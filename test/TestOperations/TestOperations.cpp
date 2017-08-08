#include "gtest/gtest.h"
#include "Operations/Constant.h"
#include "Evaluation/ForwardEvaluator.h"
#include "Utils/Dictionary.h"

TEST(TestTests, Test1) {
    EXPECT_EQ(1, 1);
}

TEST(ConstantTests, ForwardTest) {
    auto cons = new Constant(2.0);
    auto eval = new ForwardEvaluator();
    Dictionary<Input*, float> inputs;
    EXPECT_EQ(eval->ForwardEvaluate(cons, inputs), 2.0);
}

