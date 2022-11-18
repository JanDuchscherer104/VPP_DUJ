#include <iostream>

#include "fraesung.hpp"
#include "komponentenList.hpp"

int main() {
    Komponente k0;
    Komponente k1{3.0, 4.0};
    Bohrung b0;
    Bohrung b1{1.0, 2.0, 8.0};
    Komponente* kp;
    Fraesung f0{17.0, 6.0, 4.0, 10.0, 1.4};
    kp = &f0;
    // std::cout << *kp << std::endl;
    KomponentenList kl;
    kl.push_back(&k0);
    kl.push_back(&k1);
    kl.push_back(&b0);
    kl.push_back(&b1);
    kl.push_back(&f0);
    std::cout << kl << std::endl;
    return 0;
}
