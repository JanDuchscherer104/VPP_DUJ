#ifndef DELIST_IMPL_HPP
#define DELIST_IMPL_HPP

#include "DeList.hpp"

template<class T>
TElement<T>* DeList<T>::getElement(const Iterator<T>& it) const {
    TElement<T>* temp{first};
    TElement<T>* ret{};
    if (*it) { // check if it.curr points at a TElement<T> whose k is not nullptr
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

template<class T>
DeList<T>::DeList()
    : counter{0}, first{nullptr} {}

template<class T>
DeList<T>::DeList(const DeList& rhs)
    : DeList{} {
    for (T item: rhs) {
        push_back(item);
    }
}

template<class T>
DeList<T>& DeList<T>::operator=(const DeList<T>& rhs) {
    if (this != &rhs) {
        clear();
        for (T item : rhs) {
            push_back(item);
        }
    }
    return *this;
}

//DeList& DeList<T>::operator=(DeList&& rhs) noexcept {
//    if (this != &rhs) {
//        clear();
//        counter = rhs.counter;
//        first = rhs.first;
//        rhs.first = nullptr; // unlink linkedlist from rhs to prevent it from being deleted
//        rhs.counter = 0;
//    }
//    return *this;
//}

template<class T>
void DeList<T>::clear() {
    TElement<T>* pHead;
    while (first) {
        pHead = first->next;
        delete first;
        first = pHead;
    }
    counter = 0;
}

template<class T>
int DeList<T>::size() const { return counter; }

template<class T>
Iterator<T> DeList<T>::erase(const Iterator<T>& it) {
    TElement<T>* temp{getElement(it)};
    Iterator<T> ret{temp};
    if (temp) { // found matching element
        if (temp->before) { // if temp is not first
            temp->before->next = temp->next;
        } else {
            first = temp->next;
        }
        if (temp->next) { // if temp is not last
            temp->next->before = temp->before;
        }
        ++ret;
        delete temp;
        --counter;
    }
    return ret;
}

template<class T>
void DeList<T>::push_back(T k) {
    auto* temp{new TElement<T>{k}};
    if (first) {
        TElement<T>* last{first};
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

template<class T>
Iterator<T> DeList<T>::end() const {
    Iterator<T> ret{nullptr};
    return ret;
}

template<class T>
Iterator<T> DeList<T>::begin() const {
    Iterator<T> ret{first};
    return ret;
}

template<class T>
DeList<T>::~DeList() {
    clear();
}

#endif //DELIST_IMPL_HPP
