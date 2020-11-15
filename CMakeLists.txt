###cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
#  for AUTOUIC_SEARCH_PATHS
cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

project(LibrePCB)

#### set prefix for "make install"
###isEmpty(PREFIX):PREFIX = /usr/local

# check the version
find_package(Qt5 5.2 COMPONENTS Core Gui Concurrent Network OpenGL PrintSupport
  Sql Svg Widgets Xml REQUIRED)

### make this conditional?
###QT += testlib

#### redirect qInfo to qDebug for Qt < 5.5 because qInfo was not yet available
#### https://doc.qt.io/qt-5/qtglobal.html#qInfo
###lessThan(QT_MINOR_VERSION, 5) {
###    DEFINES += qInfo=qDebug
###}
###
#### do not allow to use -Werror in release mode on Qt < 5.5 because Q_ASSERT() would lead
#### to warnings (resp. errors) if the argument of Q_ASSERT() is not used elsewhere.
####   --> see: http://code.qt.io/cgit/qt/qtbase.git/tree/dist/changes-5.5.0
###CONFIG(release, debug|release) {
###    lessThan(QT_MINOR_VERSION, 5) {
###        QMAKE_CFLAGS -= -Werror
###        QMAKE_CXXFLAGS -= -Werror
###    }
###}
###
#### In Qt 5.15, a lot of things were marked as deprecated, without providing
#### alternatives available in previous Qt versions. It would require a lot of
#### preprocessor conditionals to avoid these deprecation warnings, so let's just
#### disable them for now. We are using CI anyway to ensure LibrePCB compiles with
#### the targeted Qt versions.
###equals(QT_MAJOR_VERSION, 5) {
###    greaterThan(QT_MINOR_VERSION, 14) {
###        QMAKE_CXXFLAGS += -Wno-deprecated-declarations
###        QMAKE_CXXFLAGS_DEBUG += -Wno-deprecated-declarations
###    }

# compiler
set(CMAKE_CXX_STANDARD 11)
# ?
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# flags
set(CMAKE_C_FLAGS "-Wall -Wextra ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra ${CMAKE_CXX_FLAGS}")

# flags, colors only required for ninja
#set(CMAKE_C_FLAGS "-Wall -Wextra -fdiagnostics-color=always ${CMAKE_C_FLAGS}")
#set(CMAKE_CXX_FLAGS "-Wall -Wextra -fdiagnostics-color=always ${CMAKE_CXX_FLAGS}")

## perhaps this goes in the relevant subdir
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/Modules)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# or is it SHARE_INSTALL_PREFIX ?
if(NOT DEFINED ${CMAKE_INSTALL_DATADIR})
  set(CMAKE_INSTALL_DATADIR share)
endif()



###
#### enable pkgconfig on linux when unbundling
###!isEmpty(UNBUNDLE) {
###    unix:CONFIG += link_pkgconfig
###}
###
#### If UNBUNDLE contains "all", unbundle all dependencies
###contains(UNBUNDLE, all) {
###    UNBUNDLE = (all) quazip polyclipping fontobene-qt5
###}
###
#### QuaZIP configuration
###contains(UNBUNDLE, quazip) {
###    DEFINES += SYSTEM_QUAZIP
###} else:isEmpty(UNBUNDLE) {
###    DEFINES += QUAZIP_STATIC
###}

set(LIBREPCB_RESOURCES ${CMAKE_SOURCE_DIR}/img/images.qrc)

add_subdirectory(apps)
add_subdirectory(libs)
#add_subdirectory(tests)


###TRANSLATIONS = ./i18n/librepcb.ts

