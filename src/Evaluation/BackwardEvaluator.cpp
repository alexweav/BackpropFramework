#include "BackwardEvaluator.h"
#include <algorithm>
#include <iostream>

Dictionary<Node*, float> BackwardEvaluator::BackwardEvaluate(Differentiable* node, const Dictionary<Input*, float>& vars) {
    Dictionary<Node*, float> forwardResults;
    for (pair<Input*, float> element : vars) {
        forwardResults[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    Dictionary<Node*, float> grads;
    grads[node] = 1.0;
    for(Node* n : *order) {
        Differentiable* diffNode = dynamic_cast<Differentiable*>(n);
        vector<float> prevInputs;
        vector<Node*>* predecessors = n->Predecessors();
        for (Node* pred : *predecessors) {
            prevInputs.push_back(forwardResults[pred]);
        }
        vector<float> gradOut = diffNode->Backward(prevInputs);
        for (int i = 0; i < n->Arity(); i++) {
            grads[predecessors->at(i)] += gradOut.at(i) * grads[n];
        }
        
    }
    return grads;
}
