#include <iostream>
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Multiplication.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"
#include "Evaluation/ForwardEvaluator.h"
#include "Evaluation/BackwardEvaluator.h"
#include "Utils/Dictionary.h"

using namespace std;

int main(int argc, char** argv) {
    auto var1 = new Input();
    auto var2 = new Input();
    auto cons = new Constant(5.0);
    auto add = new Addition(var1, cons);
    auto mul = new Multiplication(add, var2);

    auto eval = new ForwardEvaluator();
    Dictionary<Input*, float> vars;
    vars[var1] = 2.0;
    vars[var2] = 3.0;
    cout << eval->ForwardEvaluate(mul, vars) << endl;
    auto bval = new BackwardEvaluator();
    auto res = bval->BackwardEvaluate(mul, vars);
    cout << "(var1 + cons) * var2" << endl;
    cout << "(2 + 5) * 3" << endl;
    cout << "var1: " << res[var1] << endl;
    cout << "var2: " << res[var2] << endl;
    cout << "cons: " << res[cons] << endl;
    cout << "add:  " << res[add] << endl;
    cout << "mul:  " << res[mul] << endl;
    
    



    return 0;
}

