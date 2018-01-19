#ifndef SRC_OPERATIONS_BASE_VARIABLE_H_
#define SRC_OPERATIONS_BASE_VARIABLE_H_

#include "Node.h"
#include "Differentiable.h"
#include "IDifferentiableExecutor.h"
#include "Parameterized.h"
#include <vector>

class VariableExecutor: public IDifferentiableExecutor {
 public:
    VariableExecutor(void);
    VariableExecutor(const DataObject& value);
    DataObject GetValue(void) const;
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
    void Update(const IOptimizer&, const DataObject&);

 private:
    DataObject _value;
};

class Variable: public Differentiable, public Parameterized {
 public:
    Variable(void);
    Variable(float);
    Variable(const Eigen::MatrixXf&);
    Variable(const DataObject&);
    DataObject GetValue(void);
    DataObject Forward(const std::vector<DataObject>&) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    void Update(const IOptimizer&, const DataObject&);

 private:
    VariableExecutor _executor;
};

#endif  // SRC_OPERATIONS_BASE_VARIABLE_H_
