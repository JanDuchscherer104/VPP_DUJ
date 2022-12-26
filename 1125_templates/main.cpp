#include <iostream>
#include <cstring>
#include <complex>

template<typename T>
void swap(T& x, T& y) {
    T temp = x;
    x = y;
    y = temp;
}

template<typename T>
inline bool less(T x, T y) { return x < y; }

template<>
// spezialization for const char*
inline bool less(const char* x, const char* y) { return strcmp(x, y) < 0; }

//template<typename T>
//inline bool less(const std::complex<T>& x,const std::complex<T>& y) {
//    return abs(x) < abs(y);
//}

template<int n, typename T>
void bubbleSort(T* v) {
    for (int i = 1; i < n; ++i) {
        bool swapped = false;
        for (int j = 0; j < n - i; ++j) {
            if (less(v[j + 1], v[j])) {
                swapped = true;
                swap(v[j], v[j + 1]);
            }
        }
        if (!swapped) break;
    }
}

template<int n, typename T>
void printVec(T* v) {
    for (int i = 0; i < n; ++i) {
        std::cout << v[i] << std::endl;
    }
}

int main() {
    constexpr int n = 7;
    float v[n] {10, 8, 3, 2, 7, 420, 3.1415926535897932384626433832795};
    bubbleSort<n>(v);
    printVec<n>(v);
//    std::complex<float> vc[2] {{1, 2}, {3, 4}};
//    bubbleSort<2>(vc);
    return 0;
}
