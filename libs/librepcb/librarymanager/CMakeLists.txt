###isEmpty(UNBUNDLE) {
###    CONFIG += staticlib
###} else {
###    target.path = $${PREFIX}/lib
###    INSTALLS += target
###}
###

set(LIBREPCBLIBRARYMANAGER_SOURCES
    addlibrarywidget.cpp
    librarydownload.cpp
    libraryinfowidget.cpp
    librarylistwidgetitem.cpp
    librarymanager.cpp
    repositorylibrarylistwidgetitem.cpp)

set(LIBREPCBLIBRARYMANAGER_HEADERS
    addlibrarywidget.h
    librarydownload.h
    libraryinfowidget.h
    librarylistwidgetitem.h
    librarymanager.h
    repositorylibrarylistwidgetitem.h)

set(LIBREPCBLIBRARYMANAGER_FORMS
    addlibrarywidget.ui
    libraryinfowidget.ui
    librarylistwidgetitem.ui
    librarymanager.ui
    repositorylibrarylistwidgetitem.ui)

add_library(librepcblibrarymanager STATIC ${LIBREPCBLIBRARYMANAGER_SOURCES}
  ${LIBREPCB_RESOURCES})
target_include_directories(librepcblibrarymanager PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(librepcblibrarymanager Qt::Core Qt::Network Qt::Widgets)
