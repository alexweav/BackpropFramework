#include "src/Operations/Arithmetic/Multiplication.h"
#include <vector>

Multiplication::Multiplication(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Multiplication::Forward(const std::vector<DataObject>& inputs) const {
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
    return Scalar(i1.ToScalar() * i2.ToScalar());
}

DataObject Multiplication::MatrixMultiply(const DataObject& i1, const DataObject& i2) const {
    return Mat(i1.ToMatrix() * i2.ToMatrix());
}

std::vector<DataObject> Multiplication::Backward(const std::vector<DataObject>& prevInputs) const {
    /*std::vector<DataObject> grads(this->_arity);
    DataObject grad0(prevInputs.at(1).ToScalar());
    DataObject grad1(prevInputs.at(0).ToScalar());
    grads.at(0) = grad0;
    grads.at(1) = grad1;
    return grads;*/
    return HandleBackward(prevInputs.at(0), prevInputs.at(1));
}

std::vector<DataObject> Multiplication::HandleBackward(const DataObject& i1, const DataObject& i2) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarMultiplication(i1, i2);
    }
}

std::vector<DataObject> Multiplication::DifferentiateScalarMultiplication(const DataObject& i1, const DataObject& i2) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = i2;
    grads.at(1) = i1;
    return grads;
}
