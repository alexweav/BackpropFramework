CXX := gcc
CXXFLAGS := -lstdc++ -std=c++11
BUILD_DIR := ./build
SRC_DIR := ./src
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)

MKDIR_P := mkdir -p

backpropFramework: $(SRCS)
	$(CXX) $(SRCS) $(CXXFLAGS)

