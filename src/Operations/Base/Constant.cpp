#include "src/Operations/Base/Constant.h"
#include <vector>
#include <memory>

Constant::Constant(const float value): Constant(Scalar(value)) { }

Constant::Constant(const Eigen::MatrixXf& value): Constant(Mat(value)) { }

Constant::Constant(const DataObject& value): Node({}, true) {
    _value = value;
}

DataObject Constant::Forward(const std::vector<DataObject>& inputs) const {
    return _value;
}

std::vector<DataObject> Constant::Backward(const std::vector<DataObject>& prevInputs, const DataObject& dout) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

DataObject Constant::getValue() {
    return _value;
}

std::shared_ptr<Constant> Value(float value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}

std::shared_ptr<Constant> Value(const Eigen::MatrixXf& value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}

std::shared_ptr<Constant> Value(const DataObject& value) {
    std::shared_ptr<Constant> ptr(new Constant(value));
    return ptr;
}
