#include <iostream>
#include <vector>
#include <list>
#include "Container.hpp"
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> range(10);
    PrintContainer<std::vector<int>> print;
    int i = 0;
    std::generate(range.begin(), range.end(), [i]() mutable -> int { return ++i; });
    std::cout << print(range.begin(), range.end()) << std::endl;

    using sqr = std::function<int(int)>;
    sqr square = [](int x) { return x * x; };
    chain<std::vector<int>, sqr, sqr>(range.begin(), range.end(), square, square);
    /*chain<std::vector<int>>(range.begin(), range.end(),
                            [](int x) { return x * x; },
                            [](int x) { return x * x; });*/
    std::cout << print(range.begin(), range.end()) << std::endl;

    std::cout << "allGreater10000: " << std::boolalpha
              << allTrue<std::vector<int>, std::function<bool(int)>>(range.begin(),
                                                                     range.end(),
                                                                     [](int e) { return e > 10000; })
              << std::endl
              << "allLess10001: "
              << allTrue<std::vector<int>>(range.begin(),
                                           range.end(),
                                           [](int e) { return e < 10001; })
              << std::endl;

    std::generate(range.begin(), range.end(), [i]() mutable -> int { return ++i; });
    addN<int, 42> add42;
    timesN<int, 2> times2;
    greaterN<int, 50> greater50;
    greaterN<int, 0> greater0;
    chain<std::vector<int>>(range.begin(), range.end(), add42, times2);
    std::cout << print(range.begin(), range.end()) << std::endl;
    std::cout << "allGreater50: " << std::boolalpha << allTrue<std::vector<int>>(range.begin(),
                                                                                 range.end(),
                                                                                 greater50)
              << std::endl
              << "allGreater0: " << std::boolalpha << allTrue<std::vector<int>>(range.begin(),
                                                                                 range.end(),
                                                                                 greater0) << std::endl;

    std::list<int> rangeL(10);
    i = 0;
    PrintContainer<std::list<int>> printL;
    std::generate(rangeL.begin(), rangeL.end(), [i]() mutable -> int { return ++i; });
    chain<std::list<int>>(rangeL.begin(), rangeL.end(), add42, times2);
    std::cout << printL(rangeL.begin(), rangeL.end()) << std::endl;
    std::cout << "allGreater50: " << std::boolalpha << allTrue<std::list<int>>(rangeL.begin(),
                                                                                 rangeL.end(),
                                                                                 greater50)
              << std::endl
              << "allGreater0: " << std::boolalpha << allTrue<std::list<int>>(rangeL.begin(),
                                                                                rangeL.end(),
                                                                                greater0) << std::endl;

    return 0;
}
