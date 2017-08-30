#include "Addition.h"

using namespace std;

Addition::Addition(Node* i1, Node* i2): Node({i1, i2}, true) { }

DataObject Addition::Forward(const vector<DataObject>& inputs) const {
    return inputs.at(0).Add(inputs.at(1));
}

vector<DataObject> Addition::Backward(const vector<DataObject>& prevInputs) const {
    return HandleBackward(prevInputs.at(0), prevInputs.at(1));
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
