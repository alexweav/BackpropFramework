#include "TestEvaluation.h"

TEST_F(ForwardPropagationTest, SingleNodeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons2).ToScalar(), 2.0);
}

TEST_F(ForwardPropagationTest, MultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons7).ToScalar(), 7.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add9).ToScalar(), 9.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(cons5).ToScalar(), 5.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(mul45).ToScalar(), 45.0);
}

TEST_F(ForwardPropagationTest, MultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(add47).ToScalar(), 47.0);
}

TEST_F(ForwardPropagationTest, RepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(sub0).ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, VariableDefaultsToScalarZero) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(input).ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, VariableRegisterNewDefaultCreatesNewDefault) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(input).ToScalar(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(input).ToScalar(), 3.0);
}

TEST_F(ForwardPropagationTest, SpecifiedVariableValueOverridesDefault) {
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(input, vars).ToScalar(), 0.0);
    vars[input] = Scalar(5.0);
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(input, vars).ToScalar(), 5.0);
}
