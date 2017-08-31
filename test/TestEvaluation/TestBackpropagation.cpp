#include "TestEvaluation.h"

TEST_F(BackpropagationTest, TestSimpleFunction) {
    auto res = eval->BackwardEvaluate(ax3, vars);
    EXPECT_FLOAT_EQ(res[ax3].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(res[cons5].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[xp5].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[x].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[y].ToScalar(), 7.0);
}

