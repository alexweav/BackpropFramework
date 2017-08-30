#include "Addition.h"

using namespace std;

Addition::Addition(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Addition::Forward(const vector<DataObject>& inputs) const {
    return HandleAdd(inputs.at(0), inputs.at(1));
}

vector<DataObject> Addition::Backward(const vector<DataObject>& prevInputs) const {
    return HandleBackward(prevInputs.at(0), prevInputs.at(1));
}

DataObject Addition::HandleAdd(const DataObject& i1, const DataObject& i2) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return AddScalars(i1, i2);
    }
    if (i1.Dim() == i2.Dim() && i1.Shape() == i2.Shape()) {
        return AddMatrices(i1, i2);
    }
    //error
}

DataObject Addition::AddScalars(const DataObject& i1, const DataObject& i2) const {
    return Scalar(i1.GetData<float>() + i2.GetData<float>());
}

DataObject Addition::AddMatrices(const DataObject& i1, const DataObject& i2) const {
    return Mat(i1.GetData<MatrixXf>() + i2.GetData<MatrixXf>());
}

vector<DataObject> Addition::HandleBackward(const DataObject& i1, const DataObject& i2) const {
    if (i1.Dim() == 0 && i2.Dim() == 0) {
        return DifferentiateScalarAddition(i1, i2);
    }
}

vector<DataObject> Addition::DifferentiateScalarAddition(const DataObject& i1, const DataObject& i2) const {
    vector<DataObject> grads(this->_arity);
    grads.at(0) = Scalar(1.0);
    grads.at(1) = Scalar(1.0);
    return grads;
}
