#include "ForwardEvaluator.h"

using namespace utils;

float ForwardEvaluator::ForwardEvaluate(Node* node, const Dictionary<Input*, float>& vars) {
    Dictionary<Node*, float> evaluated;
    for(pair<Input*, float> element : vars) {
        evaluated[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    vector<float> inputs = EvaluatePredecessors(node, evaluated, order);
    float result = node->Forward(inputs);
    evaluated[node] = result;
    order->push_back(node);
    free(order);
    return result;
}

float ForwardEvaluator::ForwardEvaluate(Node* node, Dictionary<Node*, float>& evaluated, vector<Node*>* order) {
    vector<float> inputs = EvaluatePredecessors(node, evaluated, order);   
    float result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

vector<float> ForwardEvaluator::EvaluatePredecessors(Node* node, Dictionary<Node*, float>& evaluated, vector<Node*>* order) {
    vector<float> inputs(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors()->at(i)) == evaluated.end()) {
            inputs.at(i) = ForwardEvaluate(node->Predecessors()->at(i), evaluated, order);
            evaluated[node->Predecessors()->at(i)] = inputs.at(i);
        } else {
            inputs.at(i) = evaluated[node->Predecessors()->at(i)];
        }
    }
    return inputs;
}

