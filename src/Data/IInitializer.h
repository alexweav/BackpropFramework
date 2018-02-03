#ifndef SRC_DATA_IINITIALIZER_H_
#define SRC_DATA_IINITIALIZER_H_

#include "Data/Datatypes.h"

namespace Initializers {

class IInitializer {
 public:
    virtual DataObject Initialize(std::initializer_list<int64_t>) = 0;
};

}   // namespace Initializers

#endif  // SRC_DATA_IINITIALIZER_H_
