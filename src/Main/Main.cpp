#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Operations/Base/Variable.h"
#include "Evaluation/Evaluator.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"
#include "Data/Initializers/Ones.h"
#include "Data/Initializers/Constant.h"
#include "Optimizers/GradientDescentOptimizer.h"

int main(int argc, char** argv) {
    auto x = std::shared_ptr<Variable>(new Variable(3.0));
    auto x_squared = x * x;
    Variables vars;
    Evaluator eval;
    std::cout << eval.ForwardEvaluate(x_squared) << std::endl;
    GradientDescentOptimizer optimizer(0.25);
    int i;
    auto grads = eval.BackwardEvaluate(x_squared, vars);
    for (i = 0; i < 10; i++) {
        grads = eval.BackwardEvaluate(x_squared, vars);
        std::cout << "grad: " << grads[x] << std::endl;
        x->Update(optimizer, grads[x]);
        std::cout << eval.ForwardEvaluate(x_squared) << std::endl;
    }

    return 0;
}

