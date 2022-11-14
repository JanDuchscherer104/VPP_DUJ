#ifndef KOMPONENTEN_LIST_H
#define KOMPONENTEN_LIST_H

#include <iostream>

#include "fraesung.h"

/* KomponentenElement */
struct KomponentenElement {
    Komponente* k;
    KomponentenElement* before;
    KomponentenElement* next;

    KomponentenElement(Komponente* k = nullptr)
        : k{k} {}
};

/* KomponentenList */
class KomponentenList {
   private:
    size_t m_counter{0};
    KomponentenElement* m_first;
    static bool s_verbose;

    KomponentenElement* getElement(size_t pos) const;

   public:
    KomponentenList(){};
    size_t size() const {return m_counter;} //inline causes error
    KomponentenElement const* at(size_t pos) const;
    int erase(size_t pos);
    void push_back(Komponente* k);
    KomponentenElement* begin() const;
    KomponentenElement* end() const;
    ~KomponentenList();
};

#endif  // KOMPONENTEN_LIST_H
