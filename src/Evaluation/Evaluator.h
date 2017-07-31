#ifndef EVALUATOR_H
#define EVALUATOR_H

#include <vector>
#include <iostream>
#include "ForwardEvaluator.h"
#include "Operations/Node.h"
#include "Operations/IDifferentiable.h"
#include "Operations/Input.h"
#include "Utils/Dictionary.h"

using namespace utils;

class Evaluator{
    public:
        Dictionary<Node*, float>* BackwardEvaluate(Node*, Dictionary<Input*, float>& vars);
};

#endif
