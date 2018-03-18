#include "FakeNonDifferentiableConstant.h"

FakeNonDifferentiableConstantExecutor::FakeNonDifferentiableConstantExecutor(float value) {
    _value = Scalar(value);
}

DataObject FakeNonDifferentiableConstantExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return _value;
}

FakeNonDifferentiableConstant::FakeNonDifferentiableConstant(float value): Node({}) {
    std::shared_ptr<FakeNonDifferentiableConstantExecutor> executor(new FakeNonDifferentiableConstantExecutor(value));
    RegisterExecutor(executor);
}

DataObject FakeNonDifferentiableConstant::Forward(const std::vector<DataObject>& inputs) const {
}
