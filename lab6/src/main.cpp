#include "shape.h"
#include "rectangle.h"
#include "triangle.h"
#include <iostream>

template <class T>
void printName(shapelab::Shape<T> *s) {
	s -> printName();
}

int main() {
	//Create a set of pointers to rectangles
	shapelab::Rectangle<int> *r1 = new shapelab::Rectangle<int>(3, 4);
	shapelab::Rectangle<int> *r2 = new shapelab::Rectangle<int>(5, 6);

	//Create a set of pointers to rectangles
	shapelab::Triangle<int> *t1 = new shapelab::Triangle<int>(8, 7);
	shapelab::Triangle<int> *t2 = new shapelab::Triangle<int>(3, 4);
	
	printName(r1);
	printName(r2);
	printName(t1);
	printName(t2);
	
	return(0);
}
