#ifndef SRC_OPERATIONS_VALUE_VARIABLE_H_
#define SRC_OPERATIONS_VALUE_VARIABLE_H_

#include <vector>

#include "Core/IDifferentiableExecutor.h"
#include "Core/Node.h"
#include "Core/Parameterized.h"

class VariableExecutor: public IDifferentiableExecutor {
 public:
    VariableExecutor(void);
    explicit VariableExecutor(const DataObject& value);
    DataObject GetValue(void) const;
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
    void Update(const IOptimizer&, const DataObject&);

 private:
    DataObject _value;
};

class Variable: public Parameterized {
 public:
    Variable(void);
    explicit Variable(float);
    explicit Variable(const Eigen::MatrixXf&);
    explicit Variable(const DataObject&);
    DataObject GetValue(void);
    void Update(const IOptimizer&, const DataObject&);

 private:
    VariableExecutor _executor;
};

#endif  // SRC_OPERATIONS_VALUE_VARIABLE_H_
