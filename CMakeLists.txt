cmake_minimum_required(VERSION 3.5)
# Set project name and version
project(JJ_PROJECT VERSION 1.0.0)
configure_file(
    "${CMAKE_SOURCE_DIR}/include/version_info/version.h.in"
    "${CMAKE_SOURCE_DIR}/include/version_info/version.h"
    )

# Custom a message tag
set(MSG_TAG "[Joshtrick] ")

# Define build type
set(CMAKE_BUILD_TYPE Release)
string(TOUPPER "${CMAKE_BUILD_TYPE}" CMAKE_BUILD_TYPE)

# Add internal headers in project include
include_directories(include/)

# Output binaries and libraries in bin and lib
# of current build respectively
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 11)

# Add definitions
if("${CMAKE_BUILD_TYPE}" STREQUAL "DEBUG")
    add_definitions(-DDEBUG_TEST)
endif()

#Add external include directories
include_directories(
    /usr/local/include/
    )

#Link external libraries diectories
link_directories(
    )

#Link external libraries
link_libraries(
    )

#Add project source codes to project
file(GLOB_RECURSE SRC
    src/*.cpp
    src/*.cc
    )

#Create project library
if(NOT "${SRC}" STREQUAL "")
    #Create the library
    message("${MSG_TAG}Creating project library")
    add_library(${PROJECT_NAME} SHARED ${SRC})
elseif("${SRC}" STREQUAL "")
    message("${MSG_TAG}No internal dependencies")
endif()

#Add sub-directories of the project
add_subdirectory(tests/)
