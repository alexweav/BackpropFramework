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

    /*LazyEvaluator ev;

    std::shared_ptr<TestNode> node(new TestNode());
    std::cout << node->NumChannels() << std::endl;
    std::vector<DataObject> testInputs;
    ChannelDictionary res = ev.EvaluateGraph(node);
    std::cout << res[node->Channels(1)] << std::endl;
    std::cout << res[node->Channels(2)] << std::endl;*/

    auto x = std::shared_ptr<Variable>(new Variable(3.0));
    auto x_squared = x * x;
    Variables vars;
    Evaluator eval;
    std::cout << eval.ForwardEvaluate(x_squared) << std::endl;
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
    auto c3 = Value(3.0);
    auto c4 = Value(4.0);
    auto inter1 = y * c3;
    auto out1 = inter1 + z;
    auto out2 = inter1 - z;
    vars[y] = Scalar(2.0);
    vars[z] = Scalar(1.0);
    auto results = eval.MultipleEvaluate({out1, out2}, vars);
    std::cout << "out1: " << results[out1->Channels(0)] << std::endl;
    std::cout << "out2: " << results[out2->Channels(0)] << std::endl;

    std::cout << y->Channels().size() << std::endl;
    std::cout << ChannelHash()(y->Channels(0)) << std::endl;
    ChannelDictionary dict;
    dict[y->Channels(0)] = Scalar(1);
    std::cout << dict[y->Channels(0)] << std::endl;

    return 0;
}

