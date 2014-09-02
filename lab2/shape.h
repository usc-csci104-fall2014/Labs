#pragma once

#include <string>

class shape
{
private:
  std::string _name;
  
public:
  shape();
  std::string name() const;
};
