#### Files to be installed by "make install"
###target.path = $${PREFIX}/bin
###INSTALLS += target
###
#### Solaris based systems need to link against libproc
###solaris:LIBS += -lproc
###
###
###
###isEmpty(UNBUNDLE) {
###    # These libraries will only be linked statically when not unbundling
###    PRE_TARGETDEPS += \
###        $${DESTDIR}/liblibrepcblibrarymanager.a \
###        $${DESTDIR}/liblibrepcbprojecteditor.a \
###        $${DESTDIR}/liblibrepcblibraryeditor.a \
###        $${DESTDIR}/liblibrepcbworkspace.a \
###        $${DESTDIR}/liblibrepcbproject.a \
###        $${DESTDIR}/liblibrepcblibrary.a \
###        $${DESTDIR}/liblibrepcbcommon.a \
###        $${DESTDIR}/libquazip.a \
###        $${DESTDIR}/libpolyclipping.a \
###}
###

set(LIBREPCB_CLI_SOURCES
    commandlineinterface.cpp
    main.cpp)

set(LIBREPCB_CLI_HEADERS
    commandlineinterface.h)

#### QuaZIP
###!contains(UNBUNDLE, quazip) {
###    LIBS += -lquazip -lz
###    INCLUDEPATH += ../../libs/quazip
###    DEPENDPATH += ../../libs/quazip
###}
###
#### polyclipping
###!contains(UNBUNDLE, polyclipping) {
###    LIBS += -lpolyclipping
###    DEPENDPATH += ../../libs/polyclipping
###}

add_executable(librepcb-cli ${LIBREPCB_CLI_SOURCES} ${LIBREPCB_RESOURCES})
###target_include_directories(librepcb-cli PUBLIC ${LIBREPCB_INCLUDES})
target_link_libraries(librepcb-cli
  librepcblibrarymanager
  librepcblibraryeditor
  librepcbprojecteditor
  librepcbworkspace
  librepcbproject
  librepcblibrary
  librepcbcommon
  hoedown
  muparser
  sexpresso)
