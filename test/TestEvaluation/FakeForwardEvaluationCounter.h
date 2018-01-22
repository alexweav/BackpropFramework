#ifndef FAKE_FORWARD_EVALUATION_COUNTER_H
#define FAKE_FORWARD_EVALUATION_COUNTER_H

#include "Data/Datatypes.h"
#include "Operations/Base/IExecutor.h"
#include "Operations/Base/Node.h"

class FakeForwardEvaluationCounterExecutor: public IExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
    int GetNumEvaluations(void);
    void ResetCounter(void);

 protected:
    mutable int _numEvaluations = 0;

};

class FakeForwardEvaluationCounter: public Node {
    public:
        FakeForwardEvaluationCounter(void);
        DataObject Forward(const std::vector<DataObject>&) const;
        int GetNumEvaluations(void);
        void ResetCounter(void);
    protected:
        FakeForwardEvaluationCounterExecutor _executor;
};

#endif
