#include "Datatypes.h"

DataObject::DataObject(void) : DataObject({}) { }

DataObject::DataObject(const std::initializer_list<uint32_t>& shape)
            : _dimension(shape.size()), 
              _shape(shape) { 
    if (shape.size() == 0) {
        this->_kind = DataKind::SCALAR;
        this->_scalar = 0.0;
    }            
}

DataObject::DataObject(float value) {
    this->_kind = DataKind::SCALAR;
    this->_scalar = value;
}

DataObject::DataObject(const MatrixXf& matrix) {
    this->_kind = DataKind::MATRIX;
    this->_matrix = matrix;
}

uint8_t DataObject::Dim(void) {
    return this->_dimension;
}

std::vector<uint32_t> DataObject::Shape(void) {
    return this->_shape;
}

DataKind DataObject::GetKind(void) const {
    return this->_kind;
}

template<>
float DataObject::GetData<float>(void) const {
    return this->_scalar;
}

template<>
MatrixXf DataObject::GetData<MatrixXf>(void) const {
    return this->_matrix;
}

bool DataObject::operator==(const DataObject& other) {
    if (this->_kind != other.GetKind()) {
        return false;
    }
    if (this->_kind == DataKind::SCALAR) {
        return this->_scalar == other.GetData<float>();
    } else {
        return this->_matrix == other.GetData<MatrixXf>();
    }
}

