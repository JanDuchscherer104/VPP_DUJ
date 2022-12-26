#ifndef DELIST_HPP
#define DELIST_HPP

#include "TElement.hpp"
#include "Iterator.hpp"

template<class T>
class DeList {
  private:
    int counter;
    TElement<T>* first;

    TElement<T>* getElement(const Iterator<T>& it) const;

  public:
    DeList(); // non-converting constructor - no parama so not necessary
    DeList(const DeList& rhs); // copy-constructor
    DeList& operator=(const DeList& rhs); // copy-assignmentss
    void clear();
    int size() const;
    Iterator<T> erase(const Iterator<T>& it);
    void push_back(T k);
    Iterator<T> end() const;
    Iterator<T> begin() const;
    ~DeList();
};

#endif //DELIST_HPP
