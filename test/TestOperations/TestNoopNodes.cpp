#include "TestOperations.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"

TEST(ConstantTests, ForwardReturnsValue) {
    auto cons = new Constant(2.0);
    vector<DataObject> inputs;
    EXPECT_FLOAT_EQ(cons->Forward(inputs).GetData<float>(), 2.0);
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
    input->RegisterNewDefaultValue(3.0);
    EXPECT_FLOAT_EQ(input->Forward(inputs).GetData<float>(), 3.0);
}

TEST(InputTests, BackwardReturnsEmptyVector) {
    auto input = new Input();
    vector<DataObject> prevInputs;
    EXPECT_EQ(input->Backward(prevInputs).size(), 0);
}
