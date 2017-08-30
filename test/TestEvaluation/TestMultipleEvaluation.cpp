#include "TestEvaluation.h"

TEST_F(MultipleEvaluationTest, ResetMakesCounterEmpty) {
    counterConstant->ResetCounter();
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 0);
}

TEST_F(MultipleEvaluationTest, ForwardIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(counterConstant, vars).GetData<float>(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(MultipleEvaluationTest, ForwardInGraphIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addSingle, vars).GetData<float>(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(MultipleEvaluationTest, CounterNotMultipleEvaluated) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addDual, vars).GetData<float>(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}