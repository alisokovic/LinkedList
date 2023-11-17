#include "List.h"
#include <iostream>




int main()
{
    List myList{};

    Node* p{myList.zeroth()};
    for (int index{1} ; index <= 250 ; ++index)
    {
        myList.insert(index,p);
        p = p->next;
    }


    myList.print();

    


    return 0;
}