#include "doctest/doctest.h"
#include "linkedList.hpp"
#include "node.hpp"
#include <string>

TEST_CASE("List constructor test")
{
    LinkedList new_list = LinkedList();
    CHECK( new_list.returnHead() == nullptr);
}
TEST_CASE("List print test")
{
    LinkedList test_list = LinkedList();
    test_list.insertNode("FirstNodeAppend");
    test_list.insertNode("SecNodeAppend");
    Node* tmp = test_list.returnHead();
    int count = 0;
    while(tmp != nullptr)
    {
        tmp = tmp->next_node;
        count++;
    }
    CHECK(count == 2);
}

TEST_CASE("returnListLength test")
{
    LinkedList test_list = LinkedList();
    CHECK(test_list.returnListLength() == 0);
    test_list.insertNode("FirstNodeAppend");
    CHECK(test_list.returnListLength() == 1);
    test_list.insertNode("SecNodeAppend");
    CHECK(test_list.returnListLength() == 2);
}
