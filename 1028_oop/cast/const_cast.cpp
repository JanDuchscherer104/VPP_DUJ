//
// Created by Jan Duchscherer on 17.11.22.
//
#include <iostream>

class Foo {
    int x = 0;
    Foo* pF = nullptr;

  public:
    void foo() const {
        const_cast<Foo*>(this)->x = 42;
        const_cast<Foo*>(this)->pF = new Foo();
        std::cout << "x = " << x << std::endl;
        std::cout << "pf = " << pF << std::endl;
    }
};


int main() {
    Foo f;
    f.foo();
    return 0;
}
