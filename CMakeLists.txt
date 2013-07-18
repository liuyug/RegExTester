
cmake_minimum_required(VERSION 2.6)

set(CMAKE_INSTALL_PREFIX $ENV{HOME})

project(RegExTestr)
aux_source_directory(src SRCS)
#add_definitions(-Wall)

# wxWidgets
find_package(wxWidgets)
if(wxWidgets_FOUND)
    include(${wxWidgets_USE_FILE})

    # link
    add_executable(RegExTester ${SRCS})
    target_link_libraries(RegExTester ${wxWidgets_LIBRARIES})
else(wxWidgets_FOUND)
    message("wxWidgets not found!")
endif(wxWidgets_FOUND)

# install
install(TARGETS RegExTester DESTINATION bin)


