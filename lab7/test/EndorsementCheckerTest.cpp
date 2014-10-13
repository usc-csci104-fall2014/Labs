#include "EndorsementChecker.h"
#include "Person.h"
#include "gtest/gtest.h"

// The fixture for testing class.
class EndorsementCheckerTest: public ::testing::Test
{
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	EndorsementCheckerTest()
	{
		// You can do set-up work for each test here.
	}

	virtual ~EndorsementCheckerTest()
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

	// Objects declared here can be used by all tests in the test case.
};

TEST(EndorsementCheckerTest, Cycle)
{
  Person* p = new Person("Peter");
  Person* r = new Person("Ruyan");
  Person* k = new Person("Kempe");
  Person* j = new Person("Janice");
  Person* d = new Person("Douglass");

  p->endorsedBy = r;
  r->endorsedBy = k;
  k->endorsedBy = j;
  j->endorsedBy = d;
  d->endorsedBy = p;

  /* EXPECT_FALSE(EndorsementCycleChecker::cycleExists(p)); */
}


