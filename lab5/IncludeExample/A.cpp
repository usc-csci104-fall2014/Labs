#include "A.h"
#include "B.h"

A::A(void)
{
	this->Astring = "_ string";
	m_b = *(new B(0));
}

A::A(int length, char c)
{
	m_b = *( new B(2));
	this->Astring = new char[10 + length];

	char temp[9] = "_ string";
	for (int i = 0; i < 9; i++)
		this->Astring[i] = temp[i];
	this->Astring[0] = c + m_b.sumPone(0, 0);
}


A::~A(void)
{
	delete this->Astring;
}
