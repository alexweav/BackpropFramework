#ifndef SRC_OPERATIONS_BASE_VARIABLE_H_
#define SRC_OPERATIONS_BASE_VARIABLE_H_

#include "Node.h"
#include "Differentiable.h"
#include "Parameterized.h"
#include <vector>

class Variable: public Differentiable, public Parameterized {
 public:
    Variable();
    Variable(float);
    Variable(const Eigen::MatrixXf&);
    Variable(const DataObject&);
    DataObject GetValue();
    DataObject Forward(const std::vector<DataObject>&) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    void Update(const IOptimizer&, const DataObject&);

 private:
    DataObject _value;
};

#endif  // SRC_OPERATIONS_BASE_VARIABLE_H_
