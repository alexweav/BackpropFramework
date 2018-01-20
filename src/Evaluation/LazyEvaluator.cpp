#include "LazyEvaluator.h"

ChannelDictionary LazyEvaluator::EvaluateGraph(const NodePtr& node) {
    Variables vars;
    return EvaluateGraph(node, vars);
}

ChannelDictionary LazyEvaluator::EvaluateGraph(const NodePtr& node, const Variables& vars) {
    return EvaluateGraph({node}, vars);
}

ChannelDictionary LazyEvaluator::EvaluateGraph(std::initializer_list<NodePtr> nodes) {
    Variables vars;
    return EvaluateGraph(nodes, vars);
}

ChannelDictionary LazyEvaluator::EvaluateGraph(std::initializer_list<NodePtr> nodes, const Variables& vars) {

}

ChannelDictionary LazyEvaluator::EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated) {

}

std::vector<DataObject> LazyEvaluator::GetInputs(const NodePtr& node, const ChannelDictionary& evaluated) {

}
