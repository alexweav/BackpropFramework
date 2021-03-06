#ifndef SRC_OPERATIONS_VALUE_INPUT_H_
#define SRC_OPERATIONS_VALUE_INPUT_H_

#include <memory>
#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/Node.h"
#include "Core/IDifferentiableExecutor.h"

class InputExecutor: public IDifferentiableExecutor {
 public:
    InputExecutor(void);
    explicit InputExecutor(const DataObject& defaultOutput);
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
    void RegisterNewDefaultValue(const DataObject&);
    DataObject GetDefaultOutput();

 private:
    DataObject _defaultOutput;
};

class Input: public Node {
 public:
    Input(void);
    explicit Input(const DataObject& defaultOutput);
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

#endif  // SRC_OPERATIONS_VALUE_INPUT_H_
