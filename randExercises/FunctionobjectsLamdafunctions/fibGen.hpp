//
// Created by Jan Duchscherer on 15.12.22.
//

#ifndef FIBGEN_HPP
#define FIBGEN_HPP

#include <iostream>

class FibGen {
  private:
    int cur = 0;
    int prev = 0;
  public:
    FibGen() : cur{1}, prev{0} {}
    int operator()() {
        int ret;
        ret = cur + prev;
        prev = cur;
        cur = ret;
        return ret;
    }
};

template<typename T>
class Out {
  public:
    void operator()(T out) const {
        std::cout << "[";
        for (auto it = std::begin(out); it != std::end(out);) {
            std::cout << *it;
            if (++it  != std::end(out)) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
};

#endif //FIBGEN_HPP
