### recheck if any of the third-party headers not being included are required by librepcb devel

# nothing requires the executable
###add_subdirectory(delaunay-triangulation)
add_subdirectory(hoedown)
add_subdirectory(googletest)
add_subdirectory(librepcb)
add_subdirectory(muparser)
## see again about this one
###add_subdirectory(optional)
add_subdirectory(parseagle)
add_subdirectory(sexpresso)


###
###!contains(UNBUNDLE, quazip) {
###    SUBDIRS += quazip
###    librepcb.depends += quazip
###}

# if not unbundled
add_subdirectory(quazip)

###
###!contains(UNBUNDLE, polyclipping) {
###    SUBDIRS += polyclipping
###    librepcb.depends += polyclipping
###}

add_subdirectory(polyclipping)

###
###!contains(UNBUNDLE, fontobene-qt5) {
###    SUBDIRS += fontobene-qt5
###    librepcb.depends += fontobene-qt5
###}
