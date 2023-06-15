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

TEST(shared_ptrTest, DereferenceOperatorTest)
{
  my::shared_ptr<TestObject> shared_ptr(new TestObject(20));
  TestObject& dereferencedObj = *shared_ptr;
  auto result = dereferencedObj.multiplyValueByTwo();
  auto expected = 40;

  EXPECT_EQ(expected, result);
}

TEST(shared_ptrTest, FunctionGetExpectedNotNullTest)
{
  my::shared_ptr<TestObject> shared_ptr(new TestObject(20));
  TestObject* rawPtr = shared_ptr.get();
  auto expected = nullptr;

  EXPECT_NE(expected, rawPtr);
}

TEST(shared_ptrTest, FunctionGetExpectedValueTest)
{
  my::shared_ptr<TestObject> shared_ptr(new TestObject(20));
  TestObject* rawPtr = shared_ptr.get();
  auto expected = 40;
  auto result = rawPtr->multiplyValueByTwo();

  EXPECT_EQ(expected, result);
}

TEST(shared_ptrTest, DefaultConstructorTest)
{
  my::shared_ptr<TestObject> shared_ptr;
  auto value = shared_ptr.get();
  auto expected = nullptr;

  EXPECT_EQ(expected, value);
}

TEST(shared_ptrTest, FunctionUseCountReturnOneTest)
{
  my::shared_ptr<TestObject> shared_ptr(new TestObject(20));
  long counter = shared_ptr.use_count();
  auto expected = 1;

  EXPECT_EQ(expected, counter);
}