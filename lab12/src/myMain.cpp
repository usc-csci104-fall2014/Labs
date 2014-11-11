// myMain.cpp
#include <iostream>

// library classes
#include "linkedlist.h"
#include "arraylist.h"

#include "foo.h"
#include "bar.h"

using namespace std;

int main ()
{
	LinkedList<int> * l = new LinkedList<int>();
	l->insert(0, 0);
	Foo * f = new Foo();
	cout <<"The value of Foo's Bar is: ";
	cout << f->getBar().getVal() <<endl;
	delete f;
	delete l;
}