#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> soundex_map = {
    {'B', 1}, {'F', 1}, {'P', 1}, {'V', 1},
    {'C', 2}, {'G', 2}, {'J', 2}, {'K', 2}, {'Q', 2}, {'S', 2}, {'X', 2}, {'Z', 2},
    {'D', 3}, {'T', 3},
    {'L', 4},
    {'M', 5}, {'N', 5},
    {'R', 6}
};
std::string soundex(std::string word);
void soundex(char* word, char* code);
void kleinNachGross(char *word);