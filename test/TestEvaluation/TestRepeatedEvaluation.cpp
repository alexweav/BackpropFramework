#include "TestEvaluation.h"

TEST_F(RepeatedEvaluationTest, ResetMakesCounterEmpty) {
    counterConstant->ResetCounter();
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 0);
}

TEST_F(RepeatedEvaluationTest, ForwardIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(counterConstant, vars).ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, MultipleForwardIncrementsCounterOnce) {
    counterConstant->ResetCounter();
    auto results = eval->MultipleEvaluate({counterConstant, counterConstant, counterConstant});
    EXPECT_FLOAT_EQ(results[counterConstant->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, ForwardInGraphIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addSingle, vars).ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, DualEdgeGraphResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addDual, vars).ToScalar(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, NodeAsSharedResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    auto results = eval->MultipleEvaluate({zeroPlusCounter, counterPlusOne});
    EXPECT_FLOAT_EQ(results[zeroPlusCounter->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[counterPlusOne->Channels(0)].ToScalar(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, NodeAsBothTargetAndSharedResourceNotRepeatedlyEvaluated) {
    counterConstant->ResetCounter();
    auto results = eval->MultipleEvaluate({counterConstant, zeroPlusCounter, counterPlusOne});
    EXPECT_FLOAT_EQ(results[zeroPlusCounter->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[counterPlusOne->Channels(0)].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[counterConstant->Channels(0)].ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}
