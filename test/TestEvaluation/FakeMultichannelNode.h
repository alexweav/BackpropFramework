#ifndef TEST_EVALUATION_FAKE_MULTICHANNEL_NODE_H_
#define TEST_EVALUATION_FAKE_MULTICHANNEL_NODE_H_

#include "Data/Datatypes.h"
#include "Operations/Base/IExecutor.h"
#include "Operations/Base/Node.h"

class FakeAddExecutor: public IExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
};

class FakeSubtractExecutor: public IExecutor {
 public:
    DataObject operator() (const std::vector<DataObject>& inputs) const;
};

class FakeMultichannelNode: public Node {
 public:
    FakeMultichannelNode(const NodePtr& base, const NodePtr& add, const NodePtr& subtract);
    DataObject Forward(const std::vector<DataObject>&) const;
};

#endif  // TEST_EVALUATION_FAKE_MULTICHANNEL_NODE_H_
