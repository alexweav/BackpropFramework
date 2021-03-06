#ifndef SRC_OPERATIONS_VALUE_CONSTANT_H_
#define SRC_OPERATIONS_VALUE_CONSTANT_H_

#include <memory>
#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/IDifferentiableExecutor.h"
#include "Core/Node.h"

class ConstantExecutor: public IDifferentiableExecutor {
 public:
    explicit ConstantExecutor(const DataObject& value);
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
    DataObject GetValue(void) const;

 private:
    DataObject _value;
};

class Constant: public Node {
 public:
    explicit Constant(float);
    explicit Constant(const Eigen::MatrixXf&);
    explicit Constant(const DataObject&);
    DataObject GetValue(void) const;

 private:
    ConstantExecutor _executor;
};

std::shared_ptr<Constant> Value(float);
std::shared_ptr<Constant> Value(const Eigen::MatrixXf&);
std::shared_ptr<Constant> Value(const DataObject&);

#endif  // SRC_OPERATIONS_VALUE_CONSTANT_H_
