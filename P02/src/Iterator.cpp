#include "../include/Iterator.hpp"

Iterator::Iterator(IKomponentenElement* begin)
    : curr{begin} {}

Iterator& Iterator::operator++() {
    if(curr) {
        curr = curr->next;
    }
    return *this;
}

bool Iterator::operator!=(const Iterator& it) const {
    return it.curr != curr;
}

bool Iterator::operator==(const Iterator& it) const {
    return it.curr == curr;
}

IKomponente* Iterator::operator*() const {
    IKomponente* ret {};
    if (curr) {
        ret = curr->k;
    }
    return ret;
}

Iterator::~Iterator() {
    curr = nullptr;
}
