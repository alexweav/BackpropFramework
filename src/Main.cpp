#include <iostream>
#include "Operations/Addition.h"
#include "Operations/Subtraction.h"
#include "Operations/Constant.h"
#include "Operations/Input.h"
#include "Evaluator.h"
#include "Utils/Dictionary.h"

using namespace std;

void func() {
    cout << "asdf" << endl;
}

template<typename... Args>
void func(int arg, Args... args) {
    cout << "before" << arg << endl;
    func(args...);
    cout << "after" << arg << endl;
}




int main(int argc, char** argv) {
    Input* var1 = new Input();
    Input* var2 = new Input();
    Constant* cons = new Constant(5.0);
    Addition* add = new Addition(var1, cons);
    Subtraction* sub = new Subtraction(add, var2);

    Evaluator* eval = new Evaluator();
    Dictionary<Input*, float>* vars = new Dictionary<Input*, float>();
    cout << eval->ForwardEvaluate(sub, vars) << endl;
    var1->RegisterNewDefaultValue(4.0);
    cout << eval->ForwardEvaluate(sub, vars) << endl;
    var2->RegisterNewDefaultValue(2.0);
    cout << eval->ForwardEvaluate(sub, vars) << endl;
    (*vars)[var1] = 13.0;
    cout << eval->ForwardEvaluate(sub, vars) << endl;
    cout << endl << endl << endl;
    

    func(1, 2, 3, 4);
    


    return 0;
}

