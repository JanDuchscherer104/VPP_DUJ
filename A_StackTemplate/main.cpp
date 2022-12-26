#include <iostream>
#include "stack.hpp"

int main() {
    Stack<int> s1{3};
    std::cout << std::boolalpha << s1.empty() << std::endl;
    for(int i = 0; i < 10; ++i) {
        s1.push(i);
        std::cout << "Peek: " << s1.peek() << std::endl;
    }
    std::cout << "Pop: " << s1.pop() << std::endl;
    std::cout << s1 << std::endl;
    return 0;
}
