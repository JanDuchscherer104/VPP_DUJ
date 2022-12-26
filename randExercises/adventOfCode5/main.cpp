#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <vector>
#include <tuple>
#include <algorithm>

/*
                        [Z] [W] [Z]
        [D] [M]         [L] [P] [G]
    [S] [N] [R]         [S] [F] [N]
    [N] [J] [W]     [J] [F] [D] [F]
[N] [H] [G] [J]     [H] [Q] [H] [P]
[V] [J] [T] [F] [H] [Z] [R] [L] [M]
[C] [M] [C] [D] [F] [T] [P] [S] [S]
[S] [Z] [M] [T] [P] [C] [D] [C] [D]
 1   2   3   4   5   6   7   8   9
 */

void getInitialLoad(const std::string& fn, std::vector<std::stack<char>>& stacks) {
    int iStack;
    const std::string hole = "   ";
    std::string line;
    std::ifstream f(fn, std::ios::in);
    size_t elementMatch, holeMatch;
    if (f) {
        while (std::getline(f, line)) {
            iStack = 0;
            elementMatch = -2;
            holeMatch = -2;
            while ((holeMatch != std::string::npos
                || elementMatch != std::string::npos)
                && ((iStack * 4 - 1) <= (int) line.size())) {
                holeMatch = line.find(hole, holeMatch + 2);
                elementMatch = line.find('[', elementMatch + 2);
                if (elementMatch < holeMatch) {
                    stacks[iStack].push(line[elementMatch + 1]);
                    // std::cout << "["<< iStack << "," << line[elementMatch + 1] << "] ";
                    holeMatch = elementMatch;
                } else {
                    holeMatch += 2;
                    elementMatch = holeMatch;
                }
                ++iStack;
            }
            std::cout << std::endl;
        }
        f.close();
    }

    for(auto& stack: stacks) {
        std::stack<char> reversedStack{};
        while(!stack.empty()) {
            reversedStack.push(stack.top());
            stack.pop();
        }
        stack = reversedStack;
    }
    std::cout << "Initial load: " << std::endl;
    size_t stackSize;
    for (auto stack : stacks) {
        stackSize = stack.size();
        for (int i = 0; i < stackSize; ++i) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void getInstructions(const std::string& fn, std::vector<std::tuple<int, int, int>>& instrutions) {
    int numb, from, to;
    std::string word;
    std::ifstream f(fn, std::ios::in);
    if (f) {
        while (!f.eof()) {
            //std::cout << numb << " " << from << " " << to << std::endl;
            if (f >> word >> numb >> word >> from >> word >> to) {
                instrutions.emplace_back(numb, from, to);
            }
        }
    }
    if (f) {
        f.close();
    }
}

void executeInstructions(std::vector<std::stack<char>>& stacks,
                         std::vector<std::tuple<int, int, int>>& instrutions) {
    int numb, from, to;
    std::cout << "Executing " << instrutions.size() << " instructions: " << std::endl;
    for (const auto& inst : instrutions) {
        numb = std::get<0>(inst);
        from = std::get<1>(inst) - 1;
        to = std::get<2>(inst) - 1;
        std::cout << numb << " " << from << " " << to << std::endl;
        for (int i = 0; i < numb; ++i) {
            stacks[to].push(stacks[from].top());
            stacks[from].pop();
        }
    }
}

int main() {
    std::vector<std::stack<char>> stacks(9);
    std::vector<std::tuple<int, int, int>> instructions;
    getInitialLoad("initial.txt", stacks);
/*        size_t stackSize;
    for (auto stack: stacks)  {
        stackSize = stack.size();
        for(int i = 0; i < stackSize; ++i) {
            std::cout << stack.top() << " ";
            stack.pop();
        }
        std::cout << std::endl;
    }*/
    getInstructions("inst.txt", instructions);
    executeInstructions(stacks, instructions);
    for (const auto& stack : stacks) {
        std::cout << stack.top();
    }
    std::cout << std::endl;
    return 0;
}
