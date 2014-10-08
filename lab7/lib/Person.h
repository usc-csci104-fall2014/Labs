#include <string>

#ifndef PERSON_H
#define PERSON_H

struct Person {
  std::string s;
  Person* endorsedBy;

  Person(std::string s) : s(s), endorsedBy(NULL) {};
};


#endif
