#ifndef NODE_H
#define NODE_H


class Node
{
public:

    Node(const int& e = int{} , Node* n = nullptr)
    : element{e} , next{n}  { }

    int element;
    Node* next;

private:

};


#endif