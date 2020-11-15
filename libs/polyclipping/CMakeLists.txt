###QT -= core gui widgets
###
###CONFIG -= qt app_bundle
###CONFIG += staticlib
###
#### suppress compiler warnings
###CONFIG += warn_off
###

set(POLYCLIPPING_SOURCES
    clipper.cpp)

set(POLYCLIPPING_HEADERS
    clipper.hpp)

add_library(polyclipping STATIC ${POLYCLIPPING_SOURCES})
