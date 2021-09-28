! include (../../../external/blaze/blaze.pri) {
    error( "Couldn't find the blaze.pri file!" )
}

INCLUDEPATH *= $$PWD $$PWD/include

win32: {
  PRE_TARGETDEPS *= $$PWD/../../../bin_qmake/inertial_math.lib
}
else:unix: {
  PRE_TARGETDEPS *= $$PWD/../../../bin_qmake/libinertial_math.a
}

INERTIAL_MATH = $$BLAZE_LIBS -L$$PWD/../../../bin_qmake -linertial_math
