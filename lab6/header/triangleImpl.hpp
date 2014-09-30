#ifndef TRIANGLE_IMPL_H_
#define TRIANGLE_IMPL_H_

#include <iostream>

template <class T>
shapelab::Triangle<T>::Triangle(T h, T w): Shape<T>(), _height(h), _width(w) {
	std::cout << "Making a triangle!" << std::endl;
}

template <class T>
shapelab::Triangle<T>::~Triangle() {
	std::cout << "Destroying a triangle!" << std::endl;
}

template <class T>
void shapelab::Triangle<T>::printName() {
  std::cout << "Triangle" << std::endl;
}

template <class T>
void shapelab::Triangle<T>::drawImpl() {
	for(T h = 0; h < _height; ++h) {
		T current_width = static_cast<double>( h ) / _height * _width;
		current_width = std::max(static_cast<T>(1), current_width);
		for(T w = 0; w < current_width; ++w) {
			std::cout << "X";
		}
		std::cout << std::endl;
	}
}

template <class T>
std::string shapelab::Triangle<T>::name() {
	return "Triangle";
}
#endif // TRIANGLE_IMPL_H_
