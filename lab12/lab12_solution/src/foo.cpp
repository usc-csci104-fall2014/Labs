#include "foo.h"

Foo::Foo()
{
	myBar = new Bar();
}
	
Foo::Foo(Bar b)
{
	myBar = &b;
}

Foo::~Foo()
{
	if(myBar != nullptr)
		delete myBar;
}

Bar Foo::getBar()
{
	return *myBar;
}

char Foo::doFoo(char a)
{
	return a+1;
}