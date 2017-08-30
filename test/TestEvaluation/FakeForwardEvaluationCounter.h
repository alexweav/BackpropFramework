#ifndef FAKE_FORWARD_EVALUATION_COUNTER_H
#define FAKE_FORWARD_EVALUATION_COUNTER_H

#include "Operations/Base/Node.h"

class FakeForwardEvaluationCounter : public Node {
    public:
        FakeForwardEvaluationCounter();
        DataObject Forward(const vector<DataObject>&) const;
        int GetNumEvaluations();
        void ResetCounter();
    protected:
        mutable int _numEvaluations = 0;
};

#endif
