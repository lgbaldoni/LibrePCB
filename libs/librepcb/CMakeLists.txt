set(LIBRARY_INCLUDES
    ${CMAKE_SOURCE_DIR}/libs
    ${CMAKE_SOURCE_DIR}/libs/type_safe/include
    ${CMAKE_SOURCE_DIR}/libs/type_safe/external/debug_assert)

add_subdirectory(common)
add_subdirectory(library)
add_subdirectory(project)
add_subdirectory(workspace)
add_subdirectory(eagleimport)
add_subdirectory(libraryeditor)
add_subdirectory(projecteditor)
add_subdirectory(librarymanager)
