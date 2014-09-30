#ifndef SHAPE_IMPL_H_
#define SHAPE_IMPL_H_

#include <iostream>

template <class T>
int shapelab::Shape<T>::shape_id = 0;

template <class T>
shapelab::Shape<T>::Shape() {
	std::cout << "Making a shape!" << std::endl;
	shape_id++;
}

template <class T>
shapelab::Shape<T>::~Shape() {
	std::cout << "Destroying a shape!" << std::endl;
}

template <class T>
void shapelab::Shape<T>::draw() {
  std::cout << "---" << name() << "---" << std::endl;
  drawImpl();
  std::cout << "---" << area() << "---" << std::endl;
}

template <class T>
void shapelab::Shape<T>::printName() {
  std::cout << "Shape" << std::endl;
}


template <class T>
void shapelab::Shape<T>::drawImpl() {
	std::cout << "BaseClass No Implementation" << std::endl;
}

template <class T>
T shapelab::Shape<T>::area() {
	return -9999;
}

template <class T>
std::string shapelab::Shape<T>::name() {
	return "Shape Object";
}


#endif // SHAPE_IMPL_H_
