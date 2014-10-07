#include "doublingarraylist.h"
#include "gtest/gtest.h"

// The fixture for testing class.
class ArrayTest: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	ArrayTest()
	{
		// You can do set-up work for each test here.
		a = NULL;
		s = 100;
	}

	virtual ~ArrayTest()
	{
		// You can do clean-up work that doesn't throw exceptions here.		
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp()
	{
		// Code here will be called immediately after the constructor (right
		// before each test).
		a = new DoublingArrayList<int>();
		for(int i = 0; i < s; ++i) a->insert(a->size(), i);
	}

	virtual void TearDown()
	{
		// Code here will be called immediately after each test (right
		// before the destructor).
		delete a;
		a = NULL;
	}

	// Objects declared here can be used by all tests in the test case.
	DoublingArrayList<int> * a;
	int s;
};

TEST_F(ArrayTest, Get)
{
	for(int i = 0; i < s; ++i) EXPECT_EQ(i, a->get(i));
}

TEST_F(ArrayTest, Set)
{
	for(int i = 0; i < s; ++i) 
	{
		a->set(i, -i);
		EXPECT_EQ(-i, a->get(i));
	}
}

//put the rest of your test cases here!

