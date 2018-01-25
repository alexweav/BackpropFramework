#include "TestEvaluation.h"

TEST_F(BackpropagationTest, TestSimpleFunction) {
    auto res = eval.BackwardEvaluate(ax3, vars);
    EXPECT_FLOAT_EQ(res[ax3->Channels(0)].ToScalar(), 1.0);
    EXPECT_FLOAT_EQ(res[cons5->Channels(0)].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[xp5->Channels(0)].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[x->Channels(0)].ToScalar(), 3.0);
    EXPECT_FLOAT_EQ(res[y->Channels(0)].ToScalar(), 7.0);
}

TEST_F(BackpropagationTest, TestRepeatedEdgeFunction) {
    vars[x] = Scalar(0.0);
    auto res = eval.BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x->Channels(0)].ToScalar(), 0.0 * 2.0);
    vars[x] = Scalar(3.0);
    res = eval.BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x->Channels(0)].ToScalar(), 3.0 * 2.0);
    vars[x] = Scalar(-6.0);
    res = eval.BackwardEvaluate(x2, vars);
    EXPECT_FLOAT_EQ(res[x->Channels(0)].ToScalar(), -6.0 * 2.0);
}

TEST_F(BackpropagationTest, TestScalarArithmeticFunction) {
    vars[x] = Scalar(3.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(1.0);
    auto fn_sqrt = Multiply(Add(x, cons4), Subtract(y, Divide(z, cons3)));
    auto f = Multiply(fn_sqrt, fn_sqrt);
    float f_actual = ((3.0+4.0)*(2.0-(1/3.0)))*((3.0+4.0)*(2.0-(1/3.0)));
    EXPECT_FLOAT_EQ(eval.EvaluateGraph(f, vars)[f->Channels(0)].ToScalar(), f_actual);
    auto grads = eval.BackwardEvaluate(f, vars);
    float dx_actual = 2.0*(3.0+4.0)*(2.0-(1/3.0))*(2.0-(1/3.0));
    EXPECT_FLOAT_EQ(grads[x->Channels(0)].ToScalar(), dx_actual);
    float dy_actual = 2.0*49.0*(2.0 - (1/3.0));
    EXPECT_FLOAT_EQ(grads[y->Channels(0)].ToScalar(), dy_actual);
    float dz_actual = (-2/9.0)*49.0*(3.0*2.0 - 1.0);
    EXPECT_FLOAT_EQ(grads[z->Channels(0)].ToScalar(), dz_actual);
}
