#ifndef OPERATION_H
#define OPERATION_H

#include <vector>
#include <unordered_map>
#include "Node.h"
#include "../Utils/Dictionary.h"

class Operation: public Node {
public:
    Operation(initializer_list<Node*> inputs);
    virtual float Forward(vector<float>* inputs) = 0;
};

#endif
