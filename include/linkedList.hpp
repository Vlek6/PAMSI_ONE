#pragma once
#include <iostream>
#include <string>
#include "node.hpp"

class LinkedList {
        Node* head;
        int actual_id;
    public:
        LinkedList();
        void insertNode(std::string input_data);
        void insertSpecificNode(std::string input_data, int insert_id);
        void deleteSpecificNode(int delete_id);
        void beamIds();
        void printLinkedList();
        int returnListLength();
        int returnCurrentId();
        Node* returnHead();
};