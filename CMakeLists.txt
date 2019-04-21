cmake_minimum_required(VERSION 3.5)

# Set project name
set (PROJECT_NAME gtest)

project (${PROJECT_NAME})

#=== FINDING PACKAGES ===#

# Locate GTest package (library)
find_package(GTest REQUIRED)
include_directories( ${GTEST_INCLUDE_DIRS})

#--------------------------------
# This is for old cmake versions
set (CMAKE_CXX_STANDARD 11)
#--------------------------------

#=== SETTING VARIABLES ===#

# Compiling flags
set(GCC_COMPILE_FLAGS "-Wall -Wextra -g")
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

#Include dir
include_directories(include)

#=== Library ===

# We want to build a static library.
add_library(${PROJECT_NAME} STATIC "src/factorial.cpp")

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "make install" to apply
install(TARGETS ${PROJECT_NAME} ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib)

#=== Test target ===

# The file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES_TEST "test/*.cpp")

# Define the sources
add_executable(run_tests ${SOURCES_TEST})

# Link with the google test libraries.
target_link_libraries(run_tests PRIVATE ${GTEST_LIBRARIES} PRIVATE pthread PRIVATE ${PROJECT_NAME})
