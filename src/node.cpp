#include "node.hpp"

Node::Node() {
    data = "";
    id = 0;
    next_node = nullptr;
};

Node::Node(std::string input_data) {
    this->data = input_data;
    this->id = 0;
    this->next_node = nullptr;
};