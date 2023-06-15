#include <gtest/gtest.h>
#include "shared_ptr.hpp"

struct TestObject
{
  int value_;
  TestObject(int value) : value_(value){}
  TestObject(){};
  int multiplyValueByTwo()
  {
    return value_ *= 2;
  }
};

TEST(shared_ptrTest, ArrowOperatorTest)
{
  my::shared_ptr<TestObject> shared_ptr(new TestObject{20});
  auto expected = 40;

  EXPECT_EQ(expected, shared_ptr->multiplyValueByTwo());
}