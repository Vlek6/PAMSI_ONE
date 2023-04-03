// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest/doctest.h"
#include "node.hpp"
#include "linkedList.hpp"
#endif

#include <iostream>
using namespace std;
#include "node.hpp"
#include "linkedList.hpp"\

int main() {
  return 0;
}
