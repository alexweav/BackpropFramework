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
    ChannelDictionary evaluated;
    LoadVariableOverrides(vars, evaluated);
    return EvaluateGraph(std::vector<NodePtr>(nodes), evaluated);
}

ChannelDictionary LazyEvaluator::EvaluateGraph(std::vector<NodePtr> nodes, ChannelDictionary& evaluated) {
    ChannelDictionary targetResults;
    for (NodePtr node : nodes) {
        if (!IsEvaluated(node, evaluated)) {
            ChannelDictionary predecessorResults = EvaluatePredecessors(node, evaluated);
            AddChannelDictionaries(evaluated, predecessorResults);
            //TODO:get inputs and evaluate node
        }
    }
    return targetResults;
}

ChannelDictionary LazyEvaluator::EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated) {
    return EvaluateGraph(node->Predecessors(), evaluated);
}

std::vector<DataObject> LazyEvaluator::GetInputs(const NodePtr& node, const ChannelDictionary& evaluated) {
    //TODO:convert evaluated predecessor dictionary to a list of operable inputs
    for (NodePtr node : node->Predecessors()) {
        
    }
}

bool LazyEvaluator::IsEvaluated(const NodePtr& node, const ChannelDictionary& evaluated) const {
    try {
        return evaluated.find(node->Channels(0)) == evaluated.end();
    } catch (const std::out_of_range& ex) {
        return true;    //Node has no Channels, so it's evaluated vacuously
    }
}

