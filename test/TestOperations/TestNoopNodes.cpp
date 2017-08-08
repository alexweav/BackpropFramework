#include "TestOperations.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"

TEST(ConstantTests, ForwardReturnsValue) {
    auto cons = new Constant(2.0);
    vector<float> inputs;
    EXPECT_EQ(cons->Forward(inputs), 2.0);
}

TEST(ConstantTests, BackwardReturnsEmptyVector) {
    auto cons = new Constant(2.0);
    vector<float> prevInputs;
    EXPECT_EQ(cons->Backward(prevInputs).size(), 0);
}

TEST(InputTests, ForwardReturnsDefaultValue) {
    auto input = new Input();
    vector<float> inputs;
    EXPECT_EQ(input->Forward(inputs), 0.0);
}

TEST(InputTests, NewDefaultValueAppearsInForward) {
    auto input = new Input();
    vector<float> inputs;
    EXPECT_EQ(input->Forward(inputs), 0.0);
    input->RegisterNewDefaultValue(3.0);
    EXPECT_EQ(input->Forward(inputs), 3.0);
}

TEST(InputTests, BackwardReturnsEmptyVector) {
    auto input = new Input();
    vector<float> prevInputs;
    EXPECT_EQ(input->Backward(prevInputs).size(), 0);
}
