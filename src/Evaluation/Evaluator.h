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
        DataObject ForwardEvaluate(Node*, const Variables& vars);
        Dictionary<Node*, DataObject> BackwardEvaluate(Differentiable*, const Variables&);
    protected:
        DataObject ForwardEvaluate(Node*, Dictionary<Node*, DataObject>&, vector<Node*>*);
        vector<DataObject> EvaluatePredecessors(Node*, Dictionary<Node*, DataObject>&, vector<Node*>*);
};

#endif
