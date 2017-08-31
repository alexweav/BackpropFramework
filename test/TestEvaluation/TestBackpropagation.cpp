#include "TestEvaluation.h"

TEST_F(BackpropagationTest, TestSimpleFunction) {
    auto res = eval->BackwardEvaluate(ax3, vars);
    EXPECT_FLOAT_EQ(res[ax3].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(res[cons5].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[xp5].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[x].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[y].ToScalar(), 7.0);
}

TEST_F(BackpropagationTest, TestRepeatedEdgeFunction) {
    vars[x] = Scalar(0.0);
    auto res = eval->BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x].ToScalar(), 0.0 * 2.0);
    vars[x] = Scalar(3.0);
    res = eval->BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x].ToScalar(), 3.0 * 2.0);
    vars[x] = Scalar(-6.0);
    res = eval->BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x].ToScalar(), -6.0 * 2.0);
}
