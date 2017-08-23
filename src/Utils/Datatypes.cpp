#include "Datatypes.h"

DataObject::DataObject(const std::initializer_list<uint32_t>& shape)
            : _dimension(shape.size()), 
              _shape(shape) { }

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

DataKind DataObject::GetKind(void) {
    return this->_kind;
}

template<>
float DataObject::GetData<float>(void) {
    return this->_scalar;
}

template<>
MatrixXf DataObject::GetData<MatrixXf>(void) {
    return this->_matrix;
}

