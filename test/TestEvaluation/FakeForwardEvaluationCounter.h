#ifndef TEST_EVALUATION_FAKE_FORWARD_EVALUATION_COUNTER_H_
#define TEST_EVALUATION_FAKE_FORWARD_EVALUATION_COUNTER_H_

#include "Core/IExecutor.h"
#include "Core/Node.h"
#include "Data/Datatypes.h"

class FakeForwardEvaluationCounterExecutor: public IExecutor {
 public:
    virtual DataObject operator() (const std::vector<DataObject>& inputs) const;
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
    std::shared_ptr<FakeForwardEvaluationCounterExecutor> _executor;
};

#endif  // TEST_EVALUATION_FAKE_FORWARD_EVALUATION_COUNTER_H_
