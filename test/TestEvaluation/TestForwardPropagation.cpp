#include "TestEvaluation.h"

TEST_F(ForwardPropagationTest, LegacySingleNodeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(cons2)[cons2->Channels(0)].ToScalar(), 2.0);
}

TEST_F(ForwardPropagationTest, LegacyMultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(cons7)[cons7->Channels(0)].ToScalar(), 7.0);
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(add9)[add9->Channels(0)].ToScalar(), 9.0);
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(cons5)[cons5->Channels(0)].ToScalar(), 5.0);
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(mul45)[mul45->Channels(0)].ToScalar(), 45.0);
}

TEST_F(ForwardPropagationTest, LegacyMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(add47)[add47->Channels(0)].ToScalar(), 47.0);
}

TEST_F(ForwardPropagationTest, LegacyRepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(sub0)[sub0->Channels(0)].ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, LegacyVariableDefaultsToScalarZero) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, LegacyVariableRegisterNewDefaultCreatesNewDefault) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 3.0);
}

TEST_F(ForwardPropagationTest, LegacySpecifiedVariableValueOverridesDefault) {
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(input, vars)[input->Channels(0)].ToScalar(), 0.0);
    vars[input] = Scalar(5.0);
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(input, vars)[input->Channels(0)].ToScalar(), 5.0);
}

TEST_F(ForwardPropagationTest, SingleNodeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(cons2)[cons2->Channels(0)].ToScalar(), 2.0);
}

TEST_F(ForwardPropagationTest, MultiNodeTreeForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(cons7)[cons7->Channels(0)].ToScalar(), 7.0);
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(add9)[add9->Channels(0)].ToScalar(), 9.0);
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(cons5)[cons5->Channels(0)].ToScalar(), 5.0);
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(mul45)[mul45->Channels(0)].ToScalar(), 45.0);
}

TEST_F(ForwardPropagationTest, MultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(add47)[add47->Channels(0)].ToScalar(), 47.0);
}

TEST_F(ForwardPropagationTest, RepeatedEdgeMultiNodeAcyclicForwardEvaluationIsCorrect) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(sub0)[sub0->Channels(0)].ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, VariableDefaultsToScalarZero) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 0.0);
}

TEST_F(ForwardPropagationTest, VariableRegisterNewDefaultCreatesNewDefault) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(input)[input->Channels(0)].ToScalar(), 3.0);
}

TEST_F(ForwardPropagationTest, SpecifiedVariableValueOverridesDefault) {
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(input, vars)[input->Channels(0)].ToScalar(), 0.0);
    vars[input] = Scalar(5.0);
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(input, vars)[input->Channels(0)].ToScalar(), 5.0);
}
