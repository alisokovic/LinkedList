#ifndef LIST_H
#define LIST_H

#include "Node.h"


class List
{
public:
    List();
    List(const List& rhs);

    Node* zeroth();
    const Node* zeroth() const;
    Node* first();
    const Node* first() const;

    bool isEmpty() const;
    void print() const;
    Node* find(const int& data);
    Node* findPrevious(const int& data);
    void insert(const int& data, Node* p);
    void remove(const int& data);
    void makeEmpty();

    List& operator=(const List& rhs);

private:
    Node* dummyHead;
};



#include "List.cpp"

#endif