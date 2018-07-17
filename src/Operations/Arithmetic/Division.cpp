#include "Operations/Arithmetic/Division.h"

DataObject DivisionExecutor::operator() (const ExecutionContext& context) const {
    DataObject result(context.Inputs().at(0).ToScalar() / context.Inputs().at(1).ToScalar());
    return result;
}

std::vector<DataObject> DivisionExecutor::Differentiate(const ExecutionContext& context) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(context.DownstreamGradient().ToScalar() / context.Inputs().at(1).ToScalar());
    grads.at(1) = Scalar(context.Inputs().at(0).ToScalar() * -(context.DownstreamGradient().ToScalar() / (context.Inputs().at(1).ToScalar() * context.Inputs().at(1).ToScalar())));
    return grads;
}

Division::Division(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) : Node({i1, i2}) {
    AttachDifferentiableExecutor(std::make_shared<DivisionExecutor>(_executor));
}

std::shared_ptr<Division> Divide(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    std::shared_ptr<Division> ptr(new Division(i1, i2));
    return ptr;
}

std::shared_ptr<Division> operator/(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Divide(i1, i2);
}
