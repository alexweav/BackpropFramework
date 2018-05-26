#include "TestOperations.h"

TEST(ConstantTests, ForwardReturnsValue) {
    auto cons = Value(2.0);
    std::vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(cons->Execute(inputs)[cons->GetChannel()].ToScalar(), 2.0);
}

TEST(ConstantTests, ForwardMatrixReturnsValue) {
    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    auto cons = Value(m);
    std::vector<DataObject> inputs;
    EXPECT_EQ(cons->Execute(inputs)[cons->GetChannel()].ToMatrix(), m);
}

TEST(InputTests, ForwardReturnsDefaultValue) {
    auto input = Var();
    std::vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Execute(inputs)[input->GetChannel()].ToScalar(), 0.0);
}

TEST(InputTests, NewDefaultValueAppearsInForward) {
    auto input = Var();
    std::vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Execute(inputs)[input->GetChannel()].ToScalar(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(input->Execute(inputs)[input->GetChannel()].ToScalar(), 3.0);
}

TEST(InputTests, NewDefaultMatrixAppearsInForward) {
    auto input = Var();
    std::vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Execute(inputs)[input->GetChannel()].ToScalar(), 0.0);
    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    input->RegisterNewDefaultValue(m);
    EXPECT_EQ(input->Execute(inputs)[input->GetChannel()].ToMatrix(), m);
}
