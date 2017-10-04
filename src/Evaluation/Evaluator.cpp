#include "src/Evaluation/Evaluator.h"
#include <algorithm>
#include <iostream>
#include <utility>

DataObject Evaluator::ForwardEvaluate(const NodePtr& node) {
    Variables vars;
    return ForwardEvaluate(node, vars);
}

DataObject Evaluator::ForwardEvaluate(const NodePtr& node, const Variables& vars) {
    utils::Dictionary<Node, DataObject> evaluated;
    for (std::pair<InputPtr, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result;
    if (evaluated.find(node) == evaluated.end()) {
        result = node->Forward(inputs);
        evaluated[node] = result;
    } else {
        result = evaluated[node];
    }
    order->push_back(node);
    free(order);
    return result;
}

ResultDictionary Evaluator::MultipleEvaluate(std::initializer_list<NodePtr> nodes) {
    Variables vars;
    return MultipleEvaluate(nodes, vars);
}

ResultDictionary Evaluator::MultipleEvaluate(std::initializer_list<NodePtr> nodes, const Variables& vars) {
    std::vector<NodePtr> nodeVector(nodes);
    return MultipleEvaluate(nodeVector, vars);
}

ResultDictionary Evaluator::MultipleEvaluate(const std::vector<NodePtr>& nodes) {
    Variables vars;
    return MultipleEvaluate(nodes, vars);
}

ResultDictionary Evaluator::MultipleEvaluate(const std::vector<NodePtr>& nodes, const Variables& vars) {
    utils::Dictionary<Node, DataObject> results;
    utils::Dictionary<Node, DataObject> evaluated;
    for (std::pair<InputPtr, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    for (NodePtr node : nodes) {
        std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
        if (evaluated.find(node) == evaluated.end()) {
            results[node] = node->Forward(inputs);
            evaluated[node] = results[node];
        } else {
            results[node] = evaluated[node];
        }
        order->push_back(node);
    }
    free(order);
    return results;
}

DataObject Evaluator::ForwardEvaluate(const NodePtr& node, utils::Dictionary<Node, DataObject>& evaluated, std::vector<NodePtr>* order) {
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

std::vector<DataObject> Evaluator::EvaluatePredecessors(const NodePtr& node, utils::Dictionary<Node, DataObject>& evaluated, std::vector<NodePtr>* order) {
    std::vector<DataObject> inputs(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors().at(i)) == evaluated.end()) {
            DataObject res = ForwardEvaluate(node->Predecessors().at(i), evaluated, order);
            inputs.at(i) = res;
            evaluated[node->Predecessors().at(i)] = res;
        } else {
            DataObject res = evaluated[node->Predecessors().at(i)];
            inputs.at(i) = res;
        }
    }
    return inputs;
}

ResultDictionary Evaluator::BackwardEvaluate(const DifferentiablePtr& node, const Variables& vars) {
    utils::Dictionary<Node, DataObject> forwardResults;
    for (std::pair<InputPtr, DataObject> element : vars) {
        forwardResults[element.first] = element.second;
    }
    std::vector<NodePtr>* order = new std::vector<NodePtr>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    utils::Dictionary<Node, DataObject> grads;
    grads[node] = Scalar(1.0);
    for (NodePtr n : *order) {
        DifferentiablePtr diffNode = std::dynamic_pointer_cast<Differentiable>(n);
        std::vector<DataObject> prevInputs;
        std::vector<NodePtr> predecessors = n->Predecessors();
        for (NodePtr pred : predecessors) {
            prevInputs.push_back(forwardResults[pred]);
        }
        std::vector<DataObject> gradOut = diffNode->Backward(prevInputs, grads[n]);
        for (int i = 0; i < n->Arity(); i++) {
            DataObject prevGrad = grads[predecessors.at(i)];
            DataObject newGrad = prevGrad.Add(gradOut.at(i));
            grads[predecessors.at(i)] = newGrad;
        }
    }
    return grads;
}
