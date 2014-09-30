#include "triangle.h"

int main() {
	//Create a set of triangles
	shapelab::Triangle<int> tri1(3, 4);
	shapelab::Triangle<int> tri2(8, 7);
	
	//Draw the triangles
	tri1.draw();
	tri2.draw();

	return(0);
}
