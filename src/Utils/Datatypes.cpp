#include "Datatypes.h"
#include <iostream>

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

DataObject::DataObject(const MatrixXf& matrix)
            : _dimension(2),
              _shape({matrix.rows(), matrix.cols()}) {
    this->_kind = DataKind::MATRIX;
    this->_matrix = matrix;
}

void DataObject::AllocateScalar(float value) {
    this->_kind = DataKind::SCALAR;
    MatrixXf valueMatrix(1, 1);
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

template<>
float DataObject::GetData<float>(void) const {
    return _matrix(0);
}

template<>
MatrixXf DataObject::GetData<MatrixXf>(void) const {
    return _matrix;
}

bool DataObject::operator==(const DataObject& other) {
    if (_kind != other.GetKind()) {
        return false;
    }
    return _matrix == other.GetData<MatrixXf>();
}

DataObject DataObject::Add(const DataObject& other) const {
    if (_dimension == 0 && other.Dim() == 0) {
        return Scalar(GetData<float>() + other.GetData<float>());
    }
    if (_dimension == other.Dim() && _shape == other.Shape()) {
        return Mat(GetData<MatrixXf>() + other.GetData<MatrixXf>());
    }
}

DataObject DataObject::ElementwiseMultiply(const DataObject& other) const {
    if (_dimension == 0 && other.Dim() == 0) {
        return Scalar(GetData<float>() * other.GetData<float>());
    }
    if (_dimension == other.Dim() && _shape == other.Shape()) {
        return Mat(GetData<MatrixXf>().cwiseProduct(other.GetData<MatrixXf>()));
    }
}

DataObject Scalar(float value) {
    DataObject result(value);
    return result;
}

DataObject Mat(const MatrixXf& matrix) {
    DataObject result(matrix);
    return result;
}
