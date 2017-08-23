#include "Datatypes.h"

DataObject::DataObject(float value) {
    this->_kind = DataKind::SCALAR;
    this->_scalar = value;
}

DataObject::DataObject(MatrixXf* matrix) {
    this->_kind = DataKind::MATRIX;
    this->_matrix = matrix;
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
    return *(this->_matrix);
}

DataObject::~DataObject() {
    if (this->_kind == DataKind::MATRIX) {
        free(this->_matrix);
    }
}
