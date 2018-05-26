#include "TestEvaluation.h"

TEST_F(MultipleEvaluationTest, EvaluateMultipleNodesCorrectValues) {
    auto results = evaluator.EvaluateGraph({c2, c3, c4});
    EXPECT_FLOAT_EQ(results[c2->Channels(0)].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[c3->Channels(0)].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(results[c4->Channels(0)].ToScalar(), 4.0);
    std::vector<NodePtr> nodes({c2, c3, c4});
    results = evaluator.EvaluateGraph(nodes);
    EXPECT_FLOAT_EQ(results[c2->Channels(0)].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[c3->Channels(0)].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(results[c4->Channels(0)].ToScalar(), 4.0);
}

TEST_F(MultipleEvaluationTest, EvaluateMultipleInputsReturnsOverrides) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = evaluator.EvaluateGraph({x, y, z}, vars);
    EXPECT_FLOAT_EQ(results[x->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[y->Channels(0)].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[z->Channels(0)].ToScalar(), 3.0);
}

TEST_F(MultipleEvaluationTest, FunctionWithSharedComponentsReturnsCorrectOutputs) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = evaluator.EvaluateGraph({plusFunction, minusFunctionPlusTwo}, vars);
    float left = 1.0 * 2.0 - 3.0;
    float right = 2.0 * 3.0 + 4.0;
    EXPECT_FLOAT_EQ(results[plusFunction->Channels(0)].ToScalar(), left + right);
    EXPECT_FLOAT_EQ(results[minusFunctionPlusTwo->Channels(0)].ToScalar(), left - right + 2.0);
}

TEST_F(MultipleEvaluationTest, RepeatedNodeInEvaluationRequestReturnsCorrectOutputs) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = evaluator.EvaluateGraph({plusFunction, plusFunction, plusFunction, minusFunctionPlusTwo}, vars);
    float left = 1.0 * 2.0 - 3.0;
    float right = 2.0 * 3.0 + 4.0;
    EXPECT_FLOAT_EQ(results[plusFunction->Channels(0)].ToScalar(), left + right);
    EXPECT_FLOAT_EQ(results[minusFunctionPlusTwo->Channels(0)].ToScalar(), left - right + 2.0);
}
