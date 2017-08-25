#include "TestEvaluation.h"

TEST_F(ForwardPropagationTest, SingleNodeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons2, vars).GetData<float>(), 2.0);
}

TEST_F(ForwardPropagationTest, MultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons7, vars).GetData<float>(), 7.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add9, vars).GetData<float>(), 9.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons5, vars).GetData<float>(), 5.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(mul45, vars).GetData<float>(), 45.0);
}

TEST_F(ForwardPropagationTest, MultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add47, vars).GetData<float>(), 47.0);
}

TEST_F(ForwardPropagationTest, RepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(sub0, vars).GetData<float>(), 0.0);
}
