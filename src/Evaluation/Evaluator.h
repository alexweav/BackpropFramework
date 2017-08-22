#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "Operations/Differentiable.h"
#include "Operations/Input.h"
#include "Utils/Dictionary.h"

using namespace utils;

class Evaluator {
    public:
        float ForwardEvaluate(Node*, const Dictionary<Input*, float>& vars);
        Dictionary<Node*, float> BackwardEvaluate(Differentiable*, const Dictionary<Input*, float>&);
    protected:
        float ForwardEvaluate(Node*, Dictionary<Node*, float>&, vector<Node*>*);
        vector<float> EvaluatePredecessors(Node*, Dictionary<Node*, float>&, vector<Node*>*);
};

#endif
