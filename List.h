#ifndef LIST_H
#define LIST_H

#include "Node.h"


class List
{
public:
    List();

    Node* zeroth();
    const Node* zeroth() const;
    Node* first();
    const Node* first() const;

    bool isEmpty() const;
    void insert(const int& data, Node* p);

private:
    Node* dummyHead;
};



#include "List.cpp"

#endif