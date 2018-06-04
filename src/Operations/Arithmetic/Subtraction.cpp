#include "Operations/Arithmetic/Subtraction.h"

DataObject SubtractionExecutor::operator() (const ExecutionContext& context) const {
    DataObject result(context.Inputs().at(0).ToScalar() - context.Inputs().at(1).ToScalar());
    return result;
}

std::vector<DataObject> SubtractionExecutor::Differentiate(const ExecutionContext& context) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(context.DownstreamGradient());
    grads.at(1) = Scalar(-1.0).ElementwiseMultiply(context.DownstreamGradient());
    return grads;
}

Subtraction::Subtraction(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2): Node({i1, i2}) {
    RegisterDifferentiableExecutor(std::make_shared<SubtractionExecutor>(_executor));
}

std::shared_ptr<Subtraction> Subtract(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    std::shared_ptr<Subtraction> ptr(new Subtraction(i1, i2));
    return ptr;
}

std::shared_ptr<Subtraction> operator-(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Subtract(i1, i2);
}
