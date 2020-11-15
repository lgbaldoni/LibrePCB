###isEmpty(UNBUNDLE) {
###    CONFIG += staticlib
###} else {
###    target.path = $${PREFIX}/lib
###    INSTALLS += target
###}

set(EAGLEIMPORT_SOURCES
    converterdb.cpp
    deviceconverter.cpp
    devicesetconverter.cpp
    packageconverter.cpp
    symbolconverter.cpp)

set(EAGLEIMPORT_HEADERS
    converterdb.h
    deviceconverter.h
    devicesetconverter.h
    packageconverter.h
    symbolconverter.h)

add_library(librepcbeagleimport ${EAGLEIMPORT_SOURCES} ${LIBREPCB_RESOURCES})
target_include_directories(librepcbeagleimport PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(librepcbeagleimport Qt::Core Qt::Widgets parseagle)

###sexpresso
