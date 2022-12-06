#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include "IKomponentenElement.hpp"

class Iterator {
  private:
    IKomponentenElement* curr;
  public:
    explicit Iterator(IKomponentenElement* begin = nullptr); // non-converting constructor
    Iterator& operator++();
    bool operator!=(const Iterator& it) const;
    bool operator==(const Iterator& it) const;
    IKomponente* operator*() const;
    ~Iterator();
};

#endif //ITERATOR_HPP
