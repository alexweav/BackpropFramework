#include "Core/ExecutionContext.h"

ExecutionContext::ExecutionContext(void) 
    : ExecutionContext(std::vector<DataObject>(), DataObject()) { }

ExecutionContext::ExecutionContext(const std::vector<DataObject>& inputs)
    : ExecutionContext(inputs, DataObject()) { }

ExecutionContext::ExecutionContext(const DataObject& grad)
    : ExecutionContext(std::vector<DataObject>(), grad) { }

ExecutionContext::ExecutionContext(const std::vector<DataObject>& inputs, const DataObject& grad)
    : _inputs(inputs), _downstreamGradient(grad) { }

std::vector<DataObject> ExecutionContext::Inputs(void) const {
    return _inputs;
}

DataObject ExecutionContext::DownstreamGradient(void) const {
    return _downstreamGradient;
}

void ExecutionContext::PushInput(const DataObject& input) {
    _inputs.push_back(input);
}

void ExecutionContext::SetGradient(const DataObject& grad) {
    _downstreamGradient = grad;
}
