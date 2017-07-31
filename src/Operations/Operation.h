#ifndef OPERATION_H
#define OPERATION_H

#include <vector>
#include <unordered_map>
#include "Node.h"
#include "../Utils/Dictionary.h"

class Operation: public Node {
public:
    Operation(initializer_list<Node*> inputs, bool);
    virtual float Forward(const vector<float>& inputs) const = 0;
};

#endif
