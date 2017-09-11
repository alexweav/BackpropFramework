#ifndef SRC_DATA_INITIALIZERS_CONSTANT_H_
#define SRC_DATA_INITIALIZERS_CONSTANT_H_

#include "Data/IInitializer.h"

namespace Initializers {
    
    class ConstantInitializer : public IInitializer {
     public:
        ConstantInitializer(float value);
        float GetValue();
        DataObject Initialize(std::initializer_list<int64_t> shape);

     private:
        float _value;
    };

    DataObject Constant(float);
    DataObject Constant(int64_t, int64_t, float);
    DataObject Constant(std::initializer_list<int64_t>, float);
}

#endif  // SRC_DATA_INITIALIZERS_CONSTANT_H_
