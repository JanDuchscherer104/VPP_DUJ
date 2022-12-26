#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

void readFile(const std::string& fn, std::vector<int>& v) {
    std::ifstream f(fn, std::ios::in);
    std::string line;
    int calSum = 0;
    while (f.good()) {
        while (std::getline(f, line)) {
            if (f.eof()) {
                break;
            }
            if (line.empty()) {
                v.push_back(calSum);
                calSum = 0;
            } else {
                calSum += std::stoi(line);
            }
        }
    }
    if (f.good()) {
        f.close();
    }
}

template<class C, class F>
typename C::value_type reduce(typename C::const_iterator b, typename C::const_iterator e, F f) {
    typename C::value_type ret = 0;
    for (; b != e; ++b) {
        ret = f(ret, *b);
    }
    return ret;
}

template<class C>
int argmax(C cals) {
    std::vector<int> maxCals(3, 0);
    std::vector<int>::iterator minIter{};
    for (auto it : cals) {
        minIter = std::min_element(maxCals.begin(), maxCals.end()); //
        if (it > *minIter) {
            *minIter = it;
        }
    }
    int ret = 0;
    ret = reduce<std::vector<int>>(maxCals.begin(), maxCals.end(), [](int a, int b) { return a + b; });
    return ret;
}

int main() {
    std::string fn = "../data.txt";
    std::vector<int> cals;
    readFile(fn, cals);
    for (int cal : cals) {
        std::cout << "Calories: " << cal << std::endl;
    }
    std::cout << "MaxCals: " << argmax(cals) << std::endl;
    return 0;
}
