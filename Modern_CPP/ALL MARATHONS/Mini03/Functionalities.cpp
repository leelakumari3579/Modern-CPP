#include "Functionalities.hpp"

std::mutex mt1;
std::mutex mt2;
std::mutex mt3;
std::mutex mt4;

std::function<void(int N)> PrintSumOfFirstNNumber = [](int N) -> void {
    int sum {0};
    for(int i = 1; i <= N; i++) {
        sum += i;
    }
    // std::cout << "Sum of first " << N << " numbers is: " << sum << std::endl;
    std::lock_guard<std::mutex> lg(mt1);
    std::cout << sum << std::endl;
};

std::function<void(std::vector<int>&)> FindEvensInVector = [](std::vector<int>& data) {
    std::lock_guard<std::mutex> lg(mt2);
    for(int value : data) {
        if(!(value%2)) {
            std::cout << value << " ";
        }
    }
    std::cout << std::endl;
};

std::function<std::array<int, 5>(std::future<int>&)> CreateArrayWithN = [](std::future<int>& ft) -> std::array<int, 5> {
    std::array<int, 5> result;
    int N = ft.get();
    for(int i=N; i<=N+5; i++) {
        result[i-N] = i;
    }
    return result;
};

std::function<void(std::array<int, 5>&)> SquareNUmbersInArray = [](std::array<int, 5>& data)->void {
    std::vector<int> results;
    for(int value : data) {
        results.emplace_back(value * value);
    }
    std::lock_guard<std::mutex> lg(mt3);
    for(int value : results) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
};

std::function<void(std::array<int, 5>&)> CubeNumbersInArray = [](std::array<int, 5>& data)->void {
    std::array<int, 5> results;
    std::lock_guard<std::mutex> lg(mt4);
    for(int i=0; i<data.size(); i++) {
        results[i] = data[i] * data[i] * data[i];
        std::cout << results[i] << " ";
    }
    std::cout << std::endl;
};