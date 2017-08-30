#include "TestOperations.h"
#include <iostream>
#include "Operations/Base/Constant.h"
#include "Operations/Arithmetic.h"

TEST(AdditionTests, ForwardAdds) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    DataObject d2(2.0);
    DataObject d3(3.0);
    vector<DataObject> inputs({d2, d3});
    EXPECT_FLOAT_EQ(add->Forward(inputs).GetData<float>(), 5.0);
}

TEST(AdditionTests, ForwardMatrixAdds) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    vector<DataObject> inputs({Mat(m), Mat(m)});
    EXPECT_EQ(add->Forward(inputs).GetData<MatrixXf>(), m + m);
}

TEST(AdditionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    DataObject d2(2.0);
    DataObject d3(3.0);
    vector<DataObject> inputs({d2, d3});
    vector<DataObject> gradsOut = add->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0).GetData<float>(), 1.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1).GetData<float>(), 1.0);
}

TEST(AdditionTests, BackwardMatrixCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto add = new Addition(cons1, cons2);
    MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    vector<DataObject> inputs({Mat(m), Mat(m)});
    vector<DataObject> gradsOut = add->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_EQ(gradsOut.at(0).GetData<MatrixXf>(), Eigen::MatrixXf::Constant(2, 2, 1.0));
    EXPECT_EQ(gradsOut.at(1).GetData<MatrixXf>(), Eigen::MatrixXf::Constant(2, 2, 1.0));
}

TEST(SubtractionTests, ForwardSubtracts) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto sub = new Subtraction(cons1, cons2);
    DataObject d5(5.0);
    DataObject d3(3.0);
    vector<DataObject> inputs({d5, d3});
    EXPECT_FLOAT_EQ(sub->Forward(inputs).GetData<float>(), 2.0);
}

TEST(SubtractionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto sub = new Subtraction(cons1, cons2);
    DataObject d5(5.0);
    DataObject d3(3.0);
    vector<DataObject> inputs({d5, d3});
    vector<DataObject> gradsOut = sub->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0).GetData<float>(), 1.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1).GetData<float>(), -1.0);
}

TEST(MultiplicationTests, ForwardMultiplies) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto mul = new Multiplication(cons1, cons2);
    DataObject d3(3.0);
    DataObject d5(5.0);
    vector<DataObject> inputs({d3, d5});
    EXPECT_FLOAT_EQ(mul->Forward(inputs).GetData<float>(), 15.0);
}

TEST(MultiplicationTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto mul = new Multiplication(cons1, cons2);
    DataObject d3(3.0);
    DataObject d5(5.0);
    vector<DataObject> inputs({d3, d5});
    vector<DataObject> gradsOut = mul->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0).GetData<float>(), 5.0);
    EXPECT_FLOAT_EQ(gradsOut.at(1).GetData<float>(), 3.0);
}

TEST(DivisionTests, ForwardDivides) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto div = new Division(cons1, cons2);
    DataObject d7(7.0);
    DataObject d2(2.0);
    vector<DataObject> inputs({d7, d2});
    EXPECT_FLOAT_EQ(div->Forward(inputs).GetData<float>(), 3.5);
}

TEST(DivisionTests, BackwardAtPointCorrect) {
    auto cons1 = new Constant(0);
    auto cons2 = new Constant(0);
    auto div = new Division(cons1, cons2);
    DataObject d7(7.0);
    DataObject d2(2.0);
    vector<DataObject> inputs({d7, d2});
    vector<DataObject> gradsOut = div->Backward(inputs);
    EXPECT_EQ(gradsOut.size(), 2);
    EXPECT_FLOAT_EQ(gradsOut.at(0).GetData<float>(), 0.5);
    EXPECT_FLOAT_EQ(gradsOut.at(1).GetData<float>(), -1.75);
}
