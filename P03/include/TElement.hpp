#ifndef TElement_HPP
#define TElement_HPP

template<class T>
struct TElement {
  T k;
  TElement* before;
  TElement* next;

  explicit TElement(T k)
      : k{k}, before{nullptr}, next{nullptr} {}
  explicit TElement()
      : before{nullptr}, next{nullptr} {}
};

#endif //TElement_HPP
