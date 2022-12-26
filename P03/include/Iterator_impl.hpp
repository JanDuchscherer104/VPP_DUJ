#ifndef ITERATOR_IMPL_HPP
#define ITERATOR_IMPL_HPP

#include "Iterator.hpp"

template<class T>
Iterator<T>::Iterator(TElement<T>* begin)
    : curr{begin} {}

template<class T>
Iterator<T>& Iterator<T>::operator++() {
    if(curr) {
        curr = curr->next;
    }
    return *this;
}

template<class T>
bool Iterator<T>::operator!=(const Iterator<T>& it) const {
    return it.curr != curr;
}

template<class T>
bool Iterator<T>::operator==(const Iterator<T>& it) const {
    return it.curr == curr;
}

template<class T>
T Iterator<T>::operator*() const {
    T ret {};
    if (curr) {
        ret = curr->k;
    }
    return ret;
}

template<class T>
Iterator<T>::~Iterator() {
    curr = nullptr;
}

#endif // ITERATOR_IMPL_HPP
