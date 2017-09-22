cmake_minimum_required(VERSION 3.0.2)
project(BackpropFramework)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
enable_testing()

find_package(Threads REQUIRED)
include(ExternalProject)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/CMakeModules)

if(CMAKE_BUILD_TYPE STREQUAL "Coverage")
    include(CodeCoverage)
    setup_target_for_coverage(TestOperations_coverage TestOperations coverage)
    setup_target_for_coverage(TestEvaluation_coverage TestEvaluation coverage)
    setup_target_for_coverage(TestData_coverage TestData coverage)
endif()

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


set(GCC_COVERAGE_COMPILE_FLAGS "-lstdc++ -std=c++11 -g -O0 -fprofile-arcs -ftest-coverage")
set(GCC_COVERAGE_LINK_FLAGS "-lgcov --coverage")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")

file(GLOB_RECURSE BackpropFramework_SOURCES "src/*.cpp")

include_directories("src/"
                    "external/"
                    "${source_dir}/googletest/include"
                    "${source_dir}/googlemock/include")

add_subdirectory(test)
add_executable (BackpropFrameworkExe ${BackpropFramework_SOURCES})
add_library(BackpropFramework ${BackpropFramework_SOURCES})

