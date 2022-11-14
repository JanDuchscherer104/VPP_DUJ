#include <iostream>

#include "fraesung.h"
#include "komponentenList.h"

int main() {
    Komponente k0;
    std::cout << k0 << std::endl;
    Komponente k1{3.0, 4.0};
    std::cout << k1 << std::endl;
    Bohrung b0;
    std::cout << b0 << std::endl;
    Bohrung b1{1.0, 2.0, 8.0};
    std::cout << b1 << std::endl;
    Komponente* kp;
    Fraesung f0{17.0, 6.0, 4.0, 10.0, 1.4};
    kp = &f0;
    std::cout << f0 << std::endl;
    // std::cout << *kp << std::endl;
    KomponentenList kl;
    kl.push_back(&k0);
    kl.push_back(&k1);
    kl.push_back(&b0);
    kl.push_back(&b1);
    kl.push_back(&f0);
    std::cout << "from loop\n";
    for (size_t i = 0; i < kl.size(); ++i) {
        std::cout << *kl.at(i)->k << std::endl;
    }
    kl.erase(3);
    for (size_t i = 0; i < kl.size(); ++i) {
        std::cout << *kl.at(i)->k << std::endl;
    }
    return 0;
}