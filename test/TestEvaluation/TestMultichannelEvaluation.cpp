#include "TestEvaluation.h"

TEST_F(MultichannelEvaluationTest, MultichannelNodeHasMultipleChannels) {
    EXPECT_EQ(addSubtract->NumChannels(), 2);
    EXPECT_EQ(addSubtract->Channels().size(), 2);
}

TEST_F(MultichannelEvaluationTest, MultichannelNodeEvaluatesExecutors) {
    auto results = evaluator.EvaluateGraph(addSubtract);
    EXPECT_FLOAT_EQ(results[addSubtract->Channels(0)].ToScalar(), 5.0);
    EXPECT_FLOAT_EQ(results[addSubtract->Channels(1)].ToScalar(), -2.0);
}
