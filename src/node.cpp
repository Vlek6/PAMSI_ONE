#include "node.hpp"
#include <iostream>

Node::Node()
{
    data = "";
    id = 0;
    next_node = nullptr;
};

Node::Node(std::string input_data)
{
    this->data = input_data;
    this->id = 0;
    this->next_node = nullptr;
};

void Node::printNode()
{
    std::cout << "--------" << std::endl
              << "Id: " << this->id << std::endl
              << "Data: " << this->data << std::endl
              << "next node: " << this->next_node << std::endl
              << "--------" << std::endl;
}