#include "bar.h"

Bar::Bar()
{
	value = 0;
}
	
Bar::Bar(int i)
{
	value = i;
}

int Bar::getVal()
{
	return value;
}