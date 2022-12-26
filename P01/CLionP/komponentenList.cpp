#include "komponentenList.hpp"

#include <iostream>
#include <stdexcept>

#include "fraesung.hpp"

/* Definitions of methods for class KomponentenElement */
KomponentenElement::KomponentenElement(Komponente* k)
    : k{k}, before{nullptr}, next{nullptr} {}

/* Definitions of methods for class KomponentenList */
bool KomponentenList::s_verbose{false};
// KomponentenList::KomponentenList() {}
KomponentenElement* KomponentenList::getElement(size_t pos) const {
    if (pos < m_counter) {
        KomponentenElement* temp{m_first};
        for (size_t i = 0; i < pos; ++i) {
            temp = temp->next;
        }
        return temp;
    }
    if (s_verbose) {
        std::cout << "ERROR: KomponentenList::getElement: pos >= m_counter" << std::endl;
    }
    return nullptr;
}
size_t KomponentenList::size() const {
    return m_counter;
}

Komponente const* KomponentenList::at(size_t pos) const {
    KomponentenElement* temp = getElement(pos);
    if (temp) {
        return temp->k;
    }
    return nullptr;
}
int KomponentenList::erase(size_t pos) {
    KomponentenElement* pHead{getElement(pos)};
    if (s_verbose) {
        std::cout << "erase " << pos << " ~" << *(pHead->k) << std::endl;
    }
    if (pHead) {
        if (pHead->before) {
            pHead->before->next = pHead->next;
        } else {
            m_first = pHead->next;
        }
        if (pHead->next) {
            pHead->next->before = pHead->before;
        }
        delete pHead;
        --m_counter;
        return static_cast<int>(pos);
    }
    return -1;
}

void KomponentenList::push_back(Komponente* k) {
    auto* pHead = new KomponentenElement{k};
    if (m_first) {
        KomponentenElement* last{m_first};
        while (last->next) {
            last = last->next;
        }
        last->next = pHead;
        pHead->before = last;
    } else {
        m_first = pHead;
    }
    ++m_counter;
}

KomponentenElement* KomponentenList::begin() const {
    return m_first;
}

KomponentenElement* KomponentenList::end() const {
    return nullptr;
}

void KomponentenList::output(std::ostream& os) const {
    KomponentenElement* it{m_first};
    while (it) {
        os << *(it->k) << std::endl;
        it = it->next;
    }
}

KomponentenList::~KomponentenList() {
    KomponentenElement* pHead{m_first};
    while (m_first) {
        pHead = m_first->next;
        delete m_first;
        m_first = pHead;
    }
    if (s_verbose) {
        std::cout << "Destroyed KomponentenList" << std::endl;
    }
};
