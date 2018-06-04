#ifndef SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
#define SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_

#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/Operation.h"
#include "Core/IDifferentiableExecutor.h"

class SubtractionExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
    std::vector<DataObject> Differentiate(const ExecutionContext& context) const;
};

class Subtraction: public Operation {
 public:
    Subtraction(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2);

 private:
    SubtractionExecutor _executor;
};

std::shared_ptr<Subtraction> Subtract(const IChannelProviderPtr&, const IChannelProviderPtr&);
std::shared_ptr<Subtraction> operator-(const IChannelProviderPtr&, const IChannelProviderPtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_SUBTRACTION_H_
