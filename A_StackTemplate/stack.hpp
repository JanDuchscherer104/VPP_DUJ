//
// Created by Jan Duchscherer on 25.11.22.
//
#include <iostream>
#include <stdexcept>

#ifndef STACK_HPP
#define STACK_HPP

template<typename T>
class Stack {
  private:
    size_t size;
    size_t tos;
    T* data;

    void realloc() {
        std::cout << "Stack full. Allocating new memory..." << std::endl;
        size_t newSize = size * 1.5;
        T* temp{new T[newSize]};
        for (size_t i = 0; i < size; ++i) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        size = newSize;
    }
  public:
    explicit Stack(size_t s) : size{s}, tos{0}, data{new T[s]} {}
    void push(T e) {
        if (tos >= size) { realloc(); }
        data[tos] = e;
        ++tos;
    }

    bool empty() const {
        return !tos;
    }

    T pop(){
        if (empty()) {
            throw std::runtime_error("ERROR: Stack is empty!");
        }
        --tos;
        return data[tos];
    }
    T peek() {
        if (empty()) {
            throw std::runtime_error("ERROR: Stack is empty!");
        }
        return data[tos - 1];
    }

    void output(std::ostream& stream) const {
        stream << "Printing stack with size " << size << std::endl;
        for(size_t i = tos - 1; i < tos; --i) {
            stream << data[i] << std::endl;
        }
    }

    ~Stack() {
        delete[] data;
        data = nullptr;
    }
};

template<typename T>
inline std::ostream& operator<<(std::ostream& stream, Stack<T> stack) {
    stack.output(stream);
    return stream;
}

#endif //STACK_HPP
