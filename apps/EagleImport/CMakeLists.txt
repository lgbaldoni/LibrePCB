###QT += core widgets xml network printsupport
###
#### Note: The order of the libraries is very important for the linker!
#### Another order could end up in "undefined reference" errors!
#### Note that dependencies need to be listed *after* the dependent libs.
###LIBS += \
###    -L$${DESTDIR} \
###    -llibrepcbeagleimport \
###    -llibrepcblibrary \
###    -llibrepcbcommon \
###    -lparseagle \
###    -lmuparser \
###
#### Solaris based systems need to link against libproc
###solaris:LIBS += -lproc
###
###DEPENDPATH += \
###    ../../libs/librepcb/eagleimport \
###    ../../libs/librepcb/library \
###    ../../libs/librepcb/common \
###    ../../libs/parseagle \
###
###isEmpty(UNBUNDLE) {
###    # These libraries will only be linked statically when not unbundling
###    PRE_TARGETDEPS += \
###      $${DESTDIR}/liblibrepcbeagleimport.a \
###      $${DESTDIR}/liblibrepcblibrary.a \
###      $${DESTDIR}/liblibrepcbcommon.a \
###      $${DESTDIR}/libpolyclipping.a \
###}
###
###PRE_TARGETDEPS += \
###    $${DESTDIR}/libparseagle.a \
###

set(EAGLE_IMPORT_SOURCES
    main.cpp
    mainwindow.cpp
    polygonsimplifier.cpp)

set(EAGLE_IMPORT_HEADERS
    mainwindow.h
    polygonsimplifier.h)

set(EAGLE_IMPORT_FORMS
    mainwindow.ui)

###
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

add_executable(eagle-import ${EAGLE_IMPORT_SOURCES} ${LIBREPCB_RESOURCES})
target_link_libraries(eagle-import Qt::Core Qt::Widgets
  librepcbcommon parseagle
 librepcbeagleimport librepcblibrary polyclipping muparser)

###  parseagle polyclipping librepcbcommon librepcblibrary librepcbeagleimport)
