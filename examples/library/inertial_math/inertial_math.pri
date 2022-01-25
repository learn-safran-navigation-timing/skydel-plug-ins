! include (../../../external/blaze/blaze.pri) {
    error( "Couldn't find the blaze.pri file!" )
}

INCLUDEPATH *= $$PWD $$PWD/include

win32:CONFIG(release, debug|release): INERTIAL_MATH_OUT_DIR = $$PWD/../../../bin/release/
else:win32:CONFIG(debug, debug|release): INERTIAL_MATH_OUT_DIR = $$PWD/../../../bin/debug/
else:unix: INERTIAL_MATH_OUT_DIR = $$PWD/../../../bin/

win32: {
  PRE_TARGETDEPS *= $$INERTIAL_MATH_OUT_DIR/inertial_math.lib
}
else:unix: {
  PRE_TARGETDEPS *= $$INERTIAL_MATH_OUT_DIR/libinertial_math.a
}

INERTIAL_MATH = $$BLAZE_LIBS -L$$INERTIAL_MATH_OUT_DIR -linertial_math
