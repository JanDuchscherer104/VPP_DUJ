#include "../include/Iterator.hpp"

Iterator::Iterator(IKomponentenElement* begin)
    : curr{begin} {}

Iterator& Iterator::operator++() {
    if(curr) {
        curr = curr->next;
    }
    return *this;
}

Iterator& Iterator::operator--() {
    if(curr) {
        curr = curr->before;
    }
    return *this;
}

inline bool Iterator::operator!=(const Iterator& it) const {
    return it.curr != curr;
}

inline bool Iterator::operator==(const Iterator& it) const {
    return it.curr == curr;
}

inline IKomponente* Iterator::operator*() const {
    return curr->k;
}

Iterator::~Iterator() {
    curr = nullptr;
}
