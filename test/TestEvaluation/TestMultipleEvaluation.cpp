#include "TestEvaluation.h"

TEST_F(MultipleEvaluationTest, EvaluateMultipleNodesCorrectValues) {
    auto results = eval.MultipleEvaluate({c2, c3, c4});
    EXPECT_FLOAT_EQ(results[c2].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[c3].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(results[c4].ToScalar(), 4.0);
    std::vector<NodePtr> nodes({c2, c3, c4});
    results = eval.MultipleEvaluate(nodes);
    EXPECT_FLOAT_EQ(results[c2].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[c3].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(results[c4].ToScalar(), 4.0);
}

TEST_F(MultipleEvaluationTest, EvaluateMultipleInputsReturnsOverrides) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = eval.MultipleEvaluate({x, y, z}, vars);
    EXPECT_FLOAT_EQ(results[x].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(results[y].ToScalar(), 2.0);
    EXPECT_FLOAT_EQ(results[z].ToScalar(), 3.0);
}

TEST_F(MultipleEvaluationTest, FunctionWithSharedComponentsReturnsCorrectOutputs) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = eval.MultipleEvaluate({plusFunction, minusFunctionPlusTwo}, vars);
    float left = 1.0 * 2.0 - 3.0;
    float right = 2.0 * 3.0 + 4.0;
    EXPECT_FLOAT_EQ(results[plusFunction].ToScalar(), left + right);
    EXPECT_FLOAT_EQ(results[minusFunctionPlusTwo].ToScalar(), left - right + 2.0);
}

TEST_F(MultipleEvaluationTest, RepeatedNodeInEvaluationRequestReturnsCorrectOutputs) {
    vars[x] = Scalar(1.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(3.0);
    auto results = eval.MultipleEvaluate({plusFunction, plusFunction, plusFunction, minusFunctionPlusTwo}, vars);
    float left = 1.0 * 2.0 - 3.0;
    float right = 2.0 * 3.0 + 4.0;
    EXPECT_FLOAT_EQ(results[plusFunction].ToScalar(), left + right);
    EXPECT_FLOAT_EQ(results[minusFunctionPlusTwo].ToScalar(), left - right + 2.0);

}
