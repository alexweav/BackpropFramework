#ifndef SRC_EVALUATION_IEVALUATOR_H_
#define SRC_EVALUATION_IEVALUATOR_H_

#include <vector>

#include "Operations/Base/Input.h"
#include "Operations/Base/Node.h"

#include "Utils.h"

class IEvaluator {
 public:
     virtual ChannelDictionary EvaluateGraph(const NodePtr& node) = 0;
     virtual ChannelDictionary EvaluateGraph(const NodePtr& node, const Variables& vars) = 0;
     virtual ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes) = 0;
     virtual ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr> nodes, const Variables& vars) = 0;
     virtual ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes) = 0;
     virtual ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes, const Variables& vars) = 0;
};

#endif  // SRC_EVALUATION_IEVALUATOR_H_
