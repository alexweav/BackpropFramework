#include "TestEvaluation.h"

TEST_F(RepeatedEvaluationTest, ResetMakesCounterEmpty) {
    counterConstant->ResetCounter();
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 0);
}

TEST_F(RepeatedEvaluationTest, ForwardIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(counterConstant, vars)[counterConstant->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, MultipleForwardIncrementsCounterOnce) {
    counterConstant->ResetCounter();
    auto results = evaluator.EvaluateGraph({counterConstant, counterConstant, counterConstant});
    EXPECT_FLOAT_EQ(results[counterConstant->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, ForwardInGraphIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(addSingle, vars)[addSingle->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, DualEdgeGraphResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(evaluator.EvaluateGraph(addDual, vars)[addDual->Channels(0)].ToScalar(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, NodeAsSharedResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    auto results = evaluator.EvaluateGraph({zeroPlusCounter, counterPlusOne});
    EXPECT_FLOAT_EQ(results[zeroPlusCounter->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[counterPlusOne->Channels(0)].ToScalar(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, NodeAsBothTargetAndSharedResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    auto results = evaluator.EvaluateGraph({counterConstant, zeroPlusCounter, counterPlusOne});
    EXPECT_FLOAT_EQ(results[zeroPlusCounter->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[counterPlusOne->Channels(0)].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[counterConstant->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}
