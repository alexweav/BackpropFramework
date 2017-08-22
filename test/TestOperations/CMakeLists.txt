file(GLOB SRCS *.cpp)
add_executable(TestOperations ${SRCS})
target_link_libraries(TestOperations
    BackpropFramework
    libgtest
    libgmock
)

install(TARGETS TestOperations DESTINATION bin)
add_test(NAME test_operations COMMAND TestOperations)
