#include <iostream>
#include "List.h"

// Constructors

List::List()
{
    dummyHead = new Node{};
}


List::List(const List& rhs)
{
    dummyHead = new Node{};
    *this = rhs;
}


List::~List()
{
    makeEmpty();
    delete dummyHead;
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


List& List::operator=(const List& rhs)
{
    if (this != &rhs)
    {
        makeEmpty();
        const Node* r{rhs.first()};
        Node* p{zeroth()};
        while(r)
        {
            insert(r->element,p);
            r = r->next;
            p = p->next;
        }
    }
    return *this;
}


void List::appendItem(const int& data)
{
    insert(data,getNode(getSize()));
}


int List::getSize() const
{
    return getIndex(nullptr) - 1;
}


void List::inserAt(const int& index, const int& item)
{
    insert(item,getNode(index - 1));
}


void List::removeAt(const int& index)
{
    Node* tmp{ getNode(index) };
    getNode(index - 1)->next = tmp->next;
    delete tmp;
}


// Functions for simplicity

Node* List::getNode(const int& index)
{
    Node* p{zeroth()};
    for (int count{1} ; count <= index ; ++count)
        p = p->next;

    return p;
}


int List::getIndex(const Node* pFind) const
{
    if (pFind == dummyHead)
        return 0;
    
    int index{1};
    const Node* p{first()};
    while (p != pFind)
    {
        ++index;
        p = p->next;
    }
    return index;
}