#ifndef DELIST_HPP
#define DELIST_HPP

#include "IKomponentenElement.hpp"
#include "Iterator.hpp"

class DeList {
  private:
    int counter;
    IKomponentenElement* first;

    IKomponentenElement* getElement(const Iterator& it) const;

  public:
    DeList(); // non-converting constructor - no parama so not necessary
    DeList(const DeList& rhs); // copy-constructor
    DeList& operator=(const DeList& rhs); // copy-assignmentss
    void clear();
    int size() const;
    Iterator erase(const Iterator& it);
    void push_back(IKomponente* k);
    Iterator end() const;
    Iterator begin() const;
    ~DeList();
};

#endif //DELIST_HPP
