#include <vector>
#include "Data/Initializers/Constant.h"

namespace Initializers {

    ConstantInitializer::ConstantInitializer(float value):
        _value(value) { }

    float ConstantInitializer::GetValue() {
        return _value;
    }

    DataObject ConstantInitializer::Initialize(std::initializer_list<int64_t> shape) {
        if (shape.size() == 0) {
            return Scalar(_value);
        }
        std::vector<int64_t> vShape(shape);
        return Mat(Eigen::MatrixXf::Constant(vShape.at(0), vShape.at(1), _value));
    }

    DataObject Constant(float value) {
        return Constant({}, value);
    }

    DataObject Constant(int64_t rows, int64_t cols, float value) {
        return Constant({rows, cols}, value);
    }

    DataObject Constant(std::initializer_list<int64_t> shape, float value) {
        ConstantInitializer initializer(value);
        return initializer.Initialize(shape);
    }

}   // namespace Initializers
