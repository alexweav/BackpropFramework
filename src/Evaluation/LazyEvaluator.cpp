#include "LazyEvaluator.h"
#include <iostream>

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
            std::vector<DataObject> inputs = GetInputs(node, evaluated);
            ChannelDictionary localResults = node->Execute(inputs);
            AddChannelDictionaries(targetResults, localResults);
            AddChannelDictionaries(evaluated, localResults);
        }
    }
    return targetResults;
}

ChannelDictionary LazyEvaluator::EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated) {
    return EvaluateGraph(GetNodesFromPredecessors(node), evaluated);
}

std::vector<DataObject> LazyEvaluator::GetInputs(const NodePtr& node, ChannelDictionary& evaluated) {
    std::vector<DataObject> inputs;
    for (std::pair<NodePtr, Channel> predecessor : node->Predecessors()) {
        inputs.push_back(evaluated[predecessor.second]);
    }
    return inputs;
}

bool LazyEvaluator::IsEvaluated(const NodePtr& node, const ChannelDictionary& evaluated) const {
    try {
        return evaluated.count(node->Channels(0)) > 0; // TODO:inefficient
    } catch (const std::out_of_range& ex) {
        return true;    //node has no Channels, so it's evaluated vacuously
    }
}

std::vector<NodePtr> LazyEvaluator::GetNodesFromPredecessors(const NodePtr& node) const {
    std::vector<NodePtr> nodes;
    for (std::pair<NodePtr, Channel> predecessor : node->Predecessors()) {
        nodes.push_back(predecessor.first);
    }
    return nodes;
}

