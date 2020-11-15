###TARGET = uuid-generator
###
#### Use common project definitions
###include(../../common.pri)
###
###QT += core widgets
###
###LIBS += \
###    -L$${DESTDIR} \
###    -llibrepcbcommon \
###    -lmuparser \
###
#### Solaris based systems need to link against libproc
###solaris:LIBS += -lproc
###
###INCLUDEPATH += \
###    ../../libs \
###    ../../libs/type_safe/include \
###    ../../libs/type_safe/external/debug_assert \
###
###DEPENDPATH += \
###    ../../libs/librepcb/common
###
###isEmpty(UNBUNDLE) {
###    # These libraries will only be linked statically when not unbundling
###    PRE_TARGETDEPS += \
###        $${DESTDIR}/liblibrepcbcommon.a
###}

set(UUID_GENERATOR_SOURCES
    main.cpp
    mainwindow.cpp)

set(UUID_GENERATOR_HEADERS
    mainwindow.h)

set(UUID_GENERATOR_FORMS
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
###}

add_executable(uuid-generator ${UUID_GENERATOR_SOURCES} ${LIBREPCB_RESOURCES})
target_link_libraries(uuid-generator Qt::Widgets librepcbcommon)

### sexpresso muparser)
