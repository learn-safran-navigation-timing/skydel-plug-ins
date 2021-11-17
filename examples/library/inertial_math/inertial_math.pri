! include (../../../external/blaze/blaze.pri) {
    error( "Couldn't find the blaze.pri file!" )
}

INCLUDEPATH *= $$PWD $$PWD/include

win32: {
  PRE_TARGETDEPS *= $$PWD/../../../bin/inertial_math.lib
}
else:unix: {
  PRE_TARGETDEPS *= $$PWD/../../../bin/libinertial_math.a
}

INERTIAL_MATH = $$BLAZE_LIBS -L$$PWD/../../../bin -linertial_math
