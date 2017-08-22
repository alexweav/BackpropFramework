file(GLOB SRCS *.cpp)
add_executable(TestEvaluation ${SRCS})
target_link_libraries(TestEvaluation
    BackpropFramework
    libgtest
    libgmock
)

install(TARGETS TestEvaluation DESTINATION bin)
add_test(NAME test_evaluation COMMAND TestEvaluation)
