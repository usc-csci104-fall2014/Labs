#include <iostream>
#include "Person.h"
#include "EndorsementChecker.h"


int main() {
  Person* p = new Person("Peter");
  Person* r = new Person("Ruyan");
  Person* k = new Person("Kempe");
  Person* j = new Person("Janice");
  Person* d = new Person("Douglass");

  p->endorsedBy = r;
  r->endorsedBy = k;
  k->endorsedBy = j;
  j->endorsedBy = d;
  d->endorsedBy = p;

  std::cout << EndorsementCycleChecker::cycleExists(p) << std::endl;

  /* Endorsement* temp = p; */
  /* while(temp != NULL) { */
  /*   std::cout << temp->s << std::endl; */
  /*   temp = temp->endorsedBy; */
  /* } */

}
