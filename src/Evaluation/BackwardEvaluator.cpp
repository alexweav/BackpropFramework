#include "BackwardEvaluator.h"
#include <algorithm>
#include <iostream>

Dictionary<Node*, float> BackwardEvaluator::BackwardEvaluate(Node* node, const Dictionary<Input*, float>& vars) {
    Dictionary<Node*, float> forwardResults;
    for (pair<Input*, float> element : vars) {
        forwardResults[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    Dictionary<Node*, float> grads;
    Dictionary<Node*, float> inGrads;
    inGrads[node] = 1.0;
    for(Node* n : *order) {
        
    }
}
