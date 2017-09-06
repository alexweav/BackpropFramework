#ifndef SRC_OPERATIONS_BASE_CONSTANT_H_
#define SRC_OPERATIONS_BASE_CONSTANT_H_

#include "Node.h"
#include "Differentiable.h"
#include <vector>

class Constant: public Differentiable {
 public:
    explicit Constant(float);
    explicit Constant(const Eigen::MatrixXf&);
    explicit Constant(const DataObject&);
    DataObject Forward(const std::vector<DataObject>&) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    DataObject getValue();

 private:
    DataObject _value;
};

std::shared_ptr<Constant> Value(float);
std::shared_ptr<Constant> Value(const Eigen::MatrixXf&);
std::shared_ptr<Constant> Value(const DataObject&);

#endif  // SRC_OPERATIONS_BASE_CONSTANT_H_
