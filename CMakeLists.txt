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

ev_setup_cmake_variables_python_wheel()
option(${PROJECT_NAME}_INSTALL_EV_CLI_IN_PYTHON_VENV "Install ev-cli in python venv instead of using system" ON)
set(${PROJECT_NAME}_PYTHON_VENV_PATH "${CMAKE_BINARY_DIR}/venv" CACHE PATH "Path to python venv")

ev_setup_python_executable(
    USE_PYTHON_VENV ${${PROJECT_NAME}_USE_PYTHON_VENV}
    PYTHON_VENV_PATH ${${PROJECT_NAME}_PYTHON_VENV_PATH}
)
setup_ev_cli()
ev_add_project()

# config
add_subdirectory(config)
