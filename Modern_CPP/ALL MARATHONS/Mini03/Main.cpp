#include "Functionalities.hpp"

int main() {

    std::array<std::thread, 4> threads;
    int N=5;
    std::vector<int> Vector {1,2,3,4,5,6};
    std::array<int, 5> Array {1,2,3,4,5};

    std::cout << "Sum of first 5 positive numbers is: ";
    threads[0] = std::thread(PrintSumOfFirstNNumber, std::ref(N));
    std::cout << std::endl;


    std::cout << "Finding even numbers in the vector passed: ";
    threads[1] = std::thread(FindEvensInVector, std::ref(Vector));
    std::cout << std::endl;


    std::cout << "Generating 5 numbers starting from: " << N << std::endl;
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    std::future<std::array<int, 5>> result = std::async(std::launch::async, CreateArrayWithN, std::ref(ft));
    pr.set_value(N);
    for(int val : result.get()) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Squaring the numbers in the array: ";
    threads[2] = std::thread(SquareNUmbersInArray, std::ref(Array));
    std::cout << std::endl;

    std::cout << "Cubing the numbers in the array: ";
    threads[3] = std::thread(CubeNumbersInArray, std::ref(Array));
    std::cout << std::endl;

    for(std::thread& th : threads) {
        if(th.joinable())   th.join();
    }


}