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
                              Dictionary<Input*, float>& vars, 
                              Dictionary<Node*, float>& evaluated);
        vector<float>* EvaluatePredecessors(Node*, 
                                            Dictionary<Input*, float>& vars,
                                            Dictionary<Node*, float>& evaluated);
};
#endif
