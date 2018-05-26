#ifndef SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_
#define SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_

#include <vector>

#include "Core/Operation.h"
#include "Core/IDifferentiableExecutor.h"

class MultiplicationExecutor: public IDifferentiableExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    std::vector<DataObject> Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const;

 private:
    DataObject HandleMultiply(const DataObject&, const DataObject&) const;
    DataObject ScalarMultiply(const DataObject&, const DataObject&) const;
    DataObject MatrixMultiply(const DataObject&, const DataObject&) const;
    std::vector<DataObject> HandleBackward(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateScalarMultiplication(const DataObject&, const DataObject&, const DataObject&) const;
    std::vector<DataObject> DifferentiateMatrixMultiplication(const DataObject&, const DataObject&, const DataObject&) const;
};

class Multiplication: public Operation {
 public:
    Multiplication(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2);

 private:
    MultiplicationExecutor _executor;
};

std::shared_ptr<Multiplication> Multiply(const IChannelProviderPtr&, const IChannelProviderPtr&);
std::shared_ptr<Multiplication> operator*(const IChannelProviderPtr&, const IChannelProviderPtr&);

#endif  // SRC_OPERATIONS_ARITHMETIC_MULTIPLICATION_H_
