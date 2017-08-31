#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Evaluation/Evaluator.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

using namespace std;
using namespace Eigen;

int main(int argc, char** argv) {
    auto var1 = new Input();
    auto var2 = new Input();
    auto cons = new Constant(5.0);
    auto add = new Addition(var1, cons);
    auto mul = new Multiplication(add, var2);

    auto eval = new Evaluator();
    Variables vars;
    DataObject d2(2.0);
    DataObject d3(3.0);
    vars[var1] = d2;
    vars[var2] = d3;
    cout << eval->ForwardEvaluate(mul, vars).ToScalar() << endl;
    auto res = eval->BackwardEvaluate(mul, vars);
    cout << "(var1 + cons) * var2" << endl;
    cout << "(2 + 5) * 3" << endl;
    cout << "var1: " << res[var1].ToScalar() << endl;
    cout << "var2: " << res[var2].ToScalar() << endl;
    cout << "cons: " << res[cons].ToScalar() << endl;
    cout << "add:  " << res[add].ToScalar() << endl;
    cout << "mul:  " << res[mul].ToScalar() << endl;
    cout << endl;

    Eigen::MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    Eigen::MatrixXf m2(2, 2);
    m2 << 5, 6, 7, 8;
    auto cm1 = new Constant(m);
    auto cm2 = new Constant(m2);
    auto addm = new Addition(cm1, cm2);
    cout << eval->ForwardEvaluate(addm, vars).ToMatrix() << endl;

    return 0;
}

