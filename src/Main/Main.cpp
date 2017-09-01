#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Evaluation/Evaluator.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

int main(int argc, char** argv) {
    auto x = Var();
    auto y = new Input();
    auto z = Var();
    //auto v4 = Value(4.0);
    //auto v3 = Value(3.0);
    //auto fn = Multiply(Add(x, v4), Subtract(y, Divide(z, v3)));
    //auto fn_squared = Multiply(fn, fn);

    Variables vars;
    Evaluator* eval = new Evaluator();
    
    vars[x] = Scalar(3.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(1.0);
    std::cout << vars[y].ToScalar() << std::endl;
    std::cout << eval->ForwardEvaluate(y, vars).ToScalar() << std::endl;
    return 0;
}

