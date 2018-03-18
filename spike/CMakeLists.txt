file(GLOB SRCS *.cpp)
add_executable(Spike ${SRCS})
target_link_libraries(Spike
    BackpropFramework
)
