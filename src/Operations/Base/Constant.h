#ifndef SRC_OPERATIONS_BASE_CONSTANT_H_
#define SRC_OPERATIONS_BASE_CONSTANT_H_

#include "Node.h"
#include "Differentiable.h"
#include "IDifferentiableExecutor.h"
#include <vector>

class ConstantExecutor: public IDifferentiableExecutor {
 public:
    explicit ConstantExecutor(const DataObject& value);
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
    DataObject GetValue(void) const;

 private:
    DataObject _value;
};

class Constant: public Differentiable {
 public:
    explicit Constant(float);
    explicit Constant(const Eigen::MatrixXf&);
    explicit Constant(const DataObject&);
    DataObject Forward(const std::vector<DataObject>&) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    DataObject GetValue(void) const;

 private:
    ConstantExecutor _executor;
};

std::shared_ptr<Constant> Value(float);
std::shared_ptr<Constant> Value(const Eigen::MatrixXf&);
std::shared_ptr<Constant> Value(const DataObject&);

#endif  // SRC_OPERATIONS_BASE_CONSTANT_H_
