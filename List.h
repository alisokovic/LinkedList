#ifndef LIST_H
#define LIST_H

#include "Node.h"


class List
{
public:
    
    // Consturctors

    List();
    List(const List& rhs);
    List(const char* fName);
    List(long long num);
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
    void toFile(const char* fName) const;
    void toFileR(const char* fName);
    void fromFile(const char* fName);
    void removeOdds();
    bool isAscending() const;
    void grow2();
    void growNodeByNode(const int& times);
    void numToList(long long num);


private:
    
    Node* dummyHead;

    
    // Functions created for simplicity

    Node* getNode(const int& index);
    int getIndex(const Node* pFind) const;
};



#include "List.cpp"

#endif