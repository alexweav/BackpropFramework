#include "Operations/Arithmetic/Multiplication.h"

DataObject MultiplicationExecutor::operator()(const ExecutionContext& context) const {
    return HandleMultiply(context.Inputs().at(0), context.Inputs().at(1));
}

std::vector<DataObject> MultiplicationExecutor::Differentiate(const ExecutionContext& context) const {
    return HandleBackward(context.Inputs().at(0), context.Inputs().at(1), context.DownstreamGradient());
}

DataObject MultiplicationExecutor::HandleMultiply(const DataObject& i1, const DataObject& i2) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return ScalarMultiply(i1, i2);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape().at(1) == i2.Shape().at(0)) {
        return MatrixMultiply(i1, i2);
    }
}

DataObject MultiplicationExecutor::ScalarMultiply(const DataObject& i1, const DataObject& i2) const {
    return Scalar(i1.ToScalar() * i2.ToScalar());
}

DataObject MultiplicationExecutor::MatrixMultiply(const DataObject& i1, const DataObject& i2) const {
    return Mat(i1.ToMatrix() * i2.ToMatrix());
}

std::vector<DataObject> MultiplicationExecutor::HandleBackward(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarMultiplication(i1, i2, dout);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape().at(1) == i2.Shape().at(0)) {
        return DifferentiateMatrixMultiplication(i1, i2, dout);
    }
}

std::vector<DataObject> MultiplicationExecutor::DifferentiateScalarMultiplication(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = i2.ElementwiseMultiply(dout);
    grads.at(1) = i1.ElementwiseMultiply(dout);
    return grads;
}

std::vector<DataObject> MultiplicationExecutor::DifferentiateMatrixMultiplication(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Mat(dout.ToMatrix() * (i2.ToMatrix().transpose()));
    grads.at(1) = Mat((i1.ToMatrix().transpose()) * dout.ToMatrix());
    return grads;
}

Multiplication::Multiplication(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2): Node({i1, i2}) {
    RegisterDifferentiableExecutor(std::make_shared<MultiplicationExecutor>(_executor));
}

std::shared_ptr<Multiplication> Multiply(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return std::shared_ptr<Multiplication>(new Multiplication(i1, i2));
}

std::shared_ptr<Multiplication> operator*(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Multiply(i1, i2);
}
