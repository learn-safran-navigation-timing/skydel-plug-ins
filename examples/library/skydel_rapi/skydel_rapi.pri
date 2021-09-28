INCLUDEPATH *= $$PWD/sdx_api

win32: {
  PRE_TARGETDEPS *= $$PWD/../../../bin_qmake/skydel_rapi.lib
  DEFINES += GUID_WINDOWS=1
  SKYDEL_RAPI_DEP = -lOle32
}
else:unix: {
  PRE_TARGETDEPS *= $$PWD/../../../bin_qmake/libskydel_rapi.a
  DEFINES += GUID_LIBUUID=1
  SKYDEL_RAPI_DEP = -luuid
}

SKYDEL_RAPI *= -L$$PWD/../../../bin_qmake -lskydel_rapi $$SKYDEL_RAPI_DEP
