#ifndef LIST_H
#define LIST_H

#include "Node.h"


class List
{
public:
    
    // Consturctors

    List();
    List(const List& rhs);
    ~List();

    
    // Member functions

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

    void appendItem(const int& data);
    int getSize() const;
    void inserAt(const int& index, const int& item);
    void removeAt(const int& index);


private:
    
    Node* dummyHead;

    
    // Functions created for simplicity

    Node* getNode(const int& index);
    int getIndex(const Node* pFind) const;
};



#include "List.cpp"

#endif