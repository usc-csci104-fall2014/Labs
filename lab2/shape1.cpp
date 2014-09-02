#include <iostream>
#include "shape.h"

int main() {
	int i;
	std::cin >> i;
	shape * s = new shape;
	std::cout << s->name() << std::endl;
	return 0;
}
