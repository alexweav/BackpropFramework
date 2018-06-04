#include "Operations/Arithmetic/Addition.h"

DataObject AdditionExecutor::operator()(const ExecutionContext& context) const {
    return context.Inputs().at(0).Add(context.Inputs().at(1));
}

std::vector<DataObject> AdditionExecutor::Differentiate(const ExecutionContext& context) const {
    return HandleBackward(context.Inputs().at(0), context.Inputs().at(1), context.DownstreamGradient());
}

std::vector<DataObject> AdditionExecutor::HandleBackward(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarAddition(i1, i2, dout);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape() == i2.Shape()) {
        return DifferentiateMatrixAddition(i1, i2, dout);
    }
}

std::vector<DataObject> AdditionExecutor::DifferentiateScalarAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    grads.at(0) = Scalar(1.0).ElementwiseMultiply(dout);
    grads.at(1) = Scalar(1.0).ElementwiseMultiply(dout);
    return grads;
}

std::vector<DataObject> AdditionExecutor::DifferentiateMatrixAddition(const DataObject& i1, const DataObject& i2, const DataObject& dout) const {
    std::vector<DataObject> grads(2);
    Eigen::MatrixXf mat = Eigen::MatrixXf::Constant(i1.ToMatrix().rows(), i1.ToMatrix().cols(), 1.0);
    grads.at(0) = Mat(mat).ElementwiseMultiply(dout);
    grads.at(1) = Mat(mat).ElementwiseMultiply(dout);
    return grads;
}

Addition::Addition(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2): Node({i1, i2}) {
    RegisterDifferentiableExecutor(std::make_shared<AdditionExecutor>(_executor));
}

std::shared_ptr<Addition> Add(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    std::shared_ptr<Addition> ptr(new Addition(i1, i2));
    return ptr;
}

std::shared_ptr<Addition> operator+(const IChannelProviderPtr& i1, const IChannelProviderPtr& i2) {
    return Add(i1, i2);
}
