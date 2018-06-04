#ifndef TEST_TESTCORE_FAKENONDIFFERENTIABLECONSTANT_H_
#define TEST_TESTCORE_FAKENONDIFFERENTIABLECONSTANT_H_

#include "Core/ExecutionContext.h"
#include "Core/IExecutor.h"
#include "Core/Node.h"
#include "Data/Datatypes.h"

class FakeNonDifferentiableConstantExecutor: public IExecutor {
 public:
    FakeNonDifferentiableConstantExecutor(float value);
    DataObject operator() (const ExecutionContext& context) const;

 protected:
    DataObject _value;
};

class FakeNonDifferentiableConstant: public Node {
 public:
    FakeNonDifferentiableConstant(float value);
};

#endif  // TEST_TESTCORE_FAKENONDIFFERENTIABLECONSTANT_H_
