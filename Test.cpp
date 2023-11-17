#include "List.h"
#include <iostream>




int main()
{
    List myList{};

    Node* p{myList.zeroth()};
    for (int index{1} ; index <= 10 ; ++index)
    {
        myList.insert(index,p);
        p = p->next;
    }

    myList.print();

    myList.remove(5);

    myList.print();

    


    return 0;
}