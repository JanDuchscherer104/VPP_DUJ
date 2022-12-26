#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <sstream>
#include <map>

void parseData(const char* fn, std::vector<std::pair<char, char>>& data) {
    std::ifstream f(fn, std::ios::in);
    std::string line;
    std::pair<char, char> pair;
    while (f.good()) {
        while (std::getline(f, line)) {
            std::stringstream input(line);
            input >> pair.first >> pair.second;
            data.push_back(pair);
        }
    }
    if (f.good()) {
        f.close();
    }
}

/*
 * first column: A for Rock, B for Paper, and C for Scissors
 * second column: X for Rock, Y for Paper, and Z for Scissors
 * 1 for Rock, 2 for Paper, and 3 for Scissors
 * 3 for draw, 6 if the round is won
 * X means you lose, Y draw, and Z you win
 */
int getValue(const std::pair<char, char>& pair) {
    int result;
    char hand;
    std::map<char, int> mapToVal{{'X', 0}, {'Y', 3}, {'Z', 6}};
    std::map<char, int> handToVal{{'X', 1}, {'Y', 2}, {'Z', 3}};
    result = mapToVal[pair.second];
    switch (pair.second) {
        case 'X': // lose: idx + 2 % 3
            hand = (char) (((int) pair.first - 'A' + 2) % 3 + (int) 'X');
            break;
        case 'Y': // idx
            hand = (char) (((int) pair.first - 'A') + (int) 'X');
            break;
        case 'Z': // idx + 1 % 3
            hand = (char) (((int) pair.first - 'A' + 1) % 3 + (int) 'X');
    }
    std::cout << pair.first << pair.second << hand << std::endl;
    result += handToVal[hand];
    return result;
}
/*int getValue(const std::pair<char, char>& pair) {
    int result;
    std::map<char, int> mapToVal{{'X', 1}, {'Y', 2}, {'Z', 3}};
    result = mapToVal[pair.second];
    if (pair.first == 'A' && pair.second == 'Y'
        || pair.first == 'B' && pair.second == 'Z' || pair.first == 'C' && pair.second == 'X') {
        result += 6;
    } else if (pair.first == 'A' && pair.second == 'X'
        || pair.first == 'B' && pair.second == 'Y' || pair.first == 'C' && pair.second == 'Z') {
        result += 3;
    }
    return result;
}*/

int main() {
    char fn[] = "data.txt";
    std::vector<std::pair<char, char>> data;
    parseData(fn, data);
    int totalVal = 0;
    for (auto pair : data) {
        totalVal += getValue(pair);
    }
    std::cout << totalVal << std::endl;
    return 0;
}
