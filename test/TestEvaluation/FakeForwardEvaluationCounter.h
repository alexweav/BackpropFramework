#ifndef TEST_TESTEVALUATION_FAKEFORWARDEVALUATIONCOUNTER_H_
#define TEST_TESTEVALUATION_FAKEFORWARDEVALUATIONCOUNTER_H_

#include <vector>

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
    int GetNumEvaluations(void);
    void ResetCounter(void);

 protected:
    std::shared_ptr<FakeForwardEvaluationCounterExecutor> _executor;
};

#endif  // TEST_TESTEVALUATION_FAKEFORWARDEVALUATIONCOUNTER_H_
