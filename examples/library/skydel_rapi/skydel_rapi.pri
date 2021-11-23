INCLUDEPATH *= $$PWD/sdx_api

win32: {
  PRE_TARGETDEPS *= $$PWD/../../../bin/skydel_rapi.lib
  DEFINES += GUID_WINDOWS=1
  SKYDEL_RAPI_DEP = -lOle32
}
else:unix: {
  PRE_TARGETDEPS *= $$PWD/../../../bin/libskydel_rapi.a
  DEFINES += GUID_LIBUUID=1
  SKYDEL_RAPI_DEP = -luuid
}

SKYDEL_RAPI *= -L$$PWD/../../../bin -lskydel_rapi $$SKYDEL_RAPI_DEP
