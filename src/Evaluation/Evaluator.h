#ifndef SRC_EVALUATION_EVALUATOR_H_
#define SRC_EVALUATION_EVALUATOR_H_

#include <vector>
#include "Operations/Base/Differentiable.h"
#include "Operations/Base/Input.h"
#include "Utils/Dictionary.h"
#include "Data/Datatypes.h"

class Evaluator {
 public:
    DataObject ForwardEvaluate(const NodePtr& node);
    DataObject ForwardEvaluate(const NodePtr&, const Variables& vars);
    ChannelDictionary MultipleEvaluate(std::initializer_list<NodePtr>);
    ChannelDictionary MultipleEvaluate(std::initializer_list<NodePtr>, const Variables& vars);
    ChannelDictionary MultipleEvaluate(const std::vector<NodePtr>& nodes);
    ChannelDictionary MultipleEvaluate(const std::vector<NodePtr>& nodes, const Variables& vars);
    ChannelDictionary BackwardEvaluate(const DifferentiablePtr&, const Variables&);
 protected:
    DataObject ForwardEvaluate(const NodePtr&, ChannelDictionary&, std::vector<NodePtr>*);
    std::vector<DataObject> EvaluatePredecessors(const NodePtr&, ChannelDictionary&, std::vector<NodePtr>*);
 private:
    void LoadVariableOverrides(const Variables& vars, ChannelDictionary& overrides);
    ChannelDictionary LazyEvaluateNode(const NodePtr& node, const std::vector<DataObject>& inputs, ChannelDictionary& evaluated);
    void AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source);
};

#endif  // SRC_EVALUATION_EVALUATOR_H_
