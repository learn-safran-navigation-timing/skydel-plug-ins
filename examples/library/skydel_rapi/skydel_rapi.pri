INCLUDEPATH *= $$PWD/sdx_api

win32:CONFIG(release, debug|release): SKYDEL_RAPI_OUT_DIR = $$PWD/../../../bin/release/
else:win32:CONFIG(debug, debug|release): SKYDEL_RAPI_OUT_DIR = $$PWD/../../../bin/debug/
else:unix: SKYDEL_RAPI_OUT_DIR = $$PWD/../../../bin/

win32: {
  PRE_TARGETDEPS *= $$SKYDEL_RAPI_OUT_DIR/skydel_rapi.lib
  DEFINES += GUID_WINDOWS=1
  SKYDEL_RAPI_DEP = -lOle32
}
else:unix: {
  PRE_TARGETDEPS *= $$SKYDEL_RAPI_OUT_DIR/libskydel_rapi.a
  DEFINES += GUID_LIBUUID=1
  SKYDEL_RAPI_DEP = -luuid
}

SKYDEL_RAPI *= -L$$SKYDEL_RAPI_OUT_DIR -lskydel_rapi $$SKYDEL_RAPI_DEP