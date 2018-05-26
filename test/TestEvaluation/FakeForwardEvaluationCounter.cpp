#include "FakeForwardEvaluationCounter.h"

DataObject FakeForwardEvaluationCounterExecutor::operator() (const std::vector<DataObject>& inputs) const {
    return DataObject(++_numEvaluations);
}

int FakeForwardEvaluationCounterExecutor::GetNumEvaluations(void) {
    return _numEvaluations;
}

void FakeForwardEvaluationCounterExecutor::ResetCounter(void) {
    _numEvaluations = 0;
}

FakeForwardEvaluationCounter::FakeForwardEvaluationCounter() : Node({}), _executor(new FakeForwardEvaluationCounterExecutor()) {
    RegisterExecutor(_executor);
}

int FakeForwardEvaluationCounter::GetNumEvaluations(void) {
    return _executor->GetNumEvaluations();
}

void FakeForwardEvaluationCounter::ResetCounter(void) {
    _executor->ResetCounter();
}
