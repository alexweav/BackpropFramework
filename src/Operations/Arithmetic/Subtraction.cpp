#include "src/Operations/Arithmetic/Subtraction.h"
#include <vector>

DataObject SubtractionExecutor::operator() (const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() - inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> SubtractionExecutor::Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(dOut);
    grads.at(1) = Scalar(-1.0).ElementwiseMultiply(dOut);
    return grads;
}

Subtraction::Subtraction(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2): Node({i1, i2}, true) { 
    RegisterDifferentiableExecutor(std::make_shared<SubtractionExecutor>(_executor));
}

DataObject Subtraction::Forward(const std::vector<DataObject>& inputs) const {
    return _executor(inputs);
}

std::vector<DataObject> Subtraction::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return _executor.Differentiate(prevInputs, dout);
}

std::shared_ptr<Subtraction> Subtract(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    std::shared_ptr<Subtraction> ptr(new Subtraction(i1, i2));
    return ptr;
}

std::shared_ptr<Subtraction> operator-(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Subtract(i1, i2);
}
