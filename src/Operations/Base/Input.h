#ifndef SRC_OPERATIONS_BASE_INPUT_H_
#define SRC_OPERATIONS_BASE_INPUT_H_

#include "Differentiable.h"
#include "IDifferentiableExecutor.h"
#include <vector>
#include <memory>

class InputExecutor: public IDifferentiableExecutor {
 public:
    InputExecutor(void);
    InputExecutor(const DataObject& defaultOutput);
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
    void RegisterNewDefaultValue(const DataObject&);
    DataObject GetDefaultOutput();

 private:
    DataObject _defaultOutput;
};

class Input: public Differentiable {
 public:
    Input(void);
    Input(const DataObject& defaultOutput);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>&, const DataObject&) const;
    void RegisterNewDefaultValue(float);
    void RegisterNewDefaultValue(const Eigen::MatrixXf&);
    void RegisterNewDefaultValue(const DataObject&);
    DataObject GetDefaultOutput(void);
 private:
    std::shared_ptr<InputExecutor> _executor;
};

typedef utils::Dictionary<Input, DataObject> Variables;
typedef std::shared_ptr<Input> InputPtr;

std::shared_ptr<Input> Var(void);

#endif  // SRC_OPERATIONS_BASE_INPUT_H_
