#ifndef SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
#define SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_

#include <vector>

#include "Core/Operation.h"
#include "Core/Differentiable.h"
#include "Core/IDifferentiableExecutor.h"

class SubtractionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
};

class Subtraction: public Operation, public Differentiable {
 public:
    Subtraction(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2);
    DataObject Forward(const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    SubtractionExecutor _executor;
};

std::shared_ptr<Subtraction> Subtract(const IChannelProviderPtr&, const IChannelProviderPtr&);
std::shared_ptr<Subtraction> operator-(const IChannelProviderPtr&, const IChannelProviderPtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
