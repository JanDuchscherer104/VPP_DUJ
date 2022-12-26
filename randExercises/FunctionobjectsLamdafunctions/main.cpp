#include "fibGen.hpp"
#include <iostream>
#include <vector>

int main() {
    FibGen fib{};
    std::vector<int> fibVec(10);
    Out<std::vector<int>> out{};
    std::generate(fibVec.begin(), fibVec.end(), fib);
    out(fibVec);
    return 0;
}
