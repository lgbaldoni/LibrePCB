###QT += core widgets xml sql printsupport
###
###isEmpty(UNBUNDLE) {
###    CONFIG += staticlib
###} else {
###    target.path = $${PREFIX}/lib
###    INSTALLS += target
###}
###

set(LIBREPCBWORKSPACE_SOURCES
    favoriteprojectsmodel.cpp
    fileiconprovider.cpp
    library/cat/categorytreeitem.cpp
    library/cat/categorytreemodel.cpp
    library/workspacelibrarydb.cpp
    library/workspacelibraryscanner.cpp
    projecttreemodel.cpp
    recentprojectsmodel.cpp
    settings/workspacesettings.cpp
    settings/workspacesettingsdialog.cpp
    settings/workspacesettingsitem.cpp
    workspace.cpp)

set(LIBREPCBWORKSPACE_HEADERS
    favoriteprojectsmodel.h
    fileiconprovider.h
    library/cat/categorytreeitem.h
    library/cat/categorytreemodel.h
    library/workspacelibrarydb.h
    library/workspacelibraryscanner.h
    projecttreemodel.h
    recentprojectsmodel.h
    settings/workspacesettings.h
    settings/workspacesettingsdialog.h
    settings/workspacesettingsitem.h
    settings/workspacesettingsitem_genericvalue.h
    settings/workspacesettingsitem_genericvaluelist.h
    workspace.h)

set(LIBREPCBWORKSPACE_FORMS
    settings/workspacesettingsdialog.ui
    workspacechooserdialog.ui)

add_library(librepcbworkspace STATIC ${LIBREPCBWORKSPACE_SOURCES}
  ${LIBREPCB_RESOURCES})
target_include_directories(librepcbworkspace PUBLIC ${LIBRARY_INCLUDES})
target_link_libraries(librepcbworkspace Qt::Core Qt::Sql Qt::Widgets)
