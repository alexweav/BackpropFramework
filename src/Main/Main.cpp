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
    Dictionary<Input*, DataObject> vars_d;
    DataObject d2(2.0);
    DataObject d3(3.0);
    vars_d[var1] = d2;
    vars_d[var2] = d3;
    cout << vars_d[var1].GetData<float>() << endl;
    /*Dictionary<Input*, float> vars;
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
    DataObject tensor1({1, 2});
    cout << +tensor1.Dim() << endl;*/

    /*DataObject* data = new DataObject(5.0);
    cout << "Is Scalar: " << (data->GetKind() == DataKind::SCALAR) << endl;
    cout << "Value: " << data->GetData<float>() << endl;
    DataObject* mData = new DataObject(m);
    cout << "Is Matrix: " << (mData->GetKind() == DataKind::MATRIX) << endl;
    cout << "Value: " << mData->GetData<MatrixXf>() << endl;*/

    return 0;
}

