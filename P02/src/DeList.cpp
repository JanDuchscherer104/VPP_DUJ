#include "../include/DeList.hpp"

IKomponentenElement* DeList::getElement(const Iterator& it) const {
    IKomponentenElement* temp{first};
    IKomponentenElement* ret{};
    if (*it) { // check if it.curr points at a IKomponentenElement whose k is not nullptr
        while (temp) {
            if (*it == temp->k) {
                ret = temp;
                break;
            }
            temp = temp->next;
        }
    }
    return ret;
}

DeList::DeList()
    : counter{0}, first{nullptr} {}

DeList::DeList(const DeList& rhs)
    : DeList{} {
    for (IKomponente* it : rhs) {
        push_back(it);
    }
}

DeList& DeList::operator=(const DeList& rhs) {
    if (this != &rhs) {
        clear();
        for (IKomponente* it : rhs) {
            push_back(it);
        }
    }
    return *this;
}

//DeList& DeList::operator=(DeList&& rhs) noexcept {
//    if (this != &rhs) {
//        clear();
//        counter = rhs.counter;
//        first = rhs.first;
//        rhs.first = nullptr; // unlink linkedlist from rhs to prevent it from being deleted
//        rhs.counter = 0;
//    }
//    return *this;
//}

void DeList::clear() {
    IKomponentenElement* pHead;
    while (first) {
        pHead = first->next;
        delete first;
        first = pHead;
    }
    counter = 0;
}

int DeList::size() const { return counter; }

Iterator DeList::erase(const Iterator& it) {
    IKomponentenElement* temp{getElement(it)};
    Iterator ret{temp};
    if (temp) { // found matching element
        if (temp->before) { // if temp is not first
            temp->before->next = temp->next;
        } else {
            first = temp->next;
        }
        if (temp->next) { // if temp is not last
            temp->next->before = temp->before;
        }
        delete temp;
        --counter;
    }
    return ret;
}

void DeList::push_back(IKomponente* k) {
    auto* temp{new IKomponentenElement{k}};
    if (first) {
        IKomponentenElement* last{first};
        while (last->next) {
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
