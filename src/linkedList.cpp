#include "linkedList.hpp"
#include <assert.h>
/**
 * @brief Default constructor for Linked List object
 *
 */
LinkedList::LinkedList()
{
    head = nullptr;
    actual_id = 0;
};

void LinkedList::insertNode(std::string input_data)
{
    /**
     * @brief Create new Node object
     *
     */
    Node *new_node = new Node(input_data);

    /**
     * @brief New node as a first element when list is empty
     *
     */
    if (head == nullptr)
    {
        head = new_node;
        return;
    }
    // create temporary pointer to head node, to search for tail
    Node *tmp = head;
    while (tmp->next_node != nullptr)
    {
        tmp = tmp->next_node;
    }
    // after finding tail of the list, new Node is appended
    // pushing Node to an end of list
    tmp->next_node = new_node;
    this->beamIds();
};

void LinkedList::insertSpecificNode(std::string input_data, int input_id)
{
    Node *insert_node = new Node(input_data);

    assert(input_id >= 0);
    
    Node *temp = head;
    if (this->returnListLength() < input_id)
    {
        throw std::logic_error("List out of index!");
        exit(1);
    }
    else
    {
        // std::cout << "Input ID: " << input_id << std::endl;
        while (temp->id != input_id)
        {
            std::cout << temp->id << std::endl;
            temp = temp->next_node;
        }
        Node *swapped = new Node;
        swapped = temp->next_node;
        temp->next_node = insert_node;
        insert_node->next_node = swapped;
        this->printLinkedList();
    }
    this->beamIds();
}

void LinkedList::beamIds()
{
    uint id_counter = 0;
    Node *temp = new Node;
    temp = head;
    while (temp != nullptr)
    {
        temp->id = id_counter;
        ++id_counter;
        temp = temp->next_node;
    }
}

void LinkedList::printLinkedList()
{

    Node *temp = head;

    if (head == nullptr)
    {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    else
    {
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next_node;
        }
    }
}
int LinkedList::returnListLength()
{
    uint count = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next_node;
    }
    return count;
}

int LinkedList::returnCurrentId()
{
    return actual_id;
}

Node *LinkedList::returnHead()
{
    return head;
}
