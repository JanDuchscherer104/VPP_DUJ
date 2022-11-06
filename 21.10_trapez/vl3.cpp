#include <iostream>
#include <iomanip>
#include <string>
/*
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
*/

std::string genPyramid(int h)
{
    int **pasc = new int *[h];
    std::string ret;
    for (int i = 0; i < h; ++i)
    {
        *(pasc + i) = new int[i + 1];
        for (int j = 0; j < i + 1; ++j)
        {
            if (j == 0 || j == i)
            {
                pasc[i][j] = 1;
            }
            else
            {
                pasc[i][j] = pasc[i - 1][j - 1] + pasc[i - 1][j];
            }
            ret += std::to_string(pasc[i][j]);
            if (j != i)
            {
                ret += " ";
            }
        }
        ret += "\n";
    }
    for (int i = 0; i < h; ++i)
    {
        delete[] pasc[i];
        pasc[i] = nullptr;
    }
    delete[] pasc;
    return ret;
}

void formatPyramid(std::string pyramid, int h)
{
    std::string::size_type sub_idx{pyramid.find("\n")};
    for (int j = 1; j < h - 1 && sub_idx != std::string::npos; ++j)
        sub_idx = pyramid.find("\n", sub_idx + 1); // Find the next occurrence
    int max_line_len{pyramid.length() - sub_idx};
    int prev_idx,{0};
    std::cout << std::string((int)(max_line_len / 2 + 0.5) - n, ' ');
    ++n;
    for (char ch : pyramid)
    {
        if (ch == "\n")
        {
            std::cout << std::string((int)(max_line_len / 2 + 0.5) - n, ' ');
            ++n;
        }
    }
    std::cout << max_line_len << std::endl;
}

int main(void)
{
    int h;
    std::cout << "Enter height of the pyramid: ";
    std::cin >> h;
    std::string pyramid{genPyramid(h)};
    std::cout << pyramid;
    formatPyramid(pyramid, h);
    return 0;
}