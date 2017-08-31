#include "src/Operations/Base/Constant.h"
#include <vector>

Constant::Constant(const float value): Constant(Scalar(value)) { }

Constant::Constant(const Eigen::MatrixXf& value): Constant(Mat(value)) { }

Constant::Constant(const DataObject& value): Node({}, true) {
    _value = value;
}

DataObject Constant::Forward(const std::vector<DataObject>& inputs) const {
    return _value;
}

std::vector<DataObject> Constant::Backward(const std::vector<DataObject>& prevInputs) const {
    std::vector<DataObject> gradsOut;
    return gradsOut;
}

DataObject Constant::getValue() {
    return _value;
}
