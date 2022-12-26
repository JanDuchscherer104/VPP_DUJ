#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

void readData(const std::string& fn, std::vector<std::vector<int>>& arr) {
    std::ifstream f(fn, std::ios::in);
    std::string line;
    char read;
    std::vector<int> curRow;
    if (f) {
        while (std::getline(f, line)) {
            curRow.clear();
            std::stringstream lnStream(line);
            while (lnStream >> read) {
                curRow.push_back(static_cast<int>(read - '0'));
            }
            arr.push_back(curRow);
        }
        f.close();
    }
    for (const auto& row : arr) {
        for (const auto& e : row) {
            std::cout << e;
        }
        std::cout << std::endl;
    }
}

size_t getVisibles(const std::vector<std::vector<int>>& arr) {
    size_t rows, cols;
    size_t visibilityCnt = 0;
    rows = arr.size();
    cols = arr[0].size();
    // bool visible[rows][cols]{false};
    bool** visible = new bool* [rows];
    for (size_t row = 0; row < rows; ++row) {
        visible[row] = new bool[cols];
        for (size_t col = 0; col < cols; ++col) {
            visible[row][col] = false;
        }
    }

    int highest;
    // check all rows from both sides
    //right->left
    for (size_t row = 0; row < rows; ++row) {
        highest = arr[row][0];
        for (size_t col = 0; col < cols; ++col) {
            if (arr[row][col] > highest) {
                highest = arr[row][col];
                visible[row][col] = true;
                ++visibilityCnt;
            } else if (arr[row][col] == 9) {
                break;
            }
        }
    }
    //left->right
    for (size_t row = rows; row < rows; ++row) {
        highest = arr[row][0];
        for (size_t col = cols - 1; col < cols; --col) {
            if (arr[row][col] > highest) {
                highest = arr[row][col];
                visible[row][col] = true;
                ++visibilityCnt;
            } else if (arr[row][col] == 9) {
                break;
            }
        }
    }
    // check all cols
    //right->left
    for (size_t col = 0; col < cols; ++col) {
        highest = arr[0][col];
        for (size_t row = 0; row < rows; ++row) {
            if (arr[row][col] > highest) {
                highest = arr[row][col];
                visible[row][col] = true;
                ++visibilityCnt;
            } else if (arr[row][col] == 9) {
                break;
            }
        }
    }
    //left->right
    for (size_t col = 0; col < cols; ++col) {
        highest = arr[0][col];
        for (size_t row = rows; row < rows; --row) {
            if (arr[row][col] > highest) {
                highest = arr[row][col];
                visible[row][col] = true;
                ++visibilityCnt;
            } else if (arr[row][col] == 9) {
                break;
            }
        }
    }

    for (size_t row = 0; row < rows; ++row) {
        delete[] visible[row];
        visible[row] = nullptr;
    }
    delete[] visible;
    visible = nullptr;
    return visibilityCnt;
}

int main() {
    std::vector<std::vector<int>> arr;
    readData("data.txt", arr);
    std::cout << "Visible: " << getVisibles(arr) << std::endl;
    return 0;
}
