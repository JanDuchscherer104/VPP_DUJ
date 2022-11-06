#include <cmath>
#include <iostream>
#define N_MAX 3U

/* genGrayCode(const int length, unsigned int* code)
{

} */

inline void setBit(unsigned int &binValue, int iBit) { binValue |= 1U << iBit; }

inline bool getBit(unsigned int binValue, int iBit) {
    return (bool)((binValue >> iBit) & 1U);
}

inline void deleteBit(unsigned int &binValue, int iBit) { binValue &= ~(1U << iBit); }

void binToString(unsigned int binValue, int nBits, char *binStr) {
    for (int i{0}; i < nBits; ++i) {
        binStr[nBits - i - 1] = getBit(binValue, i) ? '1' : '0';
    }
    binStr[nBits] = '\0';
}

int hammingDistance(unsigned int word1, unsigned int word2, int nBits) {
    int ret{0};
    for (int i{0}; i < nBits; ++i) {
        if (getBit(word1, i) != getBit(word2, i)) {
            ret += 1;
        }
    }
    return ret;
}

inline int grayCodeSize(int nBits) {
    return std::pow(2, nBits);
}

void printGrayCode(const unsigned int *code, int nBits) {
    char binStr[nBits];
    for (int iWrd{0}; iWrd < grayCodeSize(nBits); ++iWrd) {
        binToString(code[iWrd], nBits, binStr);
        std::cout << binStr << std::endl;
    }
}

void grayCode(unsigned int *code, int nBits) {
    static int nBitsCur{1};
    if (nBitsCur == 1) {
        setBit(code[1], 0);
    } else {
        for (int iWrd{0}; iWrd < grayCodeSize(nBitsCur - 1); ++iWrd) {
            for (int iBit{0}; iBit < nBitsCur - 1; ++iBit) {
                if (getBit(code[iWrd], iBit)) {
                    setBit(code[grayCodeSize(nBitsCur) - 1 - iWrd], iBit);
                }
                setBit(code[grayCodeSize(nBitsCur) - 1 - iWrd], iBit + 1);
                std::cout << "iWrd: " << iWrd << ", iBit: " << iBit
                          << ", nBits: " << nBits << ", nBitsCur: " << nBitsCur
                          << std::endl;
                printGrayCode(code, nBitsCur);
            }
        }
    }
    if (nBitsCur < nBits) {
        nBitsCur++;
        grayCode(code, nBits);
    } else {
        nBitsCur = 1;
    }
}

int main(void) {
    unsigned int words[8] = {0};
    printGrayCode(words, 3);
    grayCode(words, 3);
    /* unsigned int word{0};
    setBit(word, 2);
    char str[8];
    binToString(word, 8, str);
    std::cout << str << std::endl; */
    return 0;
}