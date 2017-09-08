#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Evaluation/Evaluator.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"
#include "Data/Initializers/Ones.h"

int main(int argc, char** argv) {
    auto x = Var();
    auto y = Var();
    auto z = Var();
    auto v4 = Value(4.0);
    auto v3 = Value(3.0);
    auto fn_sqrt = (x + v4) * (y - (z/v3));
    auto f = fn_sqrt * fn_sqrt;

    Variables vars;
    Evaluator eval;
    
    vars[x] = Scalar(3.0);
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(1.0);
    std::cout << "Point: " << "(" << vars[x].ToScalar() << ", " << vars[y].ToScalar() << ", " << vars[z].ToScalar() << ")" << std::endl;
    std::cout << "Value: " << eval.ForwardEvaluate(f, vars).ToScalar() << std::endl;
    auto grads = eval.BackwardEvaluate(f, vars);
    std::cout << "df/dx: " << grads[x].ToScalar() << std::endl;
    std::cout << "df/dy: " << grads[y].ToScalar() << std::endl;
    std::cout << "df/dz: " << grads[z].ToScalar() << std::endl;

    std::cout << Initializers::Ones(3, 4).ToMatrix() << std::endl;

    return 0;
}

