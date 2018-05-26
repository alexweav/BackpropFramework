#ifndef SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
#define SRC_OPERATIONS_ARITHMETIC_ADDITION_H_

#include <vector>

#include "Core/Operation.h"
#include "Core/IDifferentiableExecutor.h"

class AdditionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;

 private:
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarAddition(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixAddition(const DataObject&, const DataObject&, const DataObject&) const;
};

class Addition: public Operation {
 public:
    Addition(const IChannelProviderPtr& input1, const IChannelProviderPtr& input2);

 private:
    AdditionExecutor _executor;
};

std::shared_ptr<Addition> Add(const IChannelProviderPtr&, const IChannelProviderPtr&);
std::shared_ptr<Addition> operator+(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2);

#endif  // SRC_OPERATIONS_ARITHMETIC_ADDITION_H_
