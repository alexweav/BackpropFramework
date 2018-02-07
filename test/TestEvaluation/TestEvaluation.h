#ifndef TEST_TESTEVALUATION_TESTEVALUATION_H_
#define TEST_TESTEVALUATION_TESTEVALUATION_H_

#include "gtest/gtest.h"
#include "Operations/Arithmetic.h"
#include "Operations/Value.h"
#include "Evaluation/LegacyEvaluator.h"
#include "Evaluation/LazyEvaluator.h"

#include "FakeForwardEvaluationCounter.h"
#include "FakeMultichannelNode.h"

class ForwardPropagationTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
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
    LegacyEvaluator eval;
    LazyEvaluator evaluator;
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

class MultipleEvaluationTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        x = Var();
        y = Var();
        z = Var();
        c2 = Value(2.0);
        c3 = Value(3.0);
        c4 = Value(4.0);
        yTimesZPlusFour = y * z + c4;
        xTimesTwoMinusThree = x * c2 - c3;
        plusFunction = xTimesTwoMinusThree + yTimesZPlusFour;
        minusFunctionPlusTwo = xTimesTwoMinusThree - yTimesZPlusFour + c2;
    }
    LegacyEvaluator eval;
    LazyEvaluator evaluator;
    Variables vars;
    InputPtr x;
    InputPtr y;
    InputPtr z;
    NodePtr c2;
    NodePtr c3;
    NodePtr c4;
    NodePtr yTimesZPlusFour;
    NodePtr xTimesTwoMinusThree;
    NodePtr plusFunction;
    NodePtr minusFunctionPlusTwo;
};

class RepeatedEvaluationTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        std::shared_ptr<FakeForwardEvaluationCounter> ptr(new FakeForwardEvaluationCounter());
        counterConstant = ptr;
        zero = Value(0.0);
        one = Value(1.0);
        addSingle = Add(counterConstant, zero);
        addDual = Add(counterConstant, counterConstant);
        zeroPlusCounter = zero + counterConstant;
        counterPlusOne = counterConstant + one;
    }
    Variables vars;
    LegacyEvaluator eval;
    LazyEvaluator evaluator;
    std::shared_ptr<FakeForwardEvaluationCounter> counterConstant;
    NodePtr zero;
    NodePtr one;
    NodePtr addSingle;
    NodePtr addDual;
    NodePtr zeroPlusCounter;
    NodePtr counterPlusOne;
};

class MultichannelEvaluationTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        c1 = Value(1.0);
        c2 = Value(2.0);
        c3 = Value(3.0);
        c4 = Value(4.0);
        addSubtract = std::shared_ptr<FakeMultichannelNode>(new FakeMultichannelNode(c2, c3, c4));
        addOne1 = Add(std::make_shared<Channel>(addSubtract->Channels(0)), c1);
        addOne2 = Add(std::make_shared<Channel>(addSubtract->Channels(1)), c1);
        addBoth = Add(std::make_shared<Channel>(addSubtract->Channels(0)), std::make_shared<Channel>(addSubtract->Channels(1)));
    }
    NodePtr c1;
    NodePtr c2;
    NodePtr c3;
    NodePtr c4;
    std::shared_ptr<FakeMultichannelNode> addSubtract;
    NodePtr addOne1;
    NodePtr addOne2;
    NodePtr addBoth;
    LazyEvaluator evaluator;
};

class BackpropagationTest: public ::testing::Test {
 protected:
    virtual void SetUp() {
        x = Var();
        y = Var();
        z = Var();
        vars[x] = Scalar(2.0);
        vars[y] = Scalar(3.0);
        cons3 = Value(3.0);
        cons4 = Value(4.0);
        cons5 = Value(5.0);
        xp5 = Add(x, cons5);
        ax3 = Multiply(xp5, y);
        x2 = Multiply(x, x);
    }
    Variables vars;
    LegacyEvaluator eval;
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

#endif  // TEST_TESTEVALUATION_TESTEVALUATION_H_
