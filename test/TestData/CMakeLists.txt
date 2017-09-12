file(GLOB SRCS *.cpp)
add_executable(TestData ${SRCS})
target_link_libraries(TestData
    BackpropFramework
    libgtest
    libgmock
)

install(TARGETS TestData DESTINATION bin)
add_test(NAME test_data COMMAND TestData)
