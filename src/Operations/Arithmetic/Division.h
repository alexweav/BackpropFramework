#ifndef SRC_OPERATIONS_ARITHMETIC_DIVISION_H_
#define SRC_OPERATIONS_ARITHMETIC_DIVISION_H_

#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/Operation.h"
#include "Core/IDifferentiableExecutor.h"

class DivisionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
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
