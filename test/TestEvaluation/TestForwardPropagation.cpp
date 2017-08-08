#include "TestEvaluation.h"

TEST_F(ForwardPropagationTest, SingleNodeForwardEvaluationIsCorrect) {
    EXPECT_EQ(eval->ForwardEvaluate(cons2, vars), 2.0);
}

TEST_F(ForwardPropagationTest, MultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_EQ(eval->ForwardEvaluate(cons7, vars), 7.0);
    EXPECT_EQ(eval->ForwardEvaluate(add9, vars), 2.0 + 7.0);
    EXPECT_EQ(eval->ForwardEvaluate(cons5, vars), 5.0);
    EXPECT_EQ(eval->ForwardEvaluate(mul45, vars), (2.0 + 7.0) * 5.0);
}

TEST_F(ForwardPropagationTest, MultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_EQ(eval->ForwardEvaluate(add47, vars), ((2.0 + 7.0) * 5.0) + 2.0);
}

TEST_F(ForwardPropagationTest, RepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_EQ(eval->ForwardEvaluate(sub0, vars), 0);
}
