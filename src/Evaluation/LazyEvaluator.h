#ifndef SRC_EVALUATION_LAZYEVALUATOR_H_
#define SRC_EVALUATION_LAZYEVALUATOR_H_

#include "Operations/Base/Input.h"
#include "Operations/Base/Node.h"

#include <vector>

#include "Utils.h"

class LazyEvaluator {
 public:
    ChannelDictionary EvaluateGraph(const NodePtr& node);
    ChannelDictionary EvaluateGraph(const NodePtr& node, const Variables& vars);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes, const Variables& vars);

 protected:
    ChannelDictionary EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated);
    std::vector<DataObject> GetInputs(const NodePtr& node, const ChannelDictionary& evaluated);
};

#endif  // SRC_EVALUATION_LAZYEVALUATOR_H_
