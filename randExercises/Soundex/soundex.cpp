#include <iostream>
#include <unordered_map>
#include <string>
#include <cctype>

#include "soundex.hpp"

std::string soundex(std::string word) {
    std::string soundex;
    soundex = word[0];
    word.erase(0, 1);
    for (char ch: word) {
        if (soundex.length() == 4) {
            break;
        }
        if (soundex_map.count(ch) > 0 and soundex.back() != soundex_map[ch]) {
            soundex += std::to_string(soundex_map[ch]);
        }
    }
    while (soundex.length() < 4) {
        soundex += "0";
    }
    return soundex;
}

void soundex(char* word, char* code) {
    kleinNachGross(word);
    std::string temp_str = soundex(std::string(word));
    for (int i = 0; i < temp_str.length(); ++i)
    {
        code[i] = temp_str[i];
    }
}

void kleinNachGross(char* word) {
    for (int i = 0; i < sizeof(word); ++i)
    {
        word[i] = toupper(word[i]);
    }
}

int main(void) {
    char word[]{"Banana"};
    constexpr int N {sizeof(word)};
    char code[N];
    soundex(word, code);
    std::cout << word << " - " << code << std::endl;
    return 0;
}