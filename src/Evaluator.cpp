#include "Evaluator.h"

using namespace std;
using namespace utils;

float Evaluator::ForwardEvaluate(Node* node, Dictionary<Input*, float>* vars) {
    Dictionary<Node*, float> evaluated;
    for(pair<Input*, float> element : *vars) {
        evaluated[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    vector<float>* inputs = EvaluatePredecessors(node, evaluated, order);
    float result = node->Forward(inputs);
    evaluated[node] = result;
    order->push_back(node);
    free(inputs);
    free(order);
    return result;
}

float Evaluator::ForwardEvaluate(Node*& node, Dictionary<Node*, float>& evaluated, vector<Node*>* order) {
    vector<float>* inputs = EvaluatePredecessors(node, evaluated, order);   
    float result = node->Forward(inputs);
    order->push_back(node);
    free(inputs);
    return result;
}

vector<float>* Evaluator::EvaluatePredecessors(Node* node, Dictionary<Node*, float>& evaluated, vector<Node*>* order) {
    vector<float>* inputs = new vector<float>(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors()->at(i)) == evaluated.end()) {
            inputs->at(i) = ForwardEvaluate(node->Predecessors()->at(i), evaluated, order);
            evaluated[node->Predecessors()->at(i)] = inputs->at(i);
        } else {
            inputs->at(i) = evaluated[node->Predecessors()->at(i)];
        }
    }
    return inputs;
}

