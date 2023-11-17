#include "List.h"
#include <iostream>




int main()
{
    List list1{};

    Node* p1{list1.zeroth()};
    for (int index{1} ; index <= 10 ; ++index)
    {
        list1.insert(index,p1);
        p1 = p1->next;
    }


    list1.print();

    list1.removeAt(10);

    list1.print();


    return 0;
}