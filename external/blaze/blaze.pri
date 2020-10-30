INCLUDEPATH *= $$PWD/include

win32: {
    CONFIG(debug, debug|release) {
        BLAZE_LIBS = -L$$PWD/build/win64 -llapackd -lblasd -llibf2cd
    } else {
        BLAZE_LIBS = -L$$PWD/build/win64 -llapack -lblas -llibf2c
    }
}
else:linux-oe-g++: {
    BLAZE_LIBS = -Wl,-Bstatic -llapack -lblas -Wl,-Bdynamic -lgfortran
}
else:unix: {
    BLAZE_LIBS = -llapack
}

HEADERS += \
    $$PWD/include/blaze_math.h
