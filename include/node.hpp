#pragma once
#include <string>
#include <cmath>


struct Node{
    std::string data;
    int id;
    Node* next_node;

    Node();
    Node(std::string data);
};

class LinkedList {
    Node* head;

};

