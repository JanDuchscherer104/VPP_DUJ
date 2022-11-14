#include "uhr.hpp"

#include <iostream>

void Uhr::checkAttributes() {
    if ((s <= 0 || s > 59) || (m <= 0 || m > 59) || (h <= 0 || h > 23)) {
        s = 0;
        m = 0;
        h = 0;
    }
}

/*void Uhr::tick() {
}
void displayClock() const;*/

int main() {
    Uhr uhr(12, 33, 16);
    return 0;
}