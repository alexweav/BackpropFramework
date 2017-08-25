#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include "Operations/Differentiable.h"
#include "Operations/Input.h"
#include "Utils/Dictionary.h"
#include "Utils/Datatypes.h"

using namespace utils;

class Evaluator {
    public:
        float ForwardEvaluate(Node*, const Dictionary<Input*, DataObject>& vars);
        Dictionary<Node*, float> BackwardEvaluate(Differentiable*, const Dictionary<Input*, DataObject>&);
    protected:
        float ForwardEvaluate(Node*, Dictionary<Node*, DataObject>&, vector<Node*>*);
        vector<float> EvaluatePredecessors(Node*, Dictionary<Node*, DataObject>&, vector<Node*>*);
};

#endif
