#include "src/Evaluation/Evaluator.h"
#include <algorithm>
#include <iostream>
#include <utility>

DataObject Evaluator::ForwardEvaluate(const NodePtr& node) {
    Variables vars;
    return ForwardEvaluate(node, vars);
}

DataObject Evaluator::ForwardEvaluate(const NodePtr& node, const Variables& vars) {
    ChannelDictionary evaluated;
    LoadVariableOverrides(vars, evaluated);
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result;
    ChannelDictionary results = LazyEvaluateNode(node, inputs, evaluated);
    order->push_back(node);
    free(order);
    return results[node->Channels(0)];
}

ChannelDictionary Evaluator::MultipleEvaluate(std::initializer_list<NodePtr> nodes) {
    Variables vars;
    return MultipleEvaluate(nodes, vars);
}

ChannelDictionary Evaluator::MultipleEvaluate(std::initializer_list<NodePtr> nodes, const Variables& vars) {
    std::vector<NodePtr> nodeVector(nodes);
    return MultipleEvaluate(nodeVector, vars);
}

ChannelDictionary Evaluator::MultipleEvaluate(const std::vector<NodePtr>& nodes) {
    Variables vars;
    return MultipleEvaluate(nodes, vars);
}

ChannelDictionary Evaluator::MultipleEvaluate(const std::vector<NodePtr>& nodes, const Variables& vars) {
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
        if (evaluated.find(node->Predecessors().at(i)->Channels(0)) == evaluated.end()) {
            DataObject res = ForwardEvaluate(node->Predecessors().at(i), evaluated, order);
            inputs.at(i) = res;
            evaluated[node->Predecessors().at(i)->Channels(0)] = res;
        } else {
            DataObject res = evaluated[node->Predecessors().at(i)->Channels(0)];
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
        std::vector<NodePtr> predecessors = n->Predecessors();
        for (NodePtr pred : predecessors) {
            prevInputs.push_back(forwardResults[pred->Channels(0)]);
        }
        std::vector<DataObject> gradOut = diffNode->Backward(prevInputs, grads[n->Channels(0)]);
        for (int i = 0; i < n->Arity(); i++) {
            DataObject prevGrad = grads[predecessors.at(i)->Channels(0)];
            DataObject newGrad = prevGrad.Add(gradOut.at(i));
            grads[predecessors.at(i)->Channels(0)] = newGrad;
        }
    }
    return grads;
}

void Evaluator::LoadVariableOverrides(const Variables& variables, ChannelDictionary& overrides) {
    for (std::pair<InputPtr, DataObject> element : variables) {
        overrides[element.first->Channels(0)] = element.second; // Inputs have only one Channel by definition
    }
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

void Evaluator::AddChannelDictionaries(ChannelDictionary& target, const ChannelDictionary& source) {
    for (std::pair<Channel, DataObject> element : source) {
        target[element.first] = element.second;
    }
}
