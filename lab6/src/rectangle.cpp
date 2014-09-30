#include "rectangle.h"

int main() {
	//Create a set of rectangles
	shapelab::Rectangle<int> rec1(3, 4);
	shapelab::Rectangle<int> rec2(5, 6);
	
	//Draw the rectangles
	rec1.draw();
	rec2.draw();

	return(0);
}
