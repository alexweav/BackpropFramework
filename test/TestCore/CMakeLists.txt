file(GLOB SRCS *.cpp)
add_executable(TestCore ${SRCS})
target_link_libraries(TestCore
    BackpropFramework
    libgtest
    libgmock
)

install(TARGETS TestCore DESTINATION bin)
add_test(NAME test_core COMMAND TestCore)
