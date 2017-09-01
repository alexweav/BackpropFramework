#include "src/Evaluation/Evaluator.h"
#include <algorithm>
#include <iostream>
#include <utility>

DataObject Evaluator::ForwardEvaluate(Node* node, const Variables& vars) {
    utils::Dictionary<Node*, DataObject> evaluated;
    for (std::pair<Input*, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    std::vector<Node*>* order = new std::vector<Node*>();
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

DataObject Evaluator::ForwardEvaluate(Node* node, utils::Dictionary<Node*, DataObject>& evaluated, std::vector<Node*>* order) {
    std::vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

std::vector<DataObject> Evaluator::EvaluatePredecessors(Node* node, utils::Dictionary<Node*, DataObject>& evaluated, std::vector<Node*>* order) {
    std::vector<DataObject> inputs(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors()->at(i)) == evaluated.end()) {
            DataObject res = ForwardEvaluate(node->Predecessors()->at(i), evaluated, order);
            inputs.at(i) = res;
            evaluated[node->Predecessors()->at(i)] = res;
        } else {
            DataObject res = evaluated[node->Predecessors()->at(i)];
            inputs.at(i) = res;
        }
    }
    return inputs;
}

utils::Dictionary<Node*, DataObject> Evaluator::BackwardEvaluate(Differentiable* node, const Variables& vars) {
    utils::Dictionary<Node*, DataObject> forwardResults;
    for (std::pair<Input*, DataObject> element : vars) {
        forwardResults[element.first] = element.second;
    }
    std::vector<Node*>* order = new std::vector<Node*>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    utils::Dictionary<Node*, DataObject> grads;
    grads[node] = Scalar(1.0);
    for (Node* n : *order) {
        Differentiable* diffNode = dynamic_cast<Differentiable*>(n);
        std::vector<DataObject> prevInputs;
        std::vector<Node*>* predecessors = n->Predecessors();
        for (Node* pred : *predecessors) {
            prevInputs.push_back(forwardResults[pred]);
        }
        std::vector<DataObject> gradOut = diffNode->Backward(prevInputs, grads[n]);
        for (int i = 0; i < n->Arity(); i++) {
            DataObject prevGrad = grads[predecessors->at(i)];
            DataObject newGrad = prevGrad.Add(gradOut.at(i));
            grads[predecessors->at(i)] = newGrad;
        }
    }
    return grads;
}
