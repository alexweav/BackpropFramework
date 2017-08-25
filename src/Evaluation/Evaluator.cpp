#include "Evaluator.h"
#include <algorithm>
#include <iostream>

using namespace utils;

DataObject Evaluator::ForwardEvaluate(Node* node, const Variables& vars) {
    Dictionary<Node*, DataObject> evaluated;
    for(pair<Input*, DataObject> element : vars) {
        evaluated[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);
    vector<float> inputs_f = GetFloatVectorFromDataObjectVector(inputs);
    float result = node->Forward(inputs_f);
    DataObject res(result);
    evaluated[node] = res;
    order->push_back(node);
    free(order);
    return res;
}

DataObject Evaluator::ForwardEvaluate(Node* node, Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
    vector<DataObject> inputs = EvaluatePredecessors(node, evaluated, order);   
    vector<float> inputs_f = GetFloatVectorFromDataObjectVector(inputs);
    float result = node->Forward(inputs_f);
    DataObject res(result);
    order->push_back(node);
    return res;
}

vector<DataObject> Evaluator::EvaluatePredecessors(Node* node, Dictionary<Node*, DataObject>& evaluated, vector<Node*>* order) {
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

Dictionary<Node*, DataObject> Evaluator::BackwardEvaluate(Differentiable* node, const Variables& vars) {
    Dictionary<Node*, DataObject> forwardResults;
    for (pair<Input*, DataObject> element : vars) {
        forwardResults[element.first] = element.second;
    }
    vector<Node*>* order = new vector<Node*>();
    this->ForwardEvaluate(node, forwardResults, order);
    reverse(order->begin(), order->end());
    Dictionary<Node*, DataObject> grads;
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
            float prevGrad = grads[predecessors->at(i)].GetData<float>();
            DataObject newGrad(prevGrad + (gradOut.at(i) * grads[n].GetData<float>()));
            grads[predecessors->at(i)] = newGrad;
        }
        
    }
    return grads;
}

vector<float> Evaluator::GetFloatVectorFromDataObjectVector(const vector<DataObject>& vec) {
    vector<float> result;
    for(DataObject data : vec) {
        result.push_back(data.GetData<float>());
    }
    return result;
}
