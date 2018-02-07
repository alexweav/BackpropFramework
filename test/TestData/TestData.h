#ifndef TEST_TESTDATA_TESTDATA_H_
#define TEST_TESTDATA_TESTDATA_H_

#include <vector>

#include "gtest/gtest.h"
#include "Data/Datatypes.h"
#include "Data/Initializers/Ones.h"
#include "Data/Initializers/Zeros.h"
#include "Data/Initializers/Constant.h"

class DataPropertyTest : public ::testing::Test {
 protected:
    virtual void SetUp() { }
};

#endif  // TEST_TESTDATA_TESTDATA_H_
