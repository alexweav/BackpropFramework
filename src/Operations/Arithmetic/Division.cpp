#include "Operations/Arithmetic/Division.h"

DataObject DivisionExecutor::operator() (const std::vector<DataObject>& inputs) const {
    DataObject result(inputs.at(0).ToScalar() / inputs.at(1).ToScalar());
    return result;
}

std::vector<DataObject> DivisionExecutor::Differentiate(const std::vector<DataObject>& prevInputs, const DataObject& dOut) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(dOut.ToScalar() / prevInputs.at(1).ToScalar());
    grads.at(1) = Scalar(prevInputs.at(0).ToScalar() * -(dOut.ToScalar() / (prevInputs.at(1).ToScalar() * prevInputs.at(1).ToScalar())));
    return grads;
}

Division::Division(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) : Node({i1, i2}) {
    RegisterDifferentiableExecutor(std::make_shared<DivisionExecutor>(_executor));
}

std::shared_ptr<Division> Divide(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    std::shared_ptr<Division> ptr(new Division(i1, i2));
    return ptr;
}

std::shared_ptr<Division> operator/(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Divide(i1, i2);
}
