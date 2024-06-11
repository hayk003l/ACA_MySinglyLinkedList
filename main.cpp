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
    
    obj.print();
    
    return 0;
}