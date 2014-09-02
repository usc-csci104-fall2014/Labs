#include "shape.h"

shape::shape()
{
  _name = "Shape";
}

std::string shape::name() const
{
  return _name;
}
