#ifndef FAKE_FORWARD_EVALUATION_COUNTER_H
#define FAKE_FORWARD_EVALUATION_COUNTER_H

#include "Operations/Node.h"

class FakeForwardEvaluationCounter : public Node {
    public:
        FakeForwardEvaluationCounter();
        float Forward(const vector<float>&) const;
        int GetNumEvaluations();
        void ResetCounter();
    protected:
        mutable int _numEvaluations = 0;
};

#endif
