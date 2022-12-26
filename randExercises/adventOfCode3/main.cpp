#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include <set>

/*
 * 1. split
 * 2. filer all common items in both splits
 * 3. calculate weight of those items
 * 4. sum up all weights
 */

void getSplits(const std::string& fn, std::vector<std::pair<std::string, std::string>>& splits) {
    std::ifstream f(fn, std::ios::in);
    std::string line, s1, s2;
    if (f) {
        while (std::getline(f, line)) {
            s1 = line.substr(0, line.length() / 2);
            s2 = line.substr(line.length() / 2);
            splits.emplace_back(s1, s2);
        }
        f.close();
    }
}

void getCommons(const std::vector<std::pair<std::string, std::string>>& splits, std::vector<std::set<char>>& commons) {
    std::set<char> s1, s2, intersect;
    for (const auto& pair : splits) {
        s1.clear();
        s2.clear();
        intersect.clear();
        for (char ch : pair.first) {
            s1.insert(ch);
        }
        for (char ch : pair.second) {
            s2.insert(ch);
        }
        std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                              std::inserter(intersect, intersect.begin()));
        std::cout << "Intersect of" << pair.first << " & " << pair.second << ": ";
        for(char ch: intersect) {
            std::cout << ch;
        }
        std::cout << std::endl;
        commons.emplace_back(intersect);
    }
}

int getPrio(const std::vector<std::set<char>>& allCommons) {
    int prio = 0;
    for (const auto& commons : allCommons) {
        for (char common : commons) {
            prio += common <= 'Z' ? common - 64 + 26 : common - 96;
        }
    }
    return prio;
}

int main() {
    std::vector<std::pair<std::string, std::string>> splits;
    std::vector<std::set<char>> commons;
    getSplits("../data.txt", splits);
    getCommons(splits, commons);
    std::cout << "Prio: " <<  getPrio(commons) << std::endl;

    return 0;
}
