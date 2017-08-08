cmake_minimum_required(VERSION 3.0.2)
project (BackpropFramework)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
enable_testing()

find_package(Threads REQUIRED)
include(ExternalProject)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/master.zip
    PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
    INSTALL_COMMAND ""
)
ExternalProject_Get_Property(gtest source_dir binary_dir)

add_library(libgtest IMPORTED STATIC GLOBAL)
add_dependencies(libgtest gtest)

set_target_properties(libgtest PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/gtest/libgtest.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)

add_library(libgmock IMPORTED STATIC GLOBAL)
add_dependencies(libgmock gtest)

set_target_properties(libgmock PROPERTIES
    "IMPORTED_LOCATION" "${binary_dir}/googlemock/libgmock.a"
    "IMPORTED_LINK_INTERFACE_LIBRARIES" "${CMAKE_THREAD_LIBS_INIT}"
)


set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

file(GLOB_RECURSE BackpropFramework_SOURCES "src/*.cpp")

include_directories("src/"
                    "${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(test)
add_executable (BackpropFrameworkExe ${BackpropFramework_SOURCES})
add_library(BackpropFramework ${BackpropFramework_SOURCES})

add_test(TestOperations test/TestOperations/TestOperations)
