//=================================================================================================
/*!
//  \file blaze/math/expressions/SVecScalarMultExpr.h
//  \brief Header file for the sparse vector/scalar multiplication expression
//
//  Copyright (C) 2012-2020 Klaus Iglberger - All Rights Reserved
//
//  This file is part of the Blaze library. You can redistribute it and/or modify it under
//  the terms of the New (Revised) BSD License. Redistribution and use in source and binary
//  forms, with or without modification, are permitted provided that the following conditions
//  are met:
//
//  1. Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//  2. Redistributions in binary form must reproduce the above copyright notice, this list
//     of conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//  3. Neither the names of the Blaze development group nor the names of its contributors
//     may be used to endorse or promote products derived from this software without specific
//     prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
//  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
//  OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
//  SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
//  TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
//  BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
//  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
//  DAMAGE.
*/
//=================================================================================================

#ifndef _BLAZE_MATH_EXPRESSIONS_SVECSCALARMULTEXPR_H_
#define _BLAZE_MATH_EXPRESSIONS_SVECSCALARMULTEXPR_H_


//*************************************************************************************************
// Includes
//*************************************************************************************************

#include <iterator>
#include <utility>
#include <blaze/math/Aliases.h>
#include <blaze/math/constraints/RequiresEvaluation.h>
#include <blaze/math/constraints/SparseVector.h>
#include <blaze/math/constraints/TransposeFlag.h>
#include <blaze/math/constraints/Zero.h>
#include <blaze/math/Exception.h>
#include <blaze/math/expressions/Computation.h>
#include <blaze/math/expressions/Forward.h>
#include <blaze/math/expressions/SparseVector.h>
#include <blaze/math/expressions/VecScalarMultExpr.h>
#include <blaze/math/shims/Serial.h>
#include <blaze/math/sparse/ValueIndexPair.h>
#include <blaze/math/traits/MultTrait.h>
#include <blaze/math/typetraits/IsExpression.h>
#include <blaze/math/typetraits/IsInvertible.h>
#include <blaze/math/typetraits/IsTemporary.h>
#include <blaze/math/typetraits/IsZero.h>
#include <blaze/math/typetraits/RequiresEvaluation.h>
#include <blaze/math/typetraits/UnderlyingBuiltin.h>
#include <blaze/system/MacroDisable.h>
#include <blaze/util/Assert.h>
#include <blaze/util/constraints/FloatingPoint.h>
#include <blaze/util/constraints/Numeric.h>
#include <blaze/util/constraints/SameType.h>
#include <blaze/util/EnableIf.h>
#include <blaze/util/FunctionTrace.h>
#include <blaze/util/MaybeUnused.h>
#include <blaze/util/mpl/If.h>
#include <blaze/util/Types.h>
#include <blaze/util/typetraits/IsNumeric.h>
#include <blaze/util/typetraits/RemoveReference.h>


namespace blaze {

//=================================================================================================
//
//  CLASS SVECSCALARMULTEXPR
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Expression object for sparse vector-scalar multiplications.
// \ingroup sparse_vector_expression
//
// The SVecScalarMultExpr class represents the compile time expression for multiplications between
// a sparse vector and a scalar value.
*/
template< typename VT  // Type of the left-hand side sparse vector
        , typename ST  // Type of the right-hand side scalar value
        , bool TF >    // Transpose flag
class SVecScalarMultExpr
   : public VecScalarMultExpr< SparseVector< SVecScalarMultExpr<VT,ST,TF>, TF > >
   , private Computation
{
 private:
   //**Type definitions****************************************************************************
   using RT = ResultType_t<VT>;     //!< Result type of the sparse vector expression.
   using RN = ReturnType_t<VT>;     //!< Return type of the sparse vector expression.
   using CT = CompositeType_t<VT>;  //!< Composite type of the sparse vector expression.
   //**********************************************************************************************

   //**Return type evaluation**********************************************************************
   //! Compilation switch for the selection of the subscript operator return type.
   /*! The \a returnExpr compile time constant expression is a compilation switch for the
       selection of the \a ReturnType. If the vector operand returns a temporary vector
       or matrix, \a returnExpr will be set to \a false and the subscript operator will
       return it's result by value. Otherwise \a returnExpr will be set to \a true and
       the subscript operator may return it's result as an expression. */
   static constexpr bool returnExpr = !IsTemporary_v<RN>;

   //! Expression return type for the subscript operator.
   using ExprReturnType = decltype( std::declval<RN>() * std::declval<ST>() );
   //**********************************************************************************************

   //**Serial evaluation strategy******************************************************************
   //! Compilation switch for the serial evaluation strategy of the multiplication expression.
   /*! The \a useAssign compile time constant expression represents a compilation switch for
       the serial evaluation strategy of the multiplication expression. In case the sparse
       vector operand requires an intermediate evaluation, \a useAssign will be set to 1 and
       the multiplication expression will be evaluated via the \a assign function family.
       Otherwise \a useAssign will be set to 0 and the expression will be evaluated via the
       subscript operator. */
   static constexpr bool useAssign = RequiresEvaluation_v<VT>;

   /*! \cond BLAZE_INTERNAL */
   //! Helper variable template for the explicit application of the SFINAE principle.
   template< typename VT2 >
   static constexpr bool UseAssign_v = useAssign;
   /*! \endcond */
   //**********************************************************************************************

   //**Parallel evaluation strategy****************************************************************
   /*! \cond BLAZE_INTERNAL */
   //! Helper variable template for the explicit application of the SFINAE principle.
   /*! This variable template is a helper for the selection of the parallel evaluation strategy.
       In case either the target vector or the sparse vector operand is not SMP assignable and
       the vector operand requires an intermediate evaluation, the variable is set to 1 and the
       expression specific evaluation strategy is selected. Otherwise the variable is set to 0
       and the default strategy is chosen. */
   template< typename VT2 >
   static constexpr bool UseSMPAssign_v =
      ( ( !VT2::smpAssignable || !VT::smpAssignable ) && useAssign );
   /*! \endcond */
   //**********************************************************************************************

 public:
   //**Type definitions****************************************************************************
   using This          = SVecScalarMultExpr<VT,ST,TF>;  //!< Type of this SVecScalarMultExpr instance.
   using BaseType      = SparseVector<This,TF>;         //!< Base type of this SVecScalarMultExpr instance.
   using ResultType    = MultTrait_t<RT,ST>;            //!< Result type for expression template evaluations.
   using TransposeType = TransposeType_t<ResultType>;   //!< Transpose type for expression template evaluations.
   using ElementType   = ElementType_t<ResultType>;     //!< Resulting element type.

   //! Return type for expression template evaluations.
   using ReturnType = const If_t< returnExpr, ExprReturnType, ElementType >;

   //! Data type for composite expression templates.
   using CompositeType = If_t< useAssign, const ResultType, const SVecScalarMultExpr& >;

   //! Composite type of the left-hand side sparse vector expression.
   using LeftOperand = If_t< IsExpression_v<VT>, const VT, const VT& >;

   //! Composite type of the right-hand side scalar value.
   using RightOperand = ST;
   //**********************************************************************************************

   //**Compilation flags***************************************************************************
   //! Compilation switch for the expression template assignment strategy.
   static constexpr bool smpAssignable = false;
   //**********************************************************************************************

   //**ConstIterator class definition**************************************************************
   /*!\brief Iterator over the elements of the sparse vector/scalar multiplication expression.
   */
   class ConstIterator
   {
    public:
      //**Type definitions*************************************************************************
      //! Element type of the sparse vector expression.
      using Element = ValueIndexPair<ElementType>;

      //! Iterator type of the sparse vector expression.
      using IteratorType = ConstIterator_t< RemoveReference_t<LeftOperand> >;

      using IteratorCategory = std::forward_iterator_tag;  //!< The iterator category.
      using ValueType        = Element;                    //!< Type of the underlying pointers.
      using PointerType      = ValueType*;                 //!< Pointer return type.
      using ReferenceType    = ValueType&;                 //!< Reference return type.
      using DifferenceType   = ptrdiff_t;                  //!< Difference between two iterators.

      // STL iterator requirements
      using iterator_category = IteratorCategory;  //!< The iterator category.
      using value_type        = ValueType;         //!< Type of the underlying pointers.
      using pointer           = PointerType;       //!< Pointer return type.
      using reference         = ReferenceType;     //!< Reference return type.
      using difference_type   = DifferenceType;    //!< Difference between two iterators.
      //*******************************************************************************************

      //**Constructor******************************************************************************
      /*!\brief Constructor for the ConstIterator class.
      */
      inline ConstIterator( IteratorType vector, RightOperand scalar )
         : vector_( vector )  // Iterator over the elements of the left-hand side sparse vector expression
         , scalar_( scalar )  // Right-hand side scalar of the multiplication expression
      {}
      //*******************************************************************************************

      //**Prefix increment operator****************************************************************
      /*!\brief Pre-increment operator.
      //
      // \return Reference to the incremented expression iterator.
      */
      inline ConstIterator& operator++() {
         ++vector_;
         return *this;
      }
      //*******************************************************************************************

      //**Element access operator******************************************************************
      /*!\brief Direct access to the sparse vector element at the current iterator position.
      //
      // \return The current value of the sparse element.
      */
      inline const Element operator*() const {
         return Element( vector_->value() * scalar_, vector_->index() );
      }
      //*******************************************************************************************

      //**Element access operator******************************************************************
      /*!\brief Direct access to the sparse vector element at the current iterator position.
      //
      // \return Reference to the sparse vector element at the current iterator position.
      */
      inline const ConstIterator* operator->() const {
         return this;
      }
      //*******************************************************************************************

      //**Value function***************************************************************************
      /*!\brief Access to the current value of the sparse element.
      //
      // \return The current value of the sparse element.
      */
      inline ReturnType value() const {
         return vector_->value() * scalar_;
      }
      //*******************************************************************************************

      //**Index function***************************************************************************
      /*!\brief Access to the current index of the sparse element.
      //
      // \return The current index of the sparse element.
      */
      inline size_t index() const {
         return vector_->index();
      }
      //*******************************************************************************************

      //**Equality operator************************************************************************
      /*!\brief Equality comparison between two ConstIterator objects.
      //
      // \param rhs The right-hand side expression iterator.
      // \return \a true if the iterators refer to the same element, \a false if not.
      */
      inline bool operator==( const ConstIterator& rhs ) const {
         return vector_ == rhs.vector_;
      }
      //*******************************************************************************************

      //**Inequality operator**********************************************************************
      /*!\brief Inequality comparison between two ConstIterator objects.
      //
      // \param rhs The right-hand side expression iterator.
      // \return \a true if the iterators don't refer to the same element, \a false if they do.
      */
      inline bool operator!=( const ConstIterator& rhs ) const {
         return vector_ != rhs.vector_;
      }
      //*******************************************************************************************

      //**Subtraction operator*********************************************************************
      /*!\brief Calculating the number of elements between two expression iterators.
      //
      // \param rhs The right-hand side expression iterator.
      // \return The number of elements between the two expression iterators.
      */
      inline DifferenceType operator-( const ConstIterator& rhs ) const {
         return vector_ - rhs.vector_;
      }
      //*******************************************************************************************

    private:
      //**Member variables*************************************************************************
      IteratorType vector_;  //!< Iterator over the elements of the left-hand side sparse vector expression.
      RightOperand scalar_;  //!< Right-hand side scalar of the multiplication expression.
      //*******************************************************************************************
   };
   //**********************************************************************************************

   //**Constructor*********************************************************************************
   /*!\brief Constructor for the SVecScalarMultExpr class.
   //
   // \param vector The left-hand side sparse vector of the multiplication expression.
   // \param scalar The right-hand side scalar of the multiplication expression.
   */
   inline SVecScalarMultExpr( const VT& vector, ST scalar ) noexcept
      : vector_( vector )  // Left-hand side sparse vector of the multiplication expression
      , scalar_( scalar )  // Right-hand side scalar of the multiplication expression
   {}
   //**********************************************************************************************

   //**Subscript operator**************************************************************************
   /*!\brief Subscript operator for the direct access to the vector elements.
   //
   // \param index Access index. The index has to be in the range \f$[0..N-1]\f$.
   // \return The resulting value.
   */
   inline ReturnType operator[]( size_t index ) const {
      BLAZE_INTERNAL_ASSERT( index < vector_.size(), "Invalid vector access index" );
      return vector_[index] * scalar_;
   }
   //**********************************************************************************************

   //**At function*********************************************************************************
   /*!\brief Checked access to the vector elements.
   //
   // \param index Access index. The index has to be in the range \f$[0..N-1]\f$.
   // \return The resulting value.
   // \exception std::out_of_range Invalid vector access index.
   */
   inline ReturnType at( size_t index ) const {
      if( index >= vector_.size() ) {
         BLAZE_THROW_OUT_OF_RANGE( "Invalid vector access index" );
      }
      return (*this)[index];
   }
   //**********************************************************************************************

   //**Begin function******************************************************************************
   /*!\brief Returns an iterator to the first non-zero element of the sparse vector.
   //
   // \return Iterator to the first non-zero element of the sparse vector.
   */
   inline ConstIterator begin() const {
      return ConstIterator( vector_.begin(), scalar_ );
   }
   //**********************************************************************************************

   //**End function********************************************************************************
   /*!\brief Returns an iterator just past the last non-zero element of the sparse vector.
   //
   // \return Iterator just past the last non-zero element of the sparse vector.
   */
   inline ConstIterator end() const {
      return ConstIterator( vector_.end(), scalar_ );
   }
   //**********************************************************************************************

   //**Size function*******************************************************************************
   /*!\brief Returns the current size/dimension of the vector.
   //
   // \return The size of the vector.
   */
   inline size_t size() const noexcept {
      return vector_.size();
   }
   //**********************************************************************************************

   //**NonZeros function***************************************************************************
   /*!\brief Returns the number of non-zero elements in the sparse vector.
   //
   // \return The number of non-zero elements in the sparse vector.
   */
   inline size_t nonZeros() const {
      return vector_.nonZeros();
   }
   //**********************************************************************************************

   //**Find function*******************************************************************************
   /*!\brief Searches for a specific vector element.
   //
   // \param index The index of the search element.
   // \return Iterator to the element in case the index is found, end() iterator otherwise.
   */
   inline ConstIterator find( size_t index ) const {
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );
      return ConstIterator( vector_.find( index ), scalar_ );
   }
   //**********************************************************************************************

   //**LowerBound function*************************************************************************
   /*!\brief Returns an iterator to the first index not less then the given index.
   //
   // \param index The index of the search element.
   // \return Iterator to the first index not less then the given index, end() iterator otherwise.
   */
   inline ConstIterator lowerBound( size_t index ) const {
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );
      return ConstIterator( vector_.lowerBound( index ), scalar_ );
   }
   //**********************************************************************************************

   //**UpperBound function*************************************************************************
   /*!\brief Returns an iterator to the first index greater then the given index.
   //
   // \param index The index of the search element.
   // \return Iterator to the first index greater then the given index, end() iterator otherwise.
   */
   inline ConstIterator upperBound( size_t index ) const {
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( VT );
      return ConstIterator( vector_.upperBound( index ), scalar_ );
   }
   //**********************************************************************************************

   //**Left operand access*************************************************************************
   /*!\brief Returns the left-hand side sparse vector operand.
   //
   // \return The left-hand side sparse vector operand.
   */
   inline LeftOperand leftOperand() const noexcept {
      return vector_;
   }
   //**********************************************************************************************

   //**Right operand access************************************************************************
   /*!\brief Returns the right-hand side scalar operand.
   //
   // \return The right-hand side scalar operand.
   */
   inline RightOperand rightOperand() const noexcept {
      return scalar_;
   }
   //**********************************************************************************************

   //**********************************************************************************************
   /*!\brief Returns whether the expression can alias with the given address \a alias.
   //
   // \param alias The alias to be checked.
   // \return \a true in case the expression can alias, \a false otherwise.
   */
   template< typename T >
   inline bool canAlias( const T* alias ) const noexcept {
      return vector_.canAlias( alias );
   }
   //**********************************************************************************************

   //**********************************************************************************************
   /*!\brief Returns whether the expression is aliased with the given address \a alias.
   //
   // \param alias The alias to be checked.
   // \return \a true in case an alias effect is detected, \a false otherwise.
   */
   template< typename T >
   inline bool isAliased( const T* alias ) const noexcept {
      return vector_.isAliased( alias );
   }
   //**********************************************************************************************

 private:
   //**Member variables****************************************************************************
   LeftOperand  vector_;  //!< Left-hand side sparse vector of the multiplication expression.
   RightOperand scalar_;  //!< Right-hand side scalar of the multiplication expression.
   //**********************************************************************************************

   //**Assignment to dense vectors*****************************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief Assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be assigned.
   // \return void
   //
   // This function implements the performance optimized assignment of a sparse vector-scalar
   // multiplication expression to a dense vector. Due to the explicit application of the
   // SFINAE principle, this function can only be selected by the compiler in case the vector
   // operand requires an intermediate evaluation.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto assign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      assign( ~lhs, rhs.vector_ );
      (~lhs) *= rhs.scalar_;
   }
   /*! \endcond */
   //**********************************************************************************************

   //**Assignment to sparse vectors****************************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief Assignment of a sparse vector-scalar multiplication to a sparse vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side sparse vector.
   // \param rhs The right-hand side multiplication expression to be assigned.
   // \return void
   //
   // This function implements the performance optimized assignment of a sparse vector-scalar
   // multiplication expression to a sparse vector. Due to the explicit application of the
   // SFINAE principle, this function can only be selected by the compiler in case the vector
   // operand requires an intermediate evaluation.
   */
   template< typename VT2 >  // Type of the target sparse vector
   friend inline auto assign( SparseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      assign( ~lhs, rhs.vector_ );
      (~lhs) *= rhs.scalar_;
   }
   /*! \endcond */
   //**********************************************************************************************

   //**Addition assignment to dense vectors********************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief Addition assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be added.
   // \return void
   //
   // This function implements the performance optimized addition assignment of a sparse vector-
   // scalar multiplication expression to a dense vector. Due to the explicit application of the
   // SFINAE principle, this function can only be selected by the compiler in case the vector
   // operand requires an intermediate evaluation.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto addAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( serial( rhs ) );
      addAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**Addition assignment to sparse vectors*******************************************************
   // No special implementation for the addition assignment to sparse vectors.
   //**********************************************************************************************

   //**Subtraction assignment to dense vectors*****************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief Subtraction assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be subtracted.
   // \return void
   //
   // This function implements the performance optimized subtraction assignment of a sparse vector-
   // scalar multiplication expression to a dense vector. Due to the explicit application of the
   // SFINAE principle, this function can only be selected by the compiler in case the vector
   // operand requires an intermediate evaluation.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto subAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( serial( rhs ) );
      subAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**Subtraction assignment to sparse vectors****************************************************
   // No special implementation for the subtraction assignment to sparse vectors.
   //**********************************************************************************************

   //**Multiplication assignment to dense vectors**************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief Multiplication assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be multiplied.
   // \return void
   //
   // This function implements the performance optimized multiplication assignment of a sparse
   // vector-scalar multiplication expression to a dense vector. Due to the explicit application
   // of the SFINAE principle, this function can only be selected by the compiler in case the
   // vector operand requires an intermediate evaluation.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto multAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( serial( rhs ) );
      multAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**Multiplication assignment to sparse vectors*************************************************
   // No special implementation for the multiplication assignment to sparse vectors.
   //**********************************************************************************************

   //**SMP assignment to dense vectors*************************************************************
   // No special implementation for the SMP assignment to dense vectors.
   //**********************************************************************************************

   //**SMP assignment to sparse vectors************************************************************
   // No special implementation for the SMP assignment to sparse vectors.
   //**********************************************************************************************

   //**SMP addition assignment to dense vectors****************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief SMP addition assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be added.
   // \return void
   //
   // This function implements the performance optimized SMP addition assignment of a sparse
   // vector-scalar multiplication expression to a dense vector. Due to the explicit application
   // of the SFINAE principle, this function can only be selected by the compiler in case the
   // expression specific parallel evaluation strategy is selected.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto smpAddAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseSMPAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( rhs );
      smpAddAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**SMP addition assignment to sparse vectors***************************************************
   // No special implementation for the SMP addition assignment to sparse vectors.
   //**********************************************************************************************

   //**SMP subtraction assignment to dense vectors*************************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief SMP subtraction assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be subtracted.
   // \return void
   //
   // This function implements the performance optimized subtraction assignment of a sparse
   // vector-scalar multiplication expression to a dense vector. Due to the explicit application
   // of the SFINAE principle, this function can only be selected by the compiler in case the
   // expression specific parallel evaluation strategy is selected.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto smpSubAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseSMPAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( rhs );
      smpSubAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**SMP subtraction assignment to sparse vectors************************************************
   // No special implementation for the SMP subtraction assignment to sparse vectors.
   //**********************************************************************************************

   //**SMP multiplication assignment to dense vectors**********************************************
   /*! \cond BLAZE_INTERNAL */
   /*!\brief SMP multiplication assignment of a sparse vector-scalar multiplication to a dense vector.
   // \ingroup sparse_vector
   //
   // \param lhs The target left-hand side dense vector.
   // \param rhs The right-hand side multiplication expression to be multiplied.
   // \return void
   //
   // This function implements the performance optimized SMP multiplication assignment of a sparse
   // vector-scalar multiplication expression to a dense vector. Due to the explicit application
   // of the SFINAE principle, this function can only be selected by the compiler in case the
   // expression specific parallel evaluation strategy is selected.
   */
   template< typename VT2 >  // Type of the target dense vector
   friend inline auto smpMultAssign( DenseVector<VT2,TF>& lhs, const SVecScalarMultExpr& rhs )
      -> EnableIf_t< UseSMPAssign_v<VT2> >
   {
      BLAZE_FUNCTION_TRACE;

      BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( ResultType );
      BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ResultType, TF );
      BLAZE_CONSTRAINT_MUST_NOT_REQUIRE_EVALUATION( ResultType );

      BLAZE_INTERNAL_ASSERT( (~lhs).size() == rhs.size(), "Invalid vector sizes" );

      const ResultType tmp( rhs );
      smpMultAssign( ~lhs, tmp );
   }
   /*! \endcond */
   //**********************************************************************************************

   //**SMP multiplication assignment to sparse vectors*********************************************
   // No special implementation for the SMP multiplication assignment to sparse vectors.
   //**********************************************************************************************

   //**Compile time checks*************************************************************************
   /*! \cond BLAZE_INTERNAL */
   BLAZE_CONSTRAINT_MUST_BE_SPARSE_VECTOR_TYPE( VT );
   BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( VT, TF );
   BLAZE_CONSTRAINT_MUST_NOT_BE_ZERO_TYPE( VT );
   BLAZE_CONSTRAINT_MUST_BE_NUMERIC_TYPE( ST );
   BLAZE_CONSTRAINT_MUST_BE_SAME_TYPE( ST, RightOperand );
   /*! \endcond */
   //**********************************************************************************************
};
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL UNARY ARITHMETIC OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Unary minus operator for the negation of a sparse vector (\f$ \vec{a} = -\vec{b} \f$).
// \ingroup sparse_vector
//
// \param sv The sparse vector to be negated.
// \return The negation of the vector.
//
// This operator represents the negation of a sparse vector:

   \code
   blaze::CompressedVector<double> a, b;
   // ... Resizing and initialization
   b = -a;
   \endcode

// The operator returns an expression representing the negation of the given sparse vector.
*/
template< typename VT  // Type of the sparse vector
        , bool TF >    // Transpose flag
inline decltype(auto) operator-( const SparseVector<VT,TF>& sv )
{
   BLAZE_FUNCTION_TRACE;

   using ScalarType = UnderlyingBuiltin_t<VT>;
   using ReturnType = const SVecScalarMultExpr<VT,ScalarType,TF>;
   return ReturnType( ~sv, ScalarType(-1) );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL BINARY ARITHMETIC OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Backend implementation of the multiplication between a sparse vector and a scalar value
//        (\f$ \vec{a}=\vec{b}*s \f$).
// \ingroup sparse_vector
//
// \param vec The left-hand side sparse vector for the multiplication.
// \param scalar The right-hand side scalar value for the multiplication.
// \return The scaled result vector.
//
// This function implements a performance optimized treatment of the multiplication between a
// sparse vector and a scalar value.
*/
template< typename VT  // Type of the left-hand side sparse vector
        , bool TF      // Transpose flag of the left-hand side sparse vector
        , typename ST  // Type of the right-hand side scalar
        , DisableIf_t< IsZero_v<VT> >* = nullptr >
inline const SVecScalarMultExpr< VT, MultTrait_t< UnderlyingBuiltin_t<VT>, ST >, TF >
   svecscalarmult( const SparseVector<VT,TF>& vec, ST scalar )
{
   BLAZE_FUNCTION_TRACE;

   using ScalarType = MultTrait_t< UnderlyingBuiltin_t<VT>, ST >;
   using ReturnType = const SVecScalarMultExpr<VT,ScalarType,TF>;
   return ReturnType( ~vec, scalar );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Backend implementation of the multiplication between a zero vector and a scalar value
//        (\f$ \vec{a}=\vec{b}*s \f$).
// \ingroup sparse_vector
//
// \param vec The left-hand side zero vector for the multiplication.
// \param scalar The right-hand side scalar value for the multiplication.
// \return The resulting zero vector.
//
// This function implements a performance optimized treatment of the multiplication between a
// zero vector and a scalar value. It returns a zero vector.
*/
template< typename VT  // Type of the left-hand side sparse vector
        , bool TF      // Transpose flag of the left-hand side sparse vector
        , typename ST  // Type of the right-hand side scalar
        , EnableIf_t< IsZero_v<VT> >* = nullptr >
inline decltype(auto)
   svecscalarmult( const SparseVector<VT,TF>& vec, ST scalar )
{
   BLAZE_FUNCTION_TRACE;

   MAYBE_UNUSED( scalar );

   using ReturnType = const MultTrait_t< ResultType_t<VT>, ST >;

   BLAZE_CONSTRAINT_MUST_BE_VECTOR_WITH_TRANSPOSE_FLAG( ReturnType, TF );
   BLAZE_CONSTRAINT_MUST_BE_ZERO_TYPE( ReturnType );

   return ReturnType( (~vec).size() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Multiplication operator for the multiplication of a sparse vector and a scalar value
//        (\f$ \vec{a}=\vec{b}*s \f$).
// \ingroup sparse_vector
//
// \param vec The left-hand side sparse vector for the multiplication.
// \param scalar The right-hand side scalar value for the multiplication.
// \return The scaled result vector.
//
// This operator represents the multiplication between a sparse vector and a scalar value:

   \code
   blaze::CompressedVector<double> a, b;
   // ... Resizing and initialization
   b = a * 1.25;
   \endcode

// The operator returns a sparse vector of the higher-order element type of the involved data
// types \a VT::ElementType and \a ST. Note that this operator only works for scalar values
// of built-in data type.
*/
template< typename VT  // Type of the left-hand side sparse vector
        , typename ST  // Type of the right-hand side scalar
        , bool TF      // Transpose flag
        , EnableIf_t< IsNumeric_v<ST> >* = nullptr >
inline decltype(auto) operator*( const SparseVector<VT,TF>& vec, ST scalar )
{
   BLAZE_FUNCTION_TRACE;

   return svecscalarmult( ~vec, scalar );
}
//*************************************************************************************************


//*************************************************************************************************
/*!\brief Multiplication operator for the multiplication of a scalar value and a sparse vector
//        (\f$ \vec{a}=s*\vec{b} \f$).
// \ingroup sparse_vector
//
// \param scalar The left-hand side scalar value for the multiplication.
// \param vec The right-hand side sparse vector for the multiplication.
// \return The scaled result vector.
//
// This operator represents the multiplication between a a scalar value and sparse vector:

   \code
   blaze::CompressedVector<double> a, b;
   // ... Resizing and initialization
   b = 1.25 * a;
   \endcode

// The operator returns a sparse vector of the higher-order element type of the involved data
// types \a ST and \a VT::ElementType. Note that this operator only works for scalar values
// of built-in data type.
*/
template< typename ST  // Type of the left-hand side scalar
        , typename VT  // Type of the right-hand side sparse vector
        , bool TF      // Transpose flag
        , EnableIf_t< IsNumeric_v<ST> >* = nullptr >
inline decltype(auto) operator*( ST scalar, const SparseVector<VT,TF>& vec )
{
   BLAZE_FUNCTION_TRACE;

   return svecscalarmult( ~vec, scalar );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL FUNCTIONS
//
//=================================================================================================

//*************************************************************************************************
/*!\brief Normalization of the sparse vector (\f$|\vec{a}|=1\f$).
//
// \param vec The given sparse vector.
// \return The normalized result vector.
//
// This function represents the normalization of a sparse vector:

   \code
   blaze::CompressedVector<double> a;
   // ... Resizing and initialization
   a = normalize( a );
   \endcode

// The function returns an expression representing the normalized sparse vector. Note that
// this function only works for floating point vectors. The attempt to use this function for
// an integral vector results in a compile time error.
*/
template< typename VT  // Type of the sparse vector
        , bool TF >    // Transpose flag
inline decltype(auto) normalize( const SparseVector<VT,TF>& vec )
{
   using ElementType = ElementType_t<VT>;

   BLAZE_CONSTRAINT_MUST_BE_FLOATING_POINT_TYPE( ElementType );

   const ElementType len ( length( ~vec ) );
   const ElementType ilen( ( len != ElementType(0) )?( ElementType(1) / len ):( 0 ) );

   using ReturnType = const SVecScalarMultExpr<VT,ElementType,TF>;
   return ReturnType( ~vec, ilen );
}
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING UNARY ARITHMETIC OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Unary minus operator for the negation of a sparse vector-scalar multiplication
//        (\f$ \vec{a} = -(\vec{b} * s) \f$).
// \ingroup sparse_vector
//
// \param sv The sparse vector-scalar multiplication to be negated.
// \return The negation of the sparse vector-scalar multiplication.
//
// This operator implements a performance optimized treatment of the negation of a sparse vector-
// scalar multiplication expression.
*/
template< typename VT  // Type of the sparse vector
        , typename ST  // Type of the scalar
        , bool TF >    // Transpose flag
inline decltype(auto) operator-( const SVecScalarMultExpr<VT,ST,TF>& sv )
{
   BLAZE_FUNCTION_TRACE;

   using ReturnType = const SVecScalarMultExpr<VT,ST,TF>;
   return ReturnType( sv.leftOperand(), -sv.rightOperand() );
}
/*! \endcond */
//*************************************************************************************************




//=================================================================================================
//
//  GLOBAL RESTRUCTURING BINARY ARITHMETIC OPERATORS
//
//=================================================================================================

//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse vector-scalar multiplication
//        expression and a scalar value (\f$ \vec{a}=(\vec{b}*s1)*s2 \f$).
// \ingroup sparse_vector
//
// \param vec The left-hand side sparse vector-scalar multiplication.
// \param scalar The right-hand side scalar value for the multiplication.
// \return The scaled result vector.
//
// This operator implements a performance optimized treatment of the multiplication of a
// sparse vector-scalar multiplication expression and a scalar value.
*/
template< typename VT   // Type of the sparse vector of the left-hand side expression
        , typename ST1  // Type of the scalar of the left-hand side expression
        , bool TF       // Transpose flag of the sparse vector
        , typename ST2  // Type of the right-hand side scalar
        , EnableIf_t< IsNumeric_v<ST2> >* = nullptr >
inline decltype(auto) operator*( const SVecScalarMultExpr<VT,ST1,TF>& vec, ST2 scalar )
{
   BLAZE_FUNCTION_TRACE;

   return vec.leftOperand() * ( vec.rightOperand() * scalar );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse vector-scalar multiplication
//        expression and a scalar value (\f$ \vec{a}=s2*(\vec{b}*s1) \f$).
// \ingroup sparse_vector
//
// \param scalar The left-hand side scalar value for the multiplication.
// \param vec The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements a performance optimized treatment of the multiplication of a
// scalar value and a sparse vector-scalar multiplication expression.
*/
template< typename ST1  // Type of the left-hand side scalar
        , typename VT   // Type of the sparse vector of the right-hand side expression
        , typename ST2  // Type of the scalar of the right-hand side expression
        , bool TF       // Transpose flag of the sparse vector
        , EnableIf_t< IsNumeric_v<ST1> >* = nullptr >
inline decltype(auto) operator*( ST1 scalar, const SVecScalarMultExpr<VT,ST2,TF>& vec )
{
   BLAZE_FUNCTION_TRACE;

   return vec.leftOperand() * ( scalar * vec.rightOperand() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Division operator for the division of a dense vector-scalar multiplication
//        expression by a scalar value (\f$ \vec{a}=(\vec{b}*s1)/s2 \f$).
// \ingroup dense_vector
//
// \param vec The left-hand side dense vector-scalar multiplication.
// \param scalar The right-hand side scalar value for the division.
// \return The scaled result vector.
//
// This operator implements a performance optimized treatment of the division of a
// dense vector-scalar multiplication expression by a scalar value.
*/
template< typename VT   // Type of the dense vector of the left-hand side expression
        , typename ST1  // Type of the scalar of the left-hand side expression
        , bool TF       // Transpose flag of the dense vector
        , typename ST2  // Type of the right-hand side scalar
        , EnableIf_t< IsNumeric_v<ST2> && ( IsInvertible_v<ST1> || IsInvertible_v<ST2> ) >* = nullptr >
inline decltype(auto) operator/( const SVecScalarMultExpr<VT,ST1,TF>& vec, ST2 scalar )
{
   BLAZE_FUNCTION_TRACE;

   return vec.leftOperand() * ( vec.rightOperand() / scalar );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse vector-scalar multiplication
//        expression and a dense vector (\f$ \vec{a}=(\vec{b}*s1)*\vec{c} \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side dense vector.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// sparse vector-scalar multiplication and a dense vector. It restructures the expression
// \f$ \vec{a}=(\vec{b}*s1)*\vec{c} \f$ to the expression \f$ \vec{a}=(\vec{b}*\vec{c})*s1 \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST     // Type of the scalar of the left-hand side expression
        , bool TF         // Transpose flag of the dense vectors
        , typename VT2 >  // Type of the right-hand side dense vector
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST,TF>& lhs, const DenseVector<VT2,TF>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * (~rhs) ) * lhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a dense vector and a sparse vector-
//        scalar multiplication expression (\f$ \vec{a}=\vec{b}*(\vec{c}*s1) \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side dense vector.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// dense vector and a sparse vector-scalar multiplication. It restructures the expression
// \f$ \vec{a}=\vec{b}*(\vec{c}*s1) \f$ to the expression \f$ \vec{a}=(\vec{b}*\vec{c})*s1 \f$.
*/
template< typename VT1   // Type of the left-hand side dense vector
        , bool TF        // Transpose flag of the dense vectors
        , typename VT2   // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const DenseVector<VT1,TF>& lhs, const SVecScalarMultExpr<VT2,ST,TF>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~lhs) * rhs.leftOperand() ) * rhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the outer product of a sparse vector-scalar multiplication
//        expression and a dense vector (\f$ A=(\vec{b}*s1)*\vec{c}^T \f$).
// \ingroup sparse_matrix
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side dense vector.
// \return The scaled result matrix.
//
// This operator implements the performance optimized treatment of the outer product of a
// sparse vector-scalar multiplication and a dense vector. It restructures the expression
// \f$ A=(\vec{b}*s1)*\vec{c}^T \f$ to the expression \f$ A=(\vec{b}*\vec{c}^T)*s1 \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST     // Type of the scalar of the left-hand side expression
        , typename VT2 >  // Type of the right-hand side dense vector
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST,false>& lhs, const DenseVector<VT2,true>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * (~rhs) ) * lhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the outer product of a dense vector and a sparse vector-
//        scalar multiplication expression (\f$ A=\vec{b}*(\vec{c}^T*s1) \f$).
// \ingroup sparse_matrix
//
// \param lhs The left-hand side dense vector.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result matrix.
//
// This operator implements the performance optimized treatment of the outer product of a
// dense vector and a sparse vector-scalar multiplication. It restructures the expression
// \f$ A=\vec{b}*(\vec{c}^T*s1) \f$ to the expression \f$ A=(\vec{b}*\vec{c}^T)*s1 \f$.
*/
template< typename VT1   // Type of the left-hand side dense vector
        , typename VT2   // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const DenseVector<VT1,false>& lhs, const SVecScalarMultExpr<VT2,ST,true>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~lhs) * rhs.leftOperand() ) * rhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse vector-scalar multiplication
//        expression and a sparse vector (\f$ \vec{a}=(\vec{b}*s1)*\vec{c} \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side sparse vector.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// sparse vector-scalar multiplication and a sparse vector. It restructures the expression
// \f$ \vec{a}=(\vec{b}*s1)*\vec{c} \f$ to the expression \f$ \vec{a}=(\vec{b}*\vec{c})*s1 \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST     // Type of the scalar of the left-hand side expression
        , bool TF         // Transpose flag of the vectors
        , typename VT2 >  // Type of the right-hand side sparse vector
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST,TF>& lhs, const SparseVector<VT2,TF>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * (~rhs) ) * lhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse vector and a sparse vector-
//        scalar multiplication expression (\f$ \vec{a}=\vec{b}*(\vec{c}*s1) \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side sparse vector.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// sparse vector and a sparse vector-scalar multiplication. It restructures the expression
// \f$ \vec{a}=\vec{b}*(\vec{c}*s1) \f$ to the expression \f$ \vec{a}=(\vec{b}*\vec{c})*s1 \f$.
*/
template< typename VT1   // Type of the left-hand side sparse vector
        , bool TF        // Transpose flag of the vectors
        , typename VT2   // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const SparseVector<VT1,TF>& lhs, const SVecScalarMultExpr<VT2,ST,TF>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~lhs) * rhs.leftOperand() ) * rhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of two sparse vector-scalar
//        multiplication expressions (\f$ \vec{a}=(\vec{b}*s1)*(\vec{c}*s2) \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of
// two sparse vector-scalar multiplication expressions. It restructures the expression
// \f$ \vec{a}=(\vec{b}*s1)*(\vec{c}*s2) \f$ to the expression \f$ \vec{a}=(\vec{b}*\vec{c})*(s1*s2) \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST1    // Type of the scalar of the left-hand side expression
        , bool TF         // Transpose flag of the sparse vectors
        , typename VT2    // Type of the sparse vector of the right-hand side expression
        , typename ST2 >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST1,TF>& lhs, const SVecScalarMultExpr<VT2,ST2,TF>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * rhs.leftOperand() ) * ( lhs.rightOperand() * rhs.rightOperand() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the outer product of a sparse vector-scalar multiplication
//        expression and a sparse vector (\f$ A=(\vec{b}*s1)*\vec{c}^T \f$).
// \ingroup sparse_matrix
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side sparse vector.
// \return The scaled result matrix.
//
// This operator implements the performance optimized treatment of the outer product of a
// sparse vector-scalar multiplication and a sparse vector. It restructures the expression
// \f$ A=(\vec{b}*s1)*\vec{c}^T \f$ to the expression \f$ A=(\vec{b}*\vec{c}^T)*s1 \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST     // Type of the scalar of the left-hand side expression
        , typename VT2 >  // Type of the right-hand side sparse vector
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST,false>& lhs, const SparseVector<VT2,true>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * (~rhs) ) * lhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the outer product of a sparse vector and a sparse vector-
//        scalar multiplication expression (\f$ A=\vec{b}*(\vec{c}^T*s1) \f$).
// \ingroup sparse_matrix
//
// \param lhs The left-hand side sparse vector.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result matrix.
//
// This operator implements the performance optimized treatment of the outer product of a
// sparse vector and a sparse vector-scalar multiplication. It restructures the expression
// \f$ A=\vec{b}*(\vec{c}^T*s1) \f$ to the expression \f$ A=(\vec{b}*\vec{c}^T)*s1 \f$.
*/
template< typename VT1   // Type of the left-hand side sparse vector
        , typename VT2   // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const SparseVector<VT1,false>& lhs, const SVecScalarMultExpr<VT2,ST,true>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~lhs) * rhs.leftOperand() ) * rhs.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the outer product of two a sparse vector-scalar
//        multiplication expressions (\f$ A=(\vec{b}*s1)*(\vec{c}^T*s2) \f$).
// \ingroup sparse_matrix
//
// \param lhs The left-hand side sparse vector-scalar multiplication.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result matrix.
//
// This operator implements the performance optimized treatment of the outer product
// of two sparse vector-scalar multiplications. It restructures the expression
// \f$ A=(\vec{b}*s1)*(\vec{c}^T*s2) \f$ to the expression \f$ A=(\vec{b}*\vec{c}^T)*(s1*s2) \f$.
*/
template< typename VT1    // Type of the sparse vector of the left-hand side expression
        , typename ST1    // Type of the scalar of the left-hand side expression
        , typename VT2    // Type of the sparse vector of the right-hand side expression
        , typename ST2 >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT1,ST1,false>& lhs, const SVecScalarMultExpr<VT2,ST2,true>& rhs )
{
   BLAZE_FUNCTION_TRACE;

   return ( lhs.leftOperand() * rhs.leftOperand() ) * ( lhs.rightOperand() * rhs.rightOperand() );
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a dense matrix and a sparse
//        vector-scalar multiplication expression (\f$ \vec{a}=B*(\vec{c}*s1) \f$).
// \ingroup dense_vector
//
// \param lhs The left-hand side dense matrix.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// dense matrix and a sparse vector-scalar multiplication. It restructures the expression
// \f$ \vec{a}=B*(\vec{c}*s1) \f$ to the expression \f$ \vec{a}=(B*\vec{c})*s1 \f$.
*/
template< typename MT    // Type of the left-hand side dense matrix
        , bool SO        // Storage order of the left-hand side dense matrix
        , typename VT    // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const DenseMatrix<MT,SO>& mat, const SVecScalarMultExpr<VT,ST,false>& vec )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~mat) * vec.leftOperand() ) * vec.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a transpose sparse vector-scalar
//        multiplication expression and a dense matrix (\f$ \vec{a}^T=(\vec{b}^T*s1)*C \f$).
// \ingroup dense_vector
//
// \param lhs The left-hand side transpose sparse vector-scalar multiplication.
// \param rhs The right-hand side dense matrix.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// transpose sparse vector-scalar multiplication and a dense matrix. It restructures the
// expression \f$ \vec{a}^T=(\vec{b}^T*s1)*C \f$ to the expression \f$ \vec{a}^T=(\vec{b}^T*C)*s1 \f$.
*/
template< typename VT  // Type of the sparse vector of the left-hand side expression
        , typename ST  // Type of the scalar of the left-hand side expression
        , typename MT  // Type of the right-hand side dense matrix
        , bool SO >    // Storage order of the right-hand side dense matrix
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT,ST,true>& vec, const DenseMatrix<MT,SO>& mat )
{
   BLAZE_FUNCTION_TRACE;

   return ( vec.leftOperand() * (~mat) ) * vec.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a sparse matrix and a sparse
//        vector-scalar multiplication expression (\f$ \vec{a}=B*(\vec{c}*s1) \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side sparse matrix.
// \param rhs The right-hand side sparse vector-scalar multiplication.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// sparse matrix and a sparse vector-scalar multiplication. It restructures the expression
// \f$ \vec{a}=B*(\vec{c}*s1) \f$ to the expression \f$ \vec{a}=(B*\vec{c})*s1 \f$.
*/
template< typename MT    // Type of the left-hand side sparse matrix
        , bool SO        // Storage order of the left-hand side sparse matrix
        , typename VT    // Type of the sparse vector of the right-hand side expression
        , typename ST >  // Type of the scalar of the right-hand side expression
inline decltype(auto)
   operator*( const SparseMatrix<MT,SO>& mat, const SVecScalarMultExpr<VT,ST,false>& vec )
{
   BLAZE_FUNCTION_TRACE;

   return ( (~mat) * vec.leftOperand() ) * vec.rightOperand();
}
/*! \endcond */
//*************************************************************************************************


//*************************************************************************************************
/*! \cond BLAZE_INTERNAL */
/*!\brief Multiplication operator for the multiplication of a transpose sparse vector-scalar
//        multiplication expression and a sparse matrix (\f$ \vec{a}^T=(\vec{b}^T*s1)*C \f$).
// \ingroup sparse_vector
//
// \param lhs The left-hand side transpose sparse vector-scalar multiplication.
// \param rhs The right-hand side sparse matrix.
// \return The scaled result vector.
//
// This operator implements the performance optimized treatment of the multiplication of a
// transpose sparse vector-scalar multiplication and a sparse matrix. It restructures the
// expression \f$ \vec{a}^T=(\vec{b}^T*s1)*C \f$ to the expression \f$ \vec{a}^T=(\vec{b}^T*C)*s1 \f$.
*/
template< typename VT  // Type of the sparse vector of the left-hand side expression
        , typename ST  // Type of the scalar of the left-hand side expression
        , typename MT  // Type of the right-hand side sparse matrix
        , bool SO >    // Storage order of the right-hand side sparse matrix
inline decltype(auto)
   operator*( const SVecScalarMultExpr<VT,ST,true>& vec, const SparseMatrix<MT,SO>& mat )
{
   BLAZE_FUNCTION_TRACE;

   return ( vec.leftOperand() * (~mat) ) * vec.rightOperand();
}
/*! \endcond */
//*************************************************************************************************

} // namespace blaze

#endif