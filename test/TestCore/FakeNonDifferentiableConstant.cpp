#include "FakeNonDifferentiableConstant.h"

FakeNonDifferentiableConstantExecutor::FakeNonDifferentiableConstantExecutor(float value) {
    _value = Scalar(value);
}

DataObject FakeNonDifferentiableConstantExecutor::operator() (const ExecutionContext& context) const {
    return _value;
}

FakeNonDifferentiableConstant::FakeNonDifferentiableConstant(float value): Node({}) {
    std::shared_ptr<FakeNonDifferentiableConstantExecutor> executor(new FakeNonDifferentiableConstantExecutor(value));
    RegisterExecutor(executor);
}

