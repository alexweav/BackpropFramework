#ifndef SRC_OPERATIONS_VALUE_VARIABLE_H_
#define SRC_OPERATIONS_VALUE_VARIABLE_H_

#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/IDifferentiableExecutor.h"
#include "Core/Node.h"
#include "Core/Parameterized.h"

class VariableExecutor: public IDifferentiableExecutor {
 public:
    VariableExecutor(void);
    explicit VariableExecutor(const DataObject& value);
    DataObject GetValue(void) const;
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
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
