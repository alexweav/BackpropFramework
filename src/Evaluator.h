#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "Operations/Node.h"
#include "Operations/IDifferentiable.h"
#include "Operations/Input.h"
#include "Utils/Dictionary.h"

using namespace utils;

class Evaluator{
    public:
        float ForwardEvaluate(Node*, Dictionary<Input*, float>* vars);
    protected:
        float ForwardEvaluate(Node*&, 
                              Dictionary<Node*, float>& evaluated);
        vector<float>* EvaluatePredecessors(Node*, 
                                            Dictionary<Node*, float>& evaluated);
};

struct EvaluationVariables {
    Dictionary<Node*, float> nodeOutputs;
    vector<Node*>* evaluationOrder;
};

#endif
