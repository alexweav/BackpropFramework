#ifndef SRC_DATA_INITIALIZERS_ZEROS_H_
#define SRC_DATA_INITIALIZERS_ZEROS_H_

#include "Data/IInitializer.h"

namespace Initializers {
    
    class ZeroInitializer : public IInitializer {
     public:
        DataObject Initialize(std::initializer_list<int64_t> shape);
    };

    DataObject Zeros(void);
    DataObject Zeros(int64_t, int64_t);
    DataObject Zeros(std::initializer_list<int64_t> shape);
}

#endif
