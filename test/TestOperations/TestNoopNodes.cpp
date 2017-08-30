#include "TestOperations.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"

TEST(ConstantTests, ForwardReturnsValue) {
    auto cons = new Constant(2.0);
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(cons->Forward(inputs).GetData<float>(), 2.0);
}

TEST(ConstantTests, ForwardMatrixReturnsValue) {
    MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    auto cons = new Constant(m);
    vector<DataObject> inputs;
    EXPECT_EQ(cons->Forward(inputs).GetData<MatrixXf>(), m);
}

TEST(ConstantTests, BackwardReturnsEmptyVector) {
    auto cons = new Constant(2.0);
    vector<DataObject> prevInputs;
    EXPECT_EQ(cons->Backward(prevInputs).size(), 0);
}

TEST(InputTests, ForwardReturnsDefaultValue) {
    auto input = new Input();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).GetData<float>(), 0.0);
}

TEST(InputTests, NewDefaultValueAppearsInForward) {
    auto input = new Input();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).GetData<float>(), 0.0);
    input->RegisterNewDefaultValue(Scalar(3.0));
    EXPECT_FLOAT_EQ(input->Forward(inputs).GetData<float>(), 3.0);
}

TEST(InputTests, NewDefaultMatrixAppearsInForward) {
    auto input = new Input();
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(input->Forward(inputs).GetData<float>(), 0.0);
    MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    input->RegisterNewDefaultValue(m);
    EXPECT_EQ(input->Forward(inputs).GetData<MatrixXf>(), m);
}

TEST(InputTests, BackwardReturnsEmptyVector) {
    auto input = new Input();
    vector<DataObject> prevInputs;
    EXPECT_EQ(input->Backward(prevInputs).size(), 0);
}
