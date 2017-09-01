#ifndef TEST_EVALUATION_H
#define TEST_EVALUATION_H

#include "gtest/gtest.h"
#include "Operations/Base/Constant.h"
#include "Operations/Arithmetic.h"
#include "Evaluation/Evaluator.h"
#include "FakeForwardEvaluationCounter.h"

class ForwardPropagationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            eval = new Evaluator();
            cons2 = Value(2.0);
            cons7 = Value(7.0);
            add9 = Add(cons2, cons7);
            cons5 = Value(5.0);
            mul45 = Multiply(add9, cons5);
            add47 = Add(mul45, cons2);
            sub0 = Subtract(add47, add47);
            input = Var();
        }
        Variables vars;
        Evaluator* eval;
        Constant* cons2;
        Constant* cons3;
        Constant* cons5;
        Constant* cons7;
        Addition* add9;
        Multiplication* mul45;
        Addition* add47;
        Subtraction* sub0;
        Input* input;
};

class MultipleEvaluationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            eval = new Evaluator();
            counterConstant = new FakeForwardEvaluationCounter();
            zero = Value(0.0);
            addSingle = Add(counterConstant, zero);
            addDual = Add(counterConstant, counterConstant);
        }
        Variables vars;
        Evaluator* eval;
        FakeForwardEvaluationCounter* counterConstant;
        Constant* zero;
        Addition* addSingle;
        Addition* addDual;
};

class BackpropagationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            x = Var();
            y = Var();
            vars[x] = Scalar(2.0);
            vars[y] = Scalar(3.0);
            eval = new Evaluator();
            cons5 = Value(5.0);
            xp5 = Add(x, cons5);
            ax3 = Multiply(xp5, y);
            x2 = Multiply(x, x);
        }
        Variables vars;
        Evaluator* eval;
        Input* x;
        Input* y;
        Constant* cons5;
        Addition* xp5;
        Multiplication* ax3;
        Multiplication* x2;
};

#endif
