#include "FakeForwardEvaluationCounter.h"

FakeForwardEvaluationCounter::FakeForwardEvaluationCounter() : Node({}, false) { }

DataObject FakeForwardEvaluationCounter::Forward(const vector<DataObject>& inputs) const {
    DataObject result(++_numEvaluations);
    return result;
}

int FakeForwardEvaluationCounter::GetNumEvaluations() {
    return _numEvaluations;
}

void FakeForwardEvaluationCounter::ResetCounter() {
    _numEvaluations = 0;
}
