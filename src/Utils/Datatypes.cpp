#include "Datatypes.h"

DataObject::DataObject(float value) {
    this->_kind = DataKind::SCALAR;
    this->_scalar = value;
}

DataObject::DataObject(std::shared_ptr<MatrixXf> matrix) {
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
std::shared_ptr<MatrixXf> DataObject::GetData<std::shared_ptr<MatrixXf>>(void) {
    return this->_matrix;
}
