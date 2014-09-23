#include "B.h"


B::B(void)
{
	this->mine = 0;
}

B::B(int a)
{
	this->mine = a;
}


B::~B(void)
{
}

int B::sumPone (int a, int b)
{
	return a + b + mine;
}
