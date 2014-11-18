#include "foo.h"
#include "bar.h"
#include "gtest/gtest.h"

// The fixture for testing class.
class FooTest: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	FooTest()
	{
		// You can do set-up work for each test here.
		b = new Bar(3);
	}

	virtual ~FooTest()
	{
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
		b = new Bar(4);
	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
		delete b;
	}

	// Objects declared here can be used by all tests in the test case.
	Bar * b;
};

TEST_F(FooTest, Get)
{
	EXPECT_EQ(4, b->getVal());
}

