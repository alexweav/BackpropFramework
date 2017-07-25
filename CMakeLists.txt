cmake_minimum_required(VERSION 3.2.2)
project (BackpropFramework)

set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

file(GLOB_RECURSE BackpropFramework_SOURCES "src/*.cpp")

add_executable (BackpropFrameworkExe ${BackpropFramework_SOURCES})
