#include "src/Evaluation/Evaluator.h"
#include <algorithm>
#include <iostream>
#include <utility>

ChannelDictionary Evaluator::EvaluateGraph(const NodePtr& node) {
    Variables vars;
    return EvaluateGraph(node, vars);
}

ChannelDictionary Evaluator::EvaluateGraph(const NodePtr& node, const Variables& vars) {
    ChannelDictionary evaluated;
    LoadVariableOverrides(vars, evaluated);
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result;
    ChannelDictionary results = LazyEvaluateNode(node, inputs, evaluated);
    order->push_back(node);
    free(order);
    return results;
}

ChannelDictionary Evaluator::EvaluateGraph(std::initializer_list<NodePtr> nodes) {
    Variables vars;
    return EvaluateGraph(nodes, vars);
}

ChannelDictionary Evaluator::EvaluateGraph(std::initializer_list<NodePtr> nodes, const Variables& vars) {
    std::vector<NodePtr> nodeVector(nodes);
    return EvaluateGraph(nodeVector, vars);
}

ChannelDictionary Evaluator::EvaluateGraph(const std::vector<NodePtr>& nodes) {
    Variables vars;
    return EvaluateGraph(nodes, vars);
}

ChannelDictionary Evaluator::EvaluateGraph(const std::vector<NodePtr>& nodes, const Variables& vars) {
    ChannelDictionary results;
    ChannelDictionary evaluated;
    LoadVariableOverrides(vars, evaluated);
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    for (NodePtr node : nodes) {
        std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
        ChannelDictionary nodeResult = LazyEvaluateNode(node, inputs, evaluated);
        AddChannelDictionaries(results, nodeResult);
        order->push_back(node);
    }
    free(order);
    return results;
}

DataObject Evaluator::ForwardEvaluate(const NodePtr& node, ChannelDictionary& evaluated, std::vector<NodePtr>* order) {
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

std::vector<DataObject> Evaluator::EvaluatePredecessors(const NodePtr& node, ChannelDictionary& evaluated, std::vector<NodePtr>* order) {
    std::vector<DataObject> inputs(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors().at(i).second) == evaluated.end()) {
            DataObject res = ForwardEvaluate(node->Predecessors().at(i).first, evaluated, order);
            inputs.at(i) = res;
            evaluated[node->Predecessors().at(i).second] = res;
        } else {
            DataObject res = evaluated[node->Predecessors().at(i).second];
            inputs.at(i) = res;
        }
    }
    return inputs;
}

ChannelDictionary Evaluator::BackwardEvaluate(const DifferentiablePtr& node, const Variables& vars) {
    ChannelDictionary forwardResults;
    LoadVariableOverrides(vars, forwardResults);
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    ChannelDictionary grads;
    grads[node->Channels(0)] = Scalar(1.0);
    for (NodePtr n : *order) {
        DifferentiablePtr diffNode = std::dynamic_pointer_cast<Differentiable>(n);
        std::vector<DataObject> prevInputs;
        std::vector<std::pair<NodePtr, Channel>> predecessors = n->Predecessors();
        for (std::pair<NodePtr, Channel> pred : predecessors) {
            prevInputs.push_back(forwardResults[pred.second]);
        }
        std::vector<DataObject> gradOut = diffNode->Backward(prevInputs, grads[n->Channels(0)]);
        for (int i = 0; i < n->Arity(); i++) {
            DataObject prevGrad = grads[predecessors.at(i).second];
            DataObject newGrad = prevGrad.Add(gradOut.at(i));
            grads[predecessors.at(i).second] = newGrad;
        }
    }
    return grads;
}

ChannelDictionary Evaluator::LazyEvaluateNode(const NodePtr& node, const std::vector<DataObject>& inputs, ChannelDictionary& evaluated) {
    ChannelDictionary results;
    bool knownEvaluated = false;
    for (Channel channel : node->Channels()) {
        if (!knownEvaluated && evaluated.find(channel) == evaluated.end()) {
            results[channel] = node->Forward(inputs);
            evaluated[channel] = results[channel];
        } else {
            results[channel] = evaluated[channel];
        }
    }
    return results;
}

