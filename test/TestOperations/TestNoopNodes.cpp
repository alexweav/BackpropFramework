#include "TestOperations.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"

using namespace std;

TEST(ConstantTests, ForwardReturnsValue) {
    auto cons = Value(2.0);
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(cons->Forward(inputs).ToScalar(), 2.0);
}

TEST(ConstantTests, ForwardMatrixReturnsValue) {
    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    auto cons = Value(m);
    vector<DataObject> inputs;
    EXPECT_EQ(cons->Forward(inputs).ToMatrix(), m);
}

TEST(ConstantTests, BackwardReturnsEmptyVector) {
    auto cons = Value(2.0);
    vector<DataObject> prevInputs;
    EXPECT_EQ(cons->Backward(prevInputs, Scalar(0)).size(), 0);
}

TEST(InputTests, ForwardReturnsDefaultValue) {
    auto input = Var();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).ToScalar(), 0.0);
}

TEST(InputTests, NewDefaultValueAppearsInForward) {
    auto input = Var();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).ToScalar(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(input->Forward(inputs).ToScalar(), 3.0);
}

TEST(InputTests, NewDefaultMatrixAppearsInForward) {
    auto input = Var();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).ToScalar(), 0.0);
    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    input->RegisterNewDefaultValue(m);
    EXPECT_EQ(input->Forward(inputs).ToMatrix(), m);
}

TEST(InputTests, BackwardReturnsEmptyVector) {
    auto input = Var();
    vector<DataObject> prevInputs;
    EXPECT_EQ(input->Backward(prevInputs, Scalar(0)).size(), 0);
}
