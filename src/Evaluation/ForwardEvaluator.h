#ifndef FORWARD_EVALUATOR_H
#define FORWARD_EVALUATOR_H

#include <vector>
#include "Operations/Node.h"
#include "Operations/Differentiable.h"
#include "Operations/Input.h"
#include "Utils/Dictionary.h"

using namespace utils;

class ForwardEvaluator {
    public:
        float ForwardEvaluate(Node*, const Dictionary<Input*, float>& vars);
    protected:
        float ForwardEvaluate(Node* node, 
                              Dictionary<Node*, float>& evaluated, 
                              vector<Node*>* order);
        vector<float> EvaluatePredecessors(Node* node,
                                           Dictionary<Node*, float>& evaluated,
                                           vector<Node*>* order);
};

#endif
