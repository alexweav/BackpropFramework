#include "FakeForwardEvaluationCounter.h"

FakeForwardEvaluationCounter::FakeForwardEvaluationCounter() : Node({}, false) { }

float FakeForwardEvaluationCounter::Forward(const vector<float>& inputs) const {
    return ++_numEvaluations;
}

int FakeForwardEvaluationCounter::GetNumEvaluations() {
    return _numEvaluations;
}

void FakeForwardEvaluationCounter::ResetCounter() {
    _numEvaluations = 0;
}
