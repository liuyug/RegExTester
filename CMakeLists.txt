
cmake_minimum_required(VERSION 2.6)


project(RegExTestr)
aux_source_directory(src SRCS)
add_definitions(-Wall)

add_executable(regextester ${SRCS})

# wxWidgets
find_package(wxWidgets)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})

    # link
    target_link_libraries(regextester ${wxWidgets_LIBRARIES})
else(wxWidgets_FOUND)
    message("wxWidgets not found!")
endif(wxWidgets_FOUND)

# install
install(TARGETS regextester DESTINATION bin)
install(FILES ${PROJECT_SOURCE_DIR}/installer/RegExTester.desktop DESTINATION
    share/applications)
install(FILES ${PROJECT_SOURCE_DIR}/installer/regex.png DESTINATION share/pixmaps)


