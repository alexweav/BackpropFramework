#include "src/Data/Datatypes.h"

DataObject::DataObject(void) : DataObject({}) { }

DataObject::DataObject(const std::initializer_list<int64_t>& shape)
            : _dimension(shape.size()),
              _shape(shape) {
    if (shape.size() == 0) {
        AllocateScalar(0.0);
    }
}

DataObject::DataObject(float value)
            : _dimension(0),
              _shape({}) {
    AllocateScalar(value);
}

DataObject::DataObject(const Eigen::MatrixXf& matrix)
            : _dimension(2),
              _shape({matrix.rows(), matrix.cols()}) {
    this->_kind = DataKind::MATRIX;
    this->_matrix = matrix;
}

void DataObject::AllocateScalar(float value) {
    this->_kind = DataKind::SCALAR;
    Eigen::MatrixXf valueMatrix(1, 1);
    valueMatrix << value;
    _matrix = valueMatrix;
}

uint8_t DataObject::Dim(void) const {
    return _dimension;
}

std::vector<int64_t> DataObject::Shape(void) const {
    return _shape;
}

DataKind DataObject::GetKind(void) const {
    return _kind;
}

float DataObject::ToScalar(void) const {
    return _matrix(0);
}

Eigen::MatrixXf DataObject::ToMatrix(void) const {
    return _matrix;
}

bool DataObject::operator==(const DataObject& other) {
    if (_kind != other.GetKind()) {
        return false;
    }
    return _matrix == other.ToMatrix();
}

DataObject DataObject::Add(const DataObject& other) const {
    if (_dimension == 0 && other.Dim() == 0) {
        return Scalar(ToScalar() + other.ToScalar());
    }
    if (_dimension == other.Dim() && _shape == other.Shape()) {
        return Mat(ToMatrix() + other.ToMatrix());
    }
}

DataObject DataObject::ElementwiseMultiply(const DataObject& other) const {
    if (_dimension == 0 && other.Dim() == 0) {
        return Scalar(ToScalar() * other.ToScalar());
    }
    if (_dimension == other.Dim() && _shape == other.Shape()) {
        return Mat(ToMatrix().cwiseProduct(other.ToMatrix()));
    }
}

DataObject Scalar(float value) {
    DataObject result(value);
    return result;
}

DataObject Mat(const Eigen::MatrixXf& matrix) {
    DataObject result(matrix);
    return result;
}

