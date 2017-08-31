#include "TestEvaluation.h"

TEST_F(ForwardPropagationTest, SingleNodeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons2, vars).ToScalar(), 2.0);
}

TEST_F(ForwardPropagationTest, MultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons7, vars).ToScalar(), 7.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add9, vars).ToScalar(), 9.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons5, vars).ToScalar(), 5.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(mul45, vars).ToScalar(), 45.0);
}

TEST_F(ForwardPropagationTest, MultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add47, vars).ToScalar(), 47.0);
}

TEST_F(ForwardPropagationTest, RepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(sub0, vars).ToScalar(), 0.0);
}
