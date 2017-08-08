#ifndef TEST_EVALUATION_H
#define TEST_EVALUATION_H

#include "gtest/gtest.h"
#include "Operations/Constant.h"
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Multiplication.h"
#include "Evaluation/ForwardEvaluator.h"

class ForwardPropagationTest : public ::testing::Test {
    protected:
        virtual void SetUp() {
            eval = new ForwardEvaluator();
            cons2 = new Constant(2.0);
            cons7 = new Constant(7.0);
            add9 = new Addition(cons2, cons7);
            cons5 = new Constant(5.0);
            mul45 = new Multiplication(add9, cons5);
            add47 = new Addition(mul45, cons2);
            sub0 = new Subtraction(add47, add47);
        }
        Dictionary<Input*, float> vars;
        ForwardEvaluator* eval;
        Constant* cons2;
        Constant* cons3;
        Constant* cons5;
        Constant* cons7;
        Addition* add9;
        Multiplication* mul45;
        Addition* add47;
        Subtraction* sub0;
};

#endif
