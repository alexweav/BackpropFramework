cmake_minimum_required(VERSION 3.0.2)
project (BackpropFramework)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

file(GLOB_RECURSE BackpropFramework_SOURCES "src/*.cpp")

include_directories("src/")

add_executable (BackpropFrameworkExe ${BackpropFramework_SOURCES})
