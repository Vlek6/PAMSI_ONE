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
  LinkedList list = LinkedList();
  // list.insertNode("jeden");
  // list.insertNode("dwa");
  // list.insertNode("trzy");

  // list.insertNode("cztery");
  // list.insertNode("piencset");
  // list.insertNode("szesc");
  // list.printLinkedList();
  // std::cout << "Losowanko" << std::endl;
  // list.shuffleIds();
  // list.printLinkedList();
  std::string txt = "Lorem ipsum guacamole tesla haha awokdao robin hood kradl jablka";
  list.messageCut(txt);
  list.printLinkedList();
  list.shuffleIds();
  std::cout << "shuffle" << std::endl;
  list.printLinkedList();
  list.sortList();
  std::cout << " - sort - " << std::endl;
  list.printLinkedList();
  return 0;
}

