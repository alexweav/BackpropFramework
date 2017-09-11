#ifndef SRC_DATA_INITIALIZERS_ONES_H_
#define SRC_DATA_INITIALIZERS_ONES_H_

#include "Data/IInitializer.h"

namespace Initializers {

    class OnesInitializer : public IInitializer {
     public:
        DataObject Initialize(std::initializer_list<int64_t> shape);
    };

    DataObject Ones(void);
    DataObject Ones(int64_t, int64_t);
    DataObject Ones(std::initializer_list<int64_t>);
}

#endif  // SRC_DATA_INITIALIZERS_ONES_H_
