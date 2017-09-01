#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Evaluation/Evaluator.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"
#include <iostream>

int main(int argc, char** argv) {
    auto var1 = Var();
    auto var2 = Var();
    auto cons = Value(5.0);
    auto add = Add(var1, cons);
    auto mul = Multiply(add, var2);

    auto eval = new Evaluator();
    Variables vars;
    DataObject d2(2.0);
    DataObject d3(3.0);
    vars[var1] = d2;
    vars[var2] = d3;
    std::cout << eval->ForwardEvaluate(mul, vars).ToScalar() << std::endl;
    auto res = eval->BackwardEvaluate(mul, vars);
    std::cout << "(var1 + cons) * var2" << std::endl;
    std::cout << "(2 + 5) * 3" << std::endl;
    std::cout << "var1: " << res[var1].ToScalar() << std::endl;
    std::cout << "var2: " << res[var2].ToScalar() << std::endl;
    std::cout << "cons: " << res[cons].ToScalar() << std::endl;
    std::cout << "add:  " << res[add].ToScalar() << std::endl;
    std::cout << "mul:  " << res[mul].ToScalar() << std::endl;
    std::cout << std::endl;

    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    Eigen::MatrixXf m2(2, 2);
    m2 << 5, 6, 7, 8;
    auto cm1 = Value(m);
    auto cm2 = Value(m2);
    auto addm = Add(cm1, cm2);
    std::cout << eval->ForwardEvaluate(addm, vars).ToMatrix() << std::endl;

    return 0;
}

