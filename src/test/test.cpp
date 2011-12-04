#include <gtest/gtest.h>

namespace {

class GenericTest : public ::testing::Test {
 protected:

  GenericTest() {}

  virtual ~GenericTest() {}

  virtual void SetUp() {}

  virtual void TearDown() {}
};

TEST_F(GenericTest, DoesSomething) {
  ASSERT_EQ(0.,0.);
}

}
