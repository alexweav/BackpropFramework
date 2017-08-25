#include "Evaluator.h"
#include <algorithm>

using namespace utils;

float Evaluator::ForwardEvaluate(Node* node, const Dictionary<Input*, DataObject>& vars) {
    Dictionary<Node*, DataObject> evaluated;
    for(pair<Input*, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    vector<float> inputs = EvaluatePredecessors(node, evaluated, order);
    float result = node->Forward(inputs);
    DataObject res(result);
    evaluated[node] = res;
    order->push_back(node);
    free(order);
    return result;
}

float Evaluator::ForwardEvaluate(Node* node, Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
    vector<float> inputs = EvaluatePredecessors(node, evaluated, order);   
    float result = node->Forward(inputs);
    order->push_back(node);
    return result;
}

vector<float> Evaluator::EvaluatePredecessors(Node* node, Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
    vector<float> inputs(node->Arity());
    for (int i = 0; i < node->Arity(); i++) {
        if (evaluated.find(node->Predecessors()->at(i)) == evaluated.end()) {
            inputs.at(i) = ForwardEvaluate(node->Predecessors()->at(i), evaluated, order);
            DataObject res(inputs.at(i));
            evaluated[node->Predecessors()->at(i)] = res;
        } else {
            inputs.at(i) = evaluated[node->Predecessors()->at(i)].GetData<float>();
        }
    }
    return inputs;
}

Dictionary<Node*, float> Evaluator::BackwardEvaluate(Differentiable* node, const Dictionary<Input*, DataObject>& vars) {
    Dictionary<Node*, DataObject> forwardResults;
    for (pair<Input*, DataObject> element : vars) {
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
            prevInputs.push_back(forwardResults[pred].GetData<float>());
        }
        vector<float> gradOut = diffNode->Backward(prevInputs);
        for (int i = 0; i < n->Arity(); i++) {
            grads[predecessors->at(i)] += gradOut.at(i) * grads[n];
        }
        
    }
    return grads;
}
