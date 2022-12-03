#include "../include/DeList.hpp"

IKomponentenElement* DeList::getElement(const Iterator& it) const {
    IKomponentenElement* temp{first};
    while (temp) {
        temp = temp->next;
        if (*it == temp->k) {
            return temp;
        }
    }
    return nullptr;
}

DeList::DeList()
    : counter{0}, first{nullptr} {}

DeList::DeList(const DeList& rhs) {
    counter = rhs.counter;
    first = rhs.first;
}

DeList& DeList::operator=(const DeList& rhs) {
    if (this != &rhs) {
        clear();
        counter = rhs.counter;
        first = rhs.first;
    }
    return *this;
}

void DeList::clear() {
    IKomponentenElement* pHead{first};
    while (first) {
        pHead = first->next;
        delete first;
        first = pHead;
    }
    counter = 0;
}

inline int DeList::size() const { return counter; }

Iterator DeList::erase(const Iterator& it) {
    IKomponentenElement* temp{getElement(it)};
    if (temp) { // found matching element
        if (temp->before) { // if temp is not first
            temp->before->next = temp->next;
        } else {
            first = temp->next;
        }
        if (temp->next) {
            temp->next->before = temp->before;
        }
        Iterator ret{temp->next};
        delete temp;
        --counter;
        return ret;
    }
    Iterator ret{nullptr}; // TODO multiple returns
    return ret;
}

void DeList::push_back(IKomponente* k) {
    auto* temp {new IKomponentenElement{k}};
    if (first) {
        IKomponentenElement* last{first};
        while(last->next) {
            last = last->next;
        }
        last->next = temp;
        temp->before = last;
    } else {
        first = temp;
    }
    ++counter;
}

Iterator DeList::end() const {
    Iterator ret{nullptr};
    return ret;
}

Iterator DeList::begin() const {
    Iterator ret{first};
    return ret;
}

DeList::~DeList() {
    clear();
}
