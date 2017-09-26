#ifndef SRC_OPERATIONS_BASE_VARIABLE_H_
#define SRC_OPERATIONS_BASE_VARIABLE_H_

#include "Node.h"
#include "Differentiable.h"
#include "Parameterized.h"
#include <vector>

class Variable: public Differentiable, public Parameterized {
 public:
    Variable(float);
    Variable(const Eigen::MatrixXf&);
    Variable(const DataObject&);
    DataObject GetValue();
    DataObject Forward(const std::vector<DataObject>&) const;
    DataObject FindParameterGradients(const DataObject&) const;
    void Update(const IOptimizer&) const;
};

#endif  // SRC_OPERATIONS_BASE_VARIABLE_H_
