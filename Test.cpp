#include "List.h"
#include <iostream>




int main()
{
    List myList{};

    std::cout << std::boolalpha << myList.isEmpty() << '\n';

    myList.insert(15,myList.zeroth());

    std::cout << std::boolalpha << myList.isEmpty() << '\n';

    


    return 0;
}