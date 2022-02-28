INCLUDEPATH *= $$PWD/include

win32: {
    CONFIG(debug, debug|release) {
        BLAZE_LIBS = -L$$PWD/build/win64 -llapackd -lblasd -llibf2cd
    } else {
        BLAZE_LIBS = -L$$PWD/build/win64 -llapack -lblas -llibf2c
    }
    QMAKE_CXXFLAGS_WARN_ON += /wd 2593
}
else:linux-oe-g++: {
    BLAZE_LIBS = -Wl,-Bstatic -llapack -lblas -Wl,-Bdynamic -lgfortran
    QMAKE_CXXFLAGS *= -Wno-unknown-pragmas
}
else:unix: {
    BLAZE_LIBS = -llapack
    QMAKE_CXXFLAGS *= -Wno-unknown-pragmas
}

HEADERS += \
    $$PWD/include/blaze_math.h
