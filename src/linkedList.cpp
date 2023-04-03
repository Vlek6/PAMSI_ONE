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
    if (this->returnListLength() <= input_id)
    {
        throw std::logic_error("List out of index!");
        exit(1);
    }
    else
    {
        // std::cout << "Input ID: " << input_id << std::endl;
        while (temp->id != input_id)
        {
            temp = temp->next_node;
        }
        Node *swapped = new Node;
        swapped = temp->next_node;
        temp->next_node = insert_node;
        insert_node->next_node = swapped;
    }
    this->beamIds();
}

void LinkedList::deleteSpecificNode(int delete_id)
{
    Node *temp = head;
    assert(delete_id >= 0);
    // TODO: tutaj zrobić asercję i sprawdzić czy poprawnie myślę
    if (this->returnListLength() < delete_id)
    {
        throw std::logic_error("List out of index!");
        exit(1);
    }
    else
    {
        while (temp->id != delete_id)
        {
            temp = temp->next_node;
        }
        Node *to_delete_node = new Node;
        to_delete_node = temp->next_node;
        temp->next_node = to_delete_node->next_node;
        delete to_delete_node;
        this->beamIds();
    }
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

void LinkedList::shuffleIds()
{
    int list_length = this->returnListLength();
    std::cout << list_length << std::endl;

    for (int i = 0; i < list_length; i++)
    {
        Node *tmp1 = head;
        Node *tmp2 = head;
        int n1 = rand() % list_length;
        int n2 = rand() % list_length;

        for (int j = 0; j < n1; j++)
        {
            tmp1 = tmp1->next_node;
        }
        for (int j = 0; j < n2; j++)
        {
            tmp2 = tmp2->next_node;
        }

        std::string tmp = tmp1->data;
        int id_tmp = tmp1->id;
        tmp1->data = tmp2->data;
        tmp1->id = tmp2->id;
        tmp2->data = tmp;
        tmp2->id = id_tmp;
    }
}

void LinkedList::messageCut(std::string input_message)
{
    int i = 0;
    int j = 0;
    while (input_message[i] != '\0')
    {
        int n = rand() % 6 + 3;
        char *particle = new char[n];
        for (j = 0; j < n - 1; j++)
        {
            particle[j] = input_message[i];
            i++;
        }
        particle[j] = '\0';
        this->insertNode(particle);
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
            std::cout << temp->id << ":" << temp->data << " ";
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
