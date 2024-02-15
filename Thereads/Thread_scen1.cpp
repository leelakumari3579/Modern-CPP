/*
    Scenario1: I have a main program which includes a function that can be executed prallel to main
    or concurrent to main without any dependency on main

    use: since there is no write to shared memory, use std::thread with no synchronization primitve
*/



/*
    step1: check const & reference to what type?
        std::array<int,2>
    step2: look at the class for this typw, is it
        copy constructable, move construtable or both?
    step3: if only copy is enabled, user must lvalue
           if only move is enabled, copy is not allowed, only rvalue
           if both are avilable, user can pass both lvalue of array and rvalue of array
*/


// void Square(const std::array<int, 5>& data)
// {
//     std::for_each(
//         data.begin(),
//         data.end(),
//         [](const int& num) {
//             std::cout<<num*num<<"..........\n";
//         }
//     );
// }

// int main()
// {
//     std::cout<<"hello\n";
    
//     std::array<int,5> result;
//     std::array<int,5> data{10,20,30,30,40};
//     int i=0;
//     std::thread t1(Square, std::ref(data));

//     /*
//         main thread operation
//     */
//     std::for_each(
//         data.begin(),
//         data.end(),
//         [&](const int& num) {
//             result[i] =  num*num*num;
//             i++;
//             //std::cout<<result[i]<<"++++++++++\n";
//         }
//     );

//     t1.join();

//     std::for_each(
//         data.begin(),
//         data.end(),
//         [&](const int& num) {
//             std::cout<<result[i]<<"**********\n";
//             i++;
//         }
//     );
// }


#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>


std::mutex mt;

void Square(const std::array<int, 5>& data){
    std::for_each(
        data.begin(),
        data.end(),
        [](const int& val) {
            std::lock_guard<std::mutex> lk(mt);
            std::cout << "Square : " << val * val << "\n";
        }
    );
}

void Cube(const std::array<int, 5>& data){
    std::for_each(
        data.begin(),
        data.end(),
        [](const int& val) {
            std::lock_guard<std::mutex> lk(mt);
            std::cout << "Cube : " << val * val * val << "\n";
        }
    );
}

int main() {
    std::array<int, 5> data {1,2,3,4,5};
    std::array<int, 5> result;

    int i {0};
    std::thread t1(Square,std::ref(data));
    std::for_each(
        data.begin(),
        data.end(),
        [&](const int& val) {
            // std::lock_guard<std::mutex> lk(mt);
            result[i++] = val * val;
        }
    );
    t1.join();

    i=0;
    std::thread t2(Cube,std::ref(data));
    std::for_each(
        data.begin(),
        data.end(),
        [&](const int& val) {
            // std::lock_guard<std::mutex> lk(mt);
            result[i++] = val * val * val;
        }
    );
    t2.join();

}