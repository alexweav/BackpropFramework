#ifndef OPERATION_H
#define OPERATION_H

#include <vector>
#include <unordered_map>
#include "Node.h"
#include "Utils/Dictionary.h"

class Operation: public virtual Node {
public:
    Operation(): Node() {}
    virtual DataObject Forward(const vector<DataObject>& inputs) const = 0;
};

#endif
