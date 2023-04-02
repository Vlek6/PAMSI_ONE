// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#include "node.hpp"
#endif

#include <iostream>
using namespace std;
#include "node.hpp"

int main() {
  cout << "It's been a long time";
  Node* exm = new Node();
  Node* exm_val = new Node("sialala");

  cout << exm->data << endl << exm_val->data << endl;


  return 0;
}
