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

TEST_F(RepeatedEvaluationTest, ForwardInGraphIncrementsCounter) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addSingle, vars).ToScalar(), 1.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}

TEST_F(RepeatedEvaluationTest, CounterNotMultipleEvaluated) {
    counterConstant->ResetCounter();
    EXPECT_FLOAT_EQ(eval->ForwardEvaluate(addDual, vars).ToScalar(), 2.0);
    EXPECT_EQ(counterConstant->GetNumEvaluations(), 1);
}
