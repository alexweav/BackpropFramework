#include <iostream>
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"
#include "Evaluation/ForwardEvaluator.h"
#include "Utils/Dictionary.h"

using namespace std;

int main(int argc, char** argv) {
    auto var1 = new Input();
    cout << var1->HasDifferentiableTree() << endl;
    auto var2 = new Input();
    auto cons = new Constant(5.0);
    auto add = new Addition(var1, cons);
    auto sub = new Subtraction(add, var2);

    auto eval = new ForwardEvaluator();
    Dictionary<Input*, float> vars;
    vars[var1] = 2.0;
    vars[var2] = 1.0;
    cout << eval->ForwardEvaluate(sub, vars) << endl;
    cout << sub->HasDifferentiableTree() << endl;
    



    return 0;
}

