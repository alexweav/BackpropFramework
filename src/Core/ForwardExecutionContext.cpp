#include "Core/ForwardExecutionContext.h"

ForwardExecutionContext::ForwardExecutionContext(void) { }

ForwardExecutionContext::ForwardExecutionContext(const std::vector<DataObject>& inputs)
    : _inputs(inputs) { }

std::vector<DataObject> ForwardExecutionContext::Inputs(void) const {
    return _inputs;
}

DataObject ForwardExecutionContext::DownstreamGradient(void) const {
    return DataObject(0);
}

void ForwardExecutionContext::PushInput(const DataObject& input) {
    _inputs.push_back(input);
}
