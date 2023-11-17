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

private:
    Node* dummyHead;
};



#include "List.cpp"

#endif