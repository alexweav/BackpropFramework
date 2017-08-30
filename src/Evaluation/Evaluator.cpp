#include "src/Evaluation/Evaluator.h"
#include <algorithm>
#include <iostream>
#include <utility>

DataObject Evaluator::ForwardEvaluate(Node* node, const Variables& vars) {
    utils::Dictionary<Node*, DataObject> evaluated;
    for (pair<Input*, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result = node->Forward(inputs);
    evaluated[node] = result;
    order->push_back(node);
    free(order);
    return result;
}

DataObject Evaluator::ForwardEvaluate(Node* node, utils::Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
    vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    DataObject result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

vector<DataObject> Evaluator::EvaluatePredecessors(Node* node, utils::Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
    vector<DataObject> inputs(node->Arity());
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
    for (pair<Input*, DataObject> element : vars) {
        forwardResults[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    utils::Dictionary<Node*, DataObject> grads;
    grads[node] = Scalar(1.0);
    for (Node* n : *order) {
        Differentiable* diffNode = dynamic_cast<Differentiable*>(n);
        vector<DataObject> prevInputs;
        vector<Node*>* predecessors = n->Predecessors();
        for (Node* pred : *predecessors) {
            prevInputs.push_back(forwardResults[pred]);
        }
        vector<DataObject> gradOut = diffNode->Backward(prevInputs);
        for (int i = 0; i < n->Arity(); i++) {
            DataObject prevGrad = grads[predecessors->at(i)];
            DataObject newGrad = prevGrad.Add(gradOut.at(i).ElementwiseMultiply(grads[n]));
            grads[predecessors->at(i)] = newGrad;
        }
    }
    return grads;
}
