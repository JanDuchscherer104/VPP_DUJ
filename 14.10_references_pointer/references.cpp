#include <iostream>
#include <vector>

void minMaxAvg(std::vector<double>& vec, double& min, double& max, double& avg) {
    double sum = 0;
    min = vec[0];
    max = vec[0];
    for (double val : vec)
    {
        max = val > max ? val : max;
        min = val < min ? val : min;
        sum += val;
    }
    avg = sum / vec.size();
}

int main(void) {
    std::vector<double> vec = {1.0, 3.14, 420, 42};
    double min, max, avg;
    minMaxAvg(vec, min, max, avg);
    std::cout << "Min: " << min << ", Max: " << max << ", Avg: " << avg << std::endl;
    return 0;
}