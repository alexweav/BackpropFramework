file(GLOB SRCS *.cpp)
add_executable(TestOperations ${SRCS})
target_link_libraries(TestOperations
    libgtest
    libgmock
)

install(TARGETS TestOperations DESTINATION bin)
