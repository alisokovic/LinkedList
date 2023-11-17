#include "List.h"
#include <fstream>
#include <iostream>


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


List::List(const char* fName)
{
    dummyHead = new Node{};
    fromFile(fName);
}


List::List(long long num)
{
    dummyHead = new Node{};
    numToList(num);
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


void List::toFile(const char* fName) const
{
    std::ofstream outputFile;
    outputFile.open(fName);
    const Node* p{ first() };
    while (p)
    {
        outputFile << p->element << ' ';
        if (getIndex(p) % 10 == 0)
            outputFile << '\n';
        p = p->next;
    }
    outputFile.close();
}


void List::toFileR(const char* fName)
{
    std::ofstream outputFile;
    outputFile.open(fName);
    for (int index{ getSize() }, count{ 1 }; index >= 1; --index, ++count)
    {
        outputFile << getNode(index)->element << ' ';
        if (count % 10 == 0)
            outputFile << '\n';
    }
    outputFile.close();
}


void List::fromFile(const char* fName)
{
    std::ifstream inputFile;
    inputFile.open(fName);
    if (inputFile)
    {
        while (inputFile)
        {
            int element{};
            inputFile >> element;
            appendItem(element);
        }
        removeAt(getSize());
    }
    else
        std::cout << "No such file in the directory\n";
    inputFile.close();
}


void List::removeOdds()
{
    for (int index{ 1 }; index <= getSize(); ++index)
    {
        if (getNode(index)->element % 2 != 0)
        {
            removeAt(index);
            --index;
        }
    }
}


bool List::isAscending() const
{
    const Node* p{ first() };
    while (p->next)
    {
        if (p->element >= p->next->element)
            return false;

        p = p->next;
    }
    return true;
}


void List::grow2()
{
    int size{ getSize() };
    for (int index{ 1 }; index <= size; ++index)
    {
        appendItem(getNode(index)->element);
    }
}


void List::growNodeByNode(const int& times)
{
    if (times <= 0)
        return;
    else
    {
        for (int index{ 1 }; index <= getSize(); index += times)
        {
            int element{ getNode(index)->element };
            for (int count{ index }; count < (index + times - 1); ++count)
            {
                inserAt(count + 1, element);
            }
        }
    }
}


void List::numToList(long long num)
{
    makeEmpty();

    do
    {
        int element{ static_cast<int>(num % 10) };
        insert(element, zeroth());

    } while (num /= 10);
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