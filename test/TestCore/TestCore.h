#ifndef TEST_TESTCORE_TESTCORE_H_
#define TEST_TESTCORE_TESTCORE_H_

#include "gtest/gtest.h"

#include "Operations/Arithmetic.h"
#include "Operations/Value.h"

#include "FakeNonDifferentiableConstant.h"

class DifferentiabilityTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        cons1 = Value(1.0);
        cons2 = Value(2.0);
        nonDiffCons1 = std::shared_ptr<FakeNonDifferentiableConstant>(new FakeNonDifferentiableConstant(1.0));
        addDiff = Add(cons1, cons2);
        addNonDiffComposition = Add(nonDiffCons1, cons2);
    }
    NodePtr cons1;
    NodePtr cons2;
    std::shared_ptr<FakeNonDifferentiableConstant> nonDiffCons1;
    NodePtr addDiff;
    NodePtr addNonDiffComposition;

};

#endif  // TEST_TESTCORE_TESTCORE_H_
