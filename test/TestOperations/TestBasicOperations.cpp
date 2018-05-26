#include "TestOperations.h"

TEST(AdditionTests, ForwardAdds) {
    auto cons1 = Value(0);
    auto cons2 = Value(0);
    auto add = Add(cons1, cons2);
    DataObject d2(2.0);
    DataObject d3(3.0);
    std::vector<DataObject> inputs({d2, d3});
    EXPECT_FLOAT_EQ(add->Forward(inputs).ToScalar(), 5.0);
}

TEST(AdditionTests, ForwardMatrixAdds) {
    auto cons1 = Value(0);
    auto cons2 = Value(0);
    auto add = Add(cons1, cons2);
    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    std::vector<DataObject> inputs({Mat(m), Mat(m)});
    EXPECT_EQ(add->Forward(inputs).ToMatrix(), m + m);
}

TEST(SubtractionTests, ForwardSubtracts) {
    auto cons1 = Value(0);
    auto cons2 = Value(0);
    auto sub = Subtract(cons1, cons2);
    DataObject d5(5.0);
    DataObject d3(3.0);
    std::vector<DataObject> inputs({d5, d3});
    EXPECT_FLOAT_EQ(sub->Forward(inputs).ToScalar(), 2.0);
}

TEST(MultiplicationTests, ForwardMultiplies) {
    auto cons1 = Value(0);
    auto cons2 = Value(0);
    auto mul = Multiply(cons1, cons2);
    DataObject d3(3.0);
    DataObject d5(5.0);
    std::vector<DataObject> inputs({d3, d5});
    EXPECT_FLOAT_EQ(mul->Forward(inputs).ToScalar(), 15.0);
}

TEST(DivisionTests, ForwardDivides) {
    auto cons1 = Value(0);
    auto cons2 = Value(0);
    auto div = Divide(cons1, cons2);
    DataObject d7(7.0);
    DataObject d2(2.0);
    std::vector<DataObject> inputs({d7, d2});
    EXPECT_FLOAT_EQ(div->Forward(inputs).ToScalar(), 3.5);
}

