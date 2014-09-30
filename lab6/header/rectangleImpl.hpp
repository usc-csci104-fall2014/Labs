#ifndef RECTANGLE_IMPL_H_
#define RECTANGLE_IMPL_H_

#include <iostream>

template <class T>
shapelab::Rectangle<T>::Rectangle(T h, T w): Shape<T>(), _height(h), _width(w) {
	std::cout << "Making a rectangle!" << std::endl;
}

template <class T>
shapelab::Rectangle<T>::~Rectangle() {
	std::cout << "Destroying a rectangle!" << std::endl;
}

template <class T>
void shapelab::Rectangle<T>::printName() {
	  std::cout << "Rectangle" << std::endl;
}

template <class T>
void shapelab::Rectangle<T>::drawImpl() {
	for( T h = 0; h < _height; ++h ) {
		for( T w = 0; w < _width; ++w ) {
			std::cout << "X";
		}
		std::cout << std::endl;
	}
}

template <class T>
T shapelab::Rectangle<T>::area() {
	return _height * _width;
}

template <class T>
std::string shapelab::Rectangle<T>::name() {
	return "Rectangle";
}

#endif // RECTANGLE_IMPL_H_

