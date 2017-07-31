#include <iostream>
#include "Operation.h"

using namespace std;

Operation::Operation(initializer_list<Node*> inputs, bool isDiff): Node(inputs, isDiff) { }

