#include <iostream>
#include "Operations/Arithmetic.h"
#include "Operations/Base/Constant.h"
#include "Operations/Base/Input.h"
#include "Operations/Base/IDifferentiableExecutor.h"
#include "Operations/Base/Variable.h"
#include "Evaluation/Evaluator.h"
#include "Evaluation/LazyEvaluator.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"
#include "Data/Initializers/Ones.h"
#include "Data/Initializers/Constant.h"
#include "Optimizers/GradientDescentOptimizer.h"

class TestExecutor: public IExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const {
        return Scalar(100);
    }
};

class TestNode: public Node {
 public:
    TestNode(void): Node({}, true) {
        std::shared_ptr<TestExecutor> executor1(new TestExecutor());
        std::shared_ptr<TestExecutor> executor2(new TestExecutor());
        RegisterExecutor(executor1);
        RegisterExecutor(executor2);
    }

    DataObject Forward(const std::vector<DataObject>& inputs) const { }
};

int main(int argc, char** argv) {


    LazyEvaluator ev;

    auto x = std::shared_ptr<Variable>(new Variable(3.0));
    ChannelDictionary res = ev.EvaluateGraph(x);
    std::cout << res[x->Channels(0)] << std::endl;
    auto c3 = Value(3.0);
    auto c4 = Value(4.0);
    res = ev.EvaluateGraph({c3, c4});
    std::cout << res[c3->Channels(0)] << std::endl;
    std::cout << res[c4->Channels(0)] << std::endl;
    auto seven = c3 + c4;
    res = ev.EvaluateGraph(seven);
    std::cout << res[seven->Channels(0)] << std::endl;

    auto x_squared = x * x;
    Variables vars;
    Evaluator eval;
    std::cout << ev.EvaluateGraph(x_squared)[x_squared->Channels(0)] << std::endl;
    GradientDescentOptimizer optimizer(0.25);
    int i;
    auto grads = eval.BackwardEvaluate(x_squared, vars);
    for (i = 0; i < 10; i++) {
        grads = eval.BackwardEvaluate(x_squared, vars);
        std::cout << "grad: " << grads[x->Channels(0)] << std::endl;
        x->Update(optimizer, grads[x->Channels(0)]);
        std::cout << eval.ForwardEvaluate(x_squared) << std::endl;
    }
    
    std::cout << std::endl;

    auto y = Var();
    auto z = Var();
    auto inter1 = y * c3;
    auto out1 = inter1 + z;
    auto out2 = inter1 - z;
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(1.0);
    auto results = ev.EvaluateGraph({out1, out2}, vars);
    std::cout << "out1: " << results[out1->Channels(0)] << std::endl;
    std::cout << "out2: " << results[out2->Channels(0)] << std::endl;

    return 0;
}

