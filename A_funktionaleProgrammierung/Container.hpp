#ifndef CONTAINER_HPP_
#define CONTAINER_HPP_
#include <string>

template<class C>
class PrintContainer {
  public:
    std::string operator()(typename C::const_iterator b, typename C::const_iterator e) const;
};

template<class C>
std::string PrintContainer<C>::operator()(typename C::const_iterator b, typename C::const_iterator e) const {
    std::string retstr = "[";
    for (typename C::const_iterator it = b; it != e; ++it) {
        retstr += std::to_string(*it) + ", ";
    }
    retstr.pop_back();
    retstr.pop_back();
    retstr += "]";

    return retstr;
}

template<class C, class F1, class F2>
void chain(typename C::iterator b, typename C::iterator e, F1 f1, F2 f2) {
    for (typename C::iterator it = b; it != e; ++it) {
        *it = f1(f2(*it));
    }
}

template<class C, class T>
bool allTrue(typename C::const_iterator b, typename C::const_iterator e, T compare) {
    bool all = true;
    for (typename C::const_iterator it = b; it != e; ++it) {
        if (!compare(*it)) {
            all = false;
            break;
        }
    }
    return all;
}

template<typename T, int n>
class addN {
  public:
    T operator()(T t) const {
        return t + n;
    }
};

template<typename T, int n>
class timesN {
  public:
    T operator()(T t) const {

        return t * n;

    }
};

template<typename T, int n>
class greaterN {
  public:
    bool operator()(T t) const {
        return t > n;
    }
};

#endif //CONTAINER_HPP_
