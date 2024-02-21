#ifndef FUNCTIONALITIES_HPP
#define FUNCTIONALITIES_HPP

#include <thread>
#include <array>
#include <functional>
#include <vector>
#include <future>
#include <iostream>
#include <mutex>

using ThreadContainer = std::array<std::thread, 5>;



extern std::function<void(int N)> PrintSumOfFirstNNumber;

extern std::function<void(std::vector<int>&)> FindEvensInVector;

extern std::function<std::array<int, 5>(std::future<int>&)> CreateArrayWithN;

extern std::function<void(std::array<int, 5>&)> SquareNUmbersInArray;

extern std::function<void(std::array<int, 5>&)> CubeNumbersInArray;

#endif // FUNCTIONALITIES_HPP
