#ifndef SRC_EVALUATION_EVALUATOR_H_
#define SRC_EVALUATION_EVALUATOR_H_

#include "Operations/Base/Differentiable.h"
#include "Operations/Base/Input.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"

#include <vector>

#include "IEvaluator.h"
#include "Utils.h"

class Evaluator: public IEvaluator {
 public:
    ChannelDictionary EvaluateGraph(const NodePtr& node);
    ChannelDictionary EvaluateGraph(const NodePtr&, const Variables& vars);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr>);
    ChannelDictionary EvaluateGraph(std::initializer_list<NodePtr>, const Variables& vars);
    ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes);
    ChannelDictionary EvaluateGraph(const std::vector<NodePtr>& nodes, const Variables& vars);
    ChannelDictionary BackwardEvaluate(const DifferentiablePtr&, const Variables&);
 protected:
    DataObject ForwardEvaluate(const NodePtr&, ChannelDictionary&, std::vector<NodePtr>*);
    std::vector<DataObject> EvaluatePredecessors(const NodePtr&, ChannelDictionary&, std::vector<NodePtr>*);
 private:
    ChannelDictionary LazyEvaluateNode(const NodePtr& node, const std::vector<DataObject>& inputs, ChannelDictionary& evaluated);
};

#endif  // SRC_EVALUATION_EVALUATOR_H_
