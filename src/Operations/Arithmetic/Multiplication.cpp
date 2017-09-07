#include "src/Operations/Arithmetic/Multiplication.h"
#include <vector>
#include <iostream>

Multiplication::Multiplication(const NodePtr& i1, const NodePtr& i2): Node({i1, i2}, true) { }

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

std::vector<DataObject> Multiplication::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    return HandleBackward(prevInputs.at(0), prevInputs.at(1), dout);
}

std::vector<DataObject> Multiplication::HandleBackward(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarMultiplication(i1, i2, dout);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape().at(1) == i2.Shape().at(0)) {
        return DifferentiateMatrixMultiplication(i1, i2, dout);
    }
}

std::vector<DataObject> Multiplication::DifferentiateScalarMultiplication(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = i2.ElementwiseMultiply(dout);
    grads.at(1) = i1.ElementwiseMultiply(dout);
    return grads;
}

std::vector<DataObject> Multiplication::DifferentiateMatrixMultiplication(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(this->_arity);
    grads.at(0) = Mat(dout.ToMatrix() * (i2.ToMatrix().transpose()));
    grads.at(1) = Mat((i1.ToMatrix().transpose()) * dout.ToMatrix());
    return grads;
}

std::shared_ptr<Multiplication> Multiply(const NodePtr& i1, const NodePtr& i2) {
    return std::shared_ptr<Multiplication>(new Multiplication(i1, i2));
}

std::shared_ptr<Multiplication> operator*(const NodePtr& i1, const NodePtr& i2) {
    return Multiply(i1, i2);
}
