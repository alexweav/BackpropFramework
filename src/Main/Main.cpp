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
    Dictionary<Input*, float> vars;
    vars[var1] = 2.0;
    vars[var2] = 3.0;
    cout << eval->ForwardEvaluate(mul, vars) << endl;
    auto res = eval->BackwardEvaluate(mul, vars);
    cout << "(var1 + cons) * var2" << endl;
    cout << "(2 + 5) * 3" << endl;
    cout << "var1: " << res[var1] << endl;
    cout << "var2: " << res[var2] << endl;
    cout << "cons: " << res[cons] << endl;
    cout << "add:  " << res[add] << endl;
    cout << "mul:  " << res[mul] << endl;
    cout << endl;
    MatrixXf m(2, 2);
    cout << m << endl;
    DataObject* data = new DataObject(5.0);
    cout << "Is Scalar: " << (data->GetKind() == DataKind::SCALAR) << endl;
    cout << "Value: " << data->GetData<float>() << endl;

    return 0;
}

