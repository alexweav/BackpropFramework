#include "TestOperations.h"
#include <iostream>
#include "Operations/Constant.h"
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Multiplication.h"
#include "Operations/Division.h"

TEST(AdditionTests, ForwardAdds) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    vector<float> inputs({2.0, 3.0});
    EXPECT_FLOAT_EQ(add->Forward(inputs), 5.0);
}

TEST(AdditionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    vector<float> inputs({2.0, 3.0});
    vector<float> gradsOut = add->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0), 1.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1), 1.0);
}

TEST(SubtractionTests, ForwardSubtracts) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto sub = new Subtraction(cons1, cons2);
    vector<float> inputs({5.0, 3.0});
    EXPECT_FLOAT_EQ(sub->Forward(inputs), 2.0);
}

TEST(SubtractionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto sub = new Subtraction(cons1, cons2);
    vector<float> inputs({5.0, 3.0});
    vector<float> gradsOut = sub->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0), 1.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1), -1.0);
}

TEST(MultiplicationTests, ForwardMultiplies) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto mul = new Multiplication(cons1, cons2);
    vector<float> inputs({3.0, 5.0});
    EXPECT_FLOAT_EQ(mul->Forward(inputs), 15.0);
}

TEST(MultiplicationTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto mul = new Multiplication(cons1, cons2);
    vector<float> inputs({3.0, 5.0});
    vector<float> gradsOut = mul->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0), 5.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1), 3.0);
}

TEST(DivisionTests, ForwardDivides) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto div = new Division(cons1, cons2);
    vector<float> inputs({7.0, 2.0});
    EXPECT_FLOAT_EQ(div->Forward(inputs), 3.5);
}

TEST(DivisionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto div = new Division(cons1, cons2);
    vector<float> inputs({7.0, 2.0});
    vector<float> gradsOut = div->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0), 0.5);
    EXPECT_FLOAT_EQ(gradsOut.at(1), -1.75);
}
