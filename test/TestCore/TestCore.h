#ifndef TEST_TESTCORE_TESTCORE_H_
#define TEST_TESTCORE_TESTCORE_H_

#include "gtest/gtest.h"

#include "Operations/Value.h"

class DifferentiabilityTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        cons1 = Value(1.0);
        cons2 = Value(2.0);
    }
    NodePtr cons1;
    NodePtr cons2;
};

#endif  // TEST_TESTCORE_TESTCORE_H_
