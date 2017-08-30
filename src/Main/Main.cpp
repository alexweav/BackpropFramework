#include <iostream>
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Multiplication.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"
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
    cout << eval->ForwardEvaluate(mul, vars).GetData<float>() << endl;
    auto res = eval->BackwardEvaluate(mul, vars);
    cout << "(var1 + cons) * var2" << endl;
    cout << "(2 + 5) * 3" << endl;
    cout << "var1: " << res[var1].GetData<float>() << endl;
    cout << "var2: " << res[var2].GetData<float>() << endl;
    cout << "cons: " << res[cons].GetData<float>() << endl;
    cout << "add:  " << res[add].GetData<float>() << endl;
    cout << "mul:  " << res[mul].GetData<float>() << endl;
    cout << endl;

    MatrixXf m(2, 2);
    m << 1, 2, 3, 4;
    MatrixXf m2(2, 2);
    m2 << 5, 6, 7, 8;
    auto cm1 = new Constant(m);
    auto cm2 = new Constant(m2);
    auto addm = new Addition(cm1, cm2);
    cout << eval->ForwardEvaluate(addm, vars).GetData<MatrixXf>() << endl;

    return 0;
}

