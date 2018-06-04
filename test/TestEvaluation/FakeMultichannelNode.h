#ifndef TEST_TESTEVALUATION_FAKEMULTICHANNELNODE_H_
#define TEST_TESTEVALUATION_FAKEMULTICHANNELNODE_H_

#include <vector>

#include "Core/ExecutionContext.h"
#include "Core/IExecutor.h"
#include "Core/Node.h"
#include "Data/Datatypes.h"

#include "FakeForwardEvaluationCounter.h"

class FakeAddExecutor: public FakeForwardEvaluationCounterExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
};

class FakeSubtractExecutor: public FakeForwardEvaluationCounterExecutor {
 public:
    DataObject operator() (const ExecutionContext& context) const;
};

class FakeMultichannelNode: public Node {
 public:
    FakeMultichannelNode(const NodePtr& base, const NodePtr& add, const NodePtr& subtract);
    int GetNumAdds(void);
    int GetNumSubtracts(void);
    void ResetCounter(void);

 protected:
    std::shared_ptr<FakeAddExecutor> _addExecutor;
    std::shared_ptr<FakeSubtractExecutor> _subtractExecutor;
};

#endif  // TEST_TESTEVALUATION_FAKEMULTICHANNELNODE_H_
