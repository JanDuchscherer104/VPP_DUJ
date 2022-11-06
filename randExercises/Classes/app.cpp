#include <iostream>

#include "profile.hpp"

int main(void) {
    Profile sam("Sam Drakkila", 30, "New York", "he/him", "USA");
    sam.add_hobby("smoking weed");
    sam.add_hobby("making music");
    sam.add_hobby("fishing");
    std::cout << sam.view_profile() << std::endl;
    return 0;
}