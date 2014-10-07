#include "stack.h"
#include "gtest/gtest.h"

// The fixture for testing class
class StackTest: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	StackTest()
	{
		// You can do set-up work for each test here.
	}

	virtual ~StackTest()
	{
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests
	stack<int> s;
};

TEST_F(StackTest, OnePushPop)
{
  EXPECT_FALSE(true);//just to show you how it works, remove me
  ASSERT_FALSE(true);//just to show you how it works, remove me
  //fill in the code from the lab writeup here
}

TEST_F(StackTest, Scale)
{
	// Exercises the Xyz feature of Foo.
}

