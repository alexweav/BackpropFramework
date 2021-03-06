#ifndef SRC_EVALUATION_LAZYEVALUATOR_H_
#define SRC_EVALUATION_LAZYEVALUATOR_H_

#include <vector>
#include <utility>

#include "Core/Node.h"
#include "Operations/Value.h"

#include "IEvaluator.h"
#include "Utils.h"

class LazyEvaluator: public IEvaluator {
 public:
    ChannelDictionary EvaluateGraph(const NodePtr& node);
    ChannelDictionary EvaluateGraph(const NodePtr& node, const Variables& vars);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes, const Variables& vars);
    ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes);
    ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes, const Variables& vars);

 protected:
    ChannelDictionary EvaluateGraph(std::vector<NodePtr> nodes, ChannelDictionary& evaluated);
    ChannelDictionary EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated);
    std::vector<DataObject> GetInputs(const NodePtr& node, ChannelDictionary& evaluated);

 private:
    bool IsEvaluated(const NodePtr& node, const ChannelDictionary& evaluated) const;
    std::vector<NodePtr> GetNodesFromPredecessors(const NodePtr& node) const;
};

#endif  // SRC_EVALUATION_LAZYEVALUATOR_H_
