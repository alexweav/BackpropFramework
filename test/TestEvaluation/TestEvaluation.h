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
            cons2 = new Constant(2.0);
            cons7 = new Constant(7.0);
            add9 = new Addition(cons2, cons7);
            cons5 = new Constant(5.0);
            mul45 = new Multiplication(add9, cons5);
            add47 = new Addition(mul45, cons2);
            sub0 = new Subtraction(add47, add47);
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
};

class MultipleEvaluationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            eval = new Evaluator();
            counterConstant = new FakeForwardEvaluationCounter();
            zero = new Constant(0.0);
            addSingle = new Addition(counterConstant, zero);
            addDual = new Addition(counterConstant, counterConstant);
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
            x = new Input();
            y = new Input();
            vars[x] = Scalar(2.0);
            vars[y] = Scalar(3.0);
            eval = new Evaluator();
            cons5 = new Constant(5.0);
            xp5 = new Addition(x, cons5);
            ax3 = new Multiplication(xp5, y);
        }
        Variables vars;
        Evaluator* eval;
        Input* x;
        Input* y;
        Constant* cons5;
        Addition* xp5;
        Multiplication* ax3;
};

#endif
