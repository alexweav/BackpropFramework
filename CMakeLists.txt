cmake_minimum_required(VERSION 3.5.1)
project (BackpropFramework)

set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

file(GLOB_RECURSE BackpropFramework_SOURCES "src/*.cpp")
file(GLOB_RECURSE BackpropFramework_HEADERS "src/*.h")

set (BackpropFramework_INCLUDE_DIRS "")
foreach (_headerFile ${BackpropFramework_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND BackpropFramework_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES BackpropFramework_INCLUDE_DIRS)

include_directories(${BackpropFramework_INCLUDE_DIRS})
add_executable (BackpropFrameworkExe ${BackpropFramework_SOURCES})
