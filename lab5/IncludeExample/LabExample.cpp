// LabExample.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "A.h"
#include "B.h"
#define PRINTLN(a) std::cout << a << std::endl
#define PI 3.14159


int main(int argc, char* argv[])
{
	A * a = new A(3, '2');
	PRINTLN(a->Astring);
	B * b = new B(3);
	PRINTLN(b->sumPone(2, 1));
	PRINTLN(PI);
	int temp;
	std::cin >> temp; 
	return 0;
}

