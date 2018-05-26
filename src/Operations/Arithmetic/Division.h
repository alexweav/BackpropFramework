#ifndef SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
#define SRC_OPERATIONS_ARITHMETIC_DIVISION_H_

#include <vector>

#include "Core/Operation.h"
#include "Core/IDifferentiableExecutor.h"

class DivisionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;
};

class Division: public Operation {
 public:
    Division(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2);
    std::vector<DataObject> Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const;

 private:
    DivisionExecutor _executor;
};

std::shared_ptr<Division> Divide(const IChannelProviderPtr&, const IChannelProviderPtr&);
std::shared_ptr<Division> operator/(const IChannelProviderPtr&, const IChannelProviderPtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
