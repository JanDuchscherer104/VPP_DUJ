#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "TElement.hpp"

template<class T>
class Iterator {
  private:
    TElement<T>* curr;
  public:
    explicit Iterator(TElement<T>* begin = nullptr); // non-converting constructor
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    bool operator==(const Iterator& it) const;
    T operator*() const;
    ~Iterator();
};

#endif //ITERATOR_HPP
