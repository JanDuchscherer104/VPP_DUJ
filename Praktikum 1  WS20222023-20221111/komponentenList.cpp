#include "komponentenList.h"

#include <iostream>

#include "fraesung.h"

/* Definitions of methods for class KomponentenList */

bool KomponentenList::s_verbose{true};

// KomponentenList::KomponentenList() {}
KomponentenElement* KomponentenList::getElement(size_t pos) const {
    /*
    return nullptr if pos > m_counter
    */
    if (pos > m_counter) {
        return nullptr;
    }
    KomponentenElement* temp{m_first};
    for (size_t i = 0; i < pos; ++i) {
        temp = temp->next;
    }
    return temp;
}
// inline size_t KomponentenList::size() const {
//     return m_counter;
// }

KomponentenElement const* KomponentenList::at(size_t pos) const {
    return std::move(getElement(pos));
}
int KomponentenList::erase(size_t pos) {
    KomponentenElement* pHead{getElement(pos)};
    if (s_verbose) {
        std::cout << "erase " << pos << " ~" << *(pHead->k) << std::endl;
    }
    if (pos == 0) {
        pHead->next->before = nullptr;
    } else {
        pHead->before->next = pHead->next;
        if (pos < m_counter - 1) {
            pHead->next->before = pHead->before;
        } else {
            return -1;
        }
    }
    delete pHead;
    --m_counter;
    return pos;
}

void KomponentenList::push_back(Komponente* k) {
    KomponentenElement* pHead = new KomponentenElement{k};
    if (m_first) {
        KomponentenElement* pPrev{getElement(m_counter - 1)};
        if (pPrev) {
            pPrev->next = pHead;
            pHead->before = pPrev;
        }
    } else {
        m_first = pHead;
    }
    ++m_counter;
}

// KomponentenElement* KomponentenList::begin() const {}
// KomponentenElement* KomponentenList::end() const {}
KomponentenList::~KomponentenList() {
    for (size_t i = m_counter; i > 0; --i) {
        delete getElement(i - 1);
    }
    if (s_verbose) {
        std::cout << "Destroyed KomponentenList" << std::endl;
    }
};
