#include "TestEvaluation.h"

TEST_F(BackpropagationTest, TestSimpleFunction) {
    auto res = eval->BackwardEvaluate(ax3, vars);
    EXPECT_FLOAT_EQ(res[ax3].GetData<float>(), 1.0);
    EXPECT_FLOAT_EQ(res[cons5].GetData<float>(), 3.0);
    EXPECT_FLOAT_EQ(res[xp5].GetData<float>(), 3.0);
    EXPECT_FLOAT_EQ(res[x].GetData<float>(), 3.0);
    EXPECT_FLOAT_EQ(res[y].GetData<float>(), 7.0);
}

