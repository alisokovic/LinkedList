#include "List.h"

// Constructors

List::List()
{
    dummyHead = new Node{};
}



// Member Functions

Node* List::zeroth()
{
    return dummyHead;
}


const Node* List::zeroth() const
{
    return dummyHead;
}


Node* List::first()
{
    return dummyHead->next;
}


const Node* List::first() const
{
    return dummyHead->next;
}


bool List::isEmpty() const
{
    return (first() == nullptr);
}


void List::insert(const int& data, Node* p)
{
    Node* newNode = new Node{data,p->next};
    p->next = newNode;
}