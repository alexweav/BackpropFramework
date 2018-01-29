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

TEST_F(MultichannelEvaluationTest, NodeCanDependOnChannelsOnly) {
    auto add5 = Add(std::make_shared<Channel>(c2->Channels(0)), std::make_shared<Channel>(c3->Channels(0)));
    EXPECT_EQ(add5->Arity(), 2);
    auto results = evaluator.EvaluateGraph(add5);
    EXPECT_FLOAT_EQ(results[add5->Channels(0)].ToScalar(), 5.0);
}

TEST_F(MultichannelEvaluationTest, NodeCanDependOnBothNodesAndChannels) {
    auto add5 = Add(c2, std::make_shared<Channel>(c3->Channels(0)));
    EXPECT_EQ(add5->Arity(), 2);
    auto results = evaluator.EvaluateGraph(add5);
    EXPECT_FLOAT_EQ(results[add5->Channels(0)].ToScalar(), 5.0);
}

TEST_F(MultichannelEvaluationTest, NodeCanDependOnMultichannelNode) {
    auto results = evaluator.EvaluateGraph({addOne1, addOne2});
    EXPECT_FLOAT_EQ(results[addOne1->Channels(0)].ToScalar(), 6.0);
    EXPECT_FLOAT_EQ(results[addOne2->Channels(0)].ToScalar(), -1.0);
}

TEST_F(MultichannelEvaluationTest, MultichannelNodeCanBeSharedResource) {
    auto results = evaluator.EvaluateGraph(addBoth);
    EXPECT_FLOAT_EQ(results[addBoth->Channels(0)].ToScalar(), 3.0);
}
