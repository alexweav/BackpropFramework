#ifndef BACKWARD_EVALUATOR_H
#define BACKWARD_EVALUATOR_H

#include "ForwardEvaluator.h"
#include "Utils/Dictionary.h"
#include "Operations/Node.h"

class BackwardEvaluator : public ForwardEvaluator {
    public:
        Dictionary<Node*, float> BackwardEvaluate(Node* node, const Dictionary<Input*, float>& vars);
};

#endif
