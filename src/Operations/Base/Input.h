#ifndef SRC_OPERATIONS_BASE_INPUT_H_
#define SRC_OPERATIONS_BASE_INPUT_H_

#include "Differentiable.h"
#include <vector>

class Input: public Differentiable {
 public:
    Input();
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    void RegisterNewDefaultValue(float);
    void RegisterNewDefaultValue(const Eigen::MatrixXf&);
    void RegisterNewDefaultValue(const DataObject&);
    DataObject GetDefaultOutput();
 private:
    DataObject _defaultOutput;
};

typedef utils::Dictionary<Input*, DataObject> Variables;

Input* Var(void);

#endif  // SRC_OPERATIONS_BASE_INPUT_H_
