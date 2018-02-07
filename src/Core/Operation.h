#ifndef SRC_CORE_OPERATION_H_
#define SRC_CORE_OPERATION_H_

#include <vector>
#include <unordered_map>
#include "Node.h"
#include "Utils/Dictionary.h"

class Operation: public virtual Node {
 public:
    Operation(): Node() {}
    virtual DataObject Forward(const std::vector<DataObject>& inputs) const = 0;
};

#endif  // SRC_CORE_OPERATION_H_
