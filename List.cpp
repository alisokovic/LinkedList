#include <iostream>
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


void List::print() const
{
    const Node* p{first()};
    int count{};
    while (p)
    {
        ++count;
        std::cout << p->element << ' ';
        if (count % 15 == 0)
            std::cout << '\n';
        p = p->next;
    }
    if (isEmpty())
        std::cout << "The list is empty!";
    std::cout << '\n';
}


Node* List::find(const int& data)
{
    Node* p{first()};
    while (p)
    {
        if (p->element == data)
            return p;
        p = p->next;
    }
    return nullptr;
}


Node* List::findPrevious(const int& data)
{
    Node* p{zeroth()};
    while (p->next)
    {
        if (p->next->element == data)
            return p;
        p = p->next;
    }
    return nullptr;
}


void List::insert(const int& data, Node* p)
{
    Node* newNode = new Node{data,p->next};
    p->next = newNode;
}


void List::remove(const int& data)
{
    Node* tmp{find(data)};
    findPrevious(data)->next = tmp->next;
    delete tmp;
}


void List::makeEmpty()
{
    while (!isEmpty())
    {
        remove(first()->element);
    }
}