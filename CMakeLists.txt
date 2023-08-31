cmake_minimum_required(VERSION 3.14.7)

project(everest-examples VERSION 0.1
    DESCRIPTION "EVerest example modules"
    LANGUAGES CXX C)

find_package(everest-cmake 0.1 REQUIRED
    COMPONENTS bundling
    PATHS ../everest-cmake
)

# dependencies
if (NOT DISABLE_EDM)
    set(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT TRUE)
    evc_setup_edm()
else()
    find_package(everest-core)
endif()

ev_add_project()

# config
add_subdirectory(config)
