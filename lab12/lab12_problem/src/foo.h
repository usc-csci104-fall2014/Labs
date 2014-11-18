#pragma once

#include "bar.h"

class Foo
{
public: 
	Foo();
	Foo(Bar b);
	~Foo();
	Bar getBar();
	char doFoo(char a);

private:
	Bar * myBar;
};