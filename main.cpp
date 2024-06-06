#include <iostream>
#include "List.hpp"

int main() {

    myStl::List<int> obj;
    obj.push_front(4);
    obj.push_back(3);
    obj.push_front(2);
    obj.push_back(1);
    obj.insert(2,2);
    obj.display();
    
    if (!obj.detectLoop()) {
        std::cout << "Cycle" << std::endl;
    }
    else {
        std::cout << "Not a cycle" << std::endl;
    }

    obj.swapList();
    obj.display();

    return 0;
}