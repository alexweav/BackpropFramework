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
        NodePtr cons2;
        NodePtr cons3;
        NodePtr cons5;
        NodePtr cons7;
        NodePtr add9;
        NodePtr mul45;
        NodePtr add47;
        NodePtr sub0;
        InputPtr input;
};

class MultipleEvaluationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            eval = new Evaluator();
            std::shared_ptr<FakeForwardEvaluationCounter> ptr(new FakeForwardEvaluationCounter());
            counterConstant = ptr;
            zero = Value(0.0);
            addSingle = Add(counterConstant, zero);
            addDual = Add(counterConstant, counterConstant);
        }
        Variables vars;
        Evaluator* eval;
        std::shared_ptr<FakeForwardEvaluationCounter> counterConstant;
        NodePtr zero;
        NodePtr addSingle;
        NodePtr addDual;
};

class BackpropagationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            x = Var();
            y = Var();
            z = Var();
            vars[x] = Scalar(2.0);
            vars[y] = Scalar(3.0);
            eval = new Evaluator();
            cons3 = Value(3.0);
            cons4 = Value(4.0);
            cons5 = Value(5.0);
            xp5 = Add(x, cons5);
            ax3 = Multiply(xp5, y);
            x2 = Multiply(x, x);
        }
        Variables vars;
        Evaluator* eval;
        InputPtr x;
        InputPtr y;
        InputPtr z;
        NodePtr cons3;
        NodePtr cons4;
        NodePtr cons5;
        NodePtr xp5;
        DifferentiablePtr ax3;
        DifferentiablePtr x2;
};

#endif
