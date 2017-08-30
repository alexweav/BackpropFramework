#include "Multiplication.h"

Multiplication::Multiplication(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Multiplication::Forward(const vector<DataObject>& inputs) const {
    //DataObject result(inputs.at(0).GetData<float>() * inputs.at(1).GetData<float>());
    //return result;
    return HandleMultiply(inputs.at(0), inputs.at(1));
}

DataObject Multiplication::HandleMultiply(const DataObject& i1, const DataObject& i2) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return ScalarMultiply(i1, i2);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape().at(1) == i2.Shape().at(0)) {
        return MatrixMultiply(i1, i2);
    }
}

DataObject Multiplication::ScalarMultiply(const DataObject& i1, const DataObject& i2) const {
    return Scalar(i1.GetData<float>() * i2.GetData<float>());
}

DataObject Multiplication::MatrixMultiply(const DataObject& i1, const DataObject& i2) const {
    return Mat(i1.GetData<MatrixXf>() * i2.GetData<MatrixXf>());
}

vector<DataObject> Multiplication::Backward(const vector<DataObject>& prevInputs) const {
    vector<DataObject> grads(this->_arity);
    DataObject grad0(prevInputs.at(1).GetData<float>());
    DataObject grad1(prevInputs.at(0).GetData<float>());
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;
}
