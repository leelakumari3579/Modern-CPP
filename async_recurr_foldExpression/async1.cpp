#include <iostream>
#include <vector>
#include <stdexcept>
#include <future>

// concurrency in action --->BOOK more about threads

/*
    SOC (system on chip)
        -cores: one available working node in the microprocessor
        -thread: a set of instructions to be executed
*/

float AverageOfNumbers(std::future<int>& ft)
{
    std::vector<int> data{10, 20, 30, 40, 50};

    //Make Average thread wait (go on hold) till ft.get() retruns a signal
    //If there is any data in future, we can save it in N.
    int n = ft.get();

    // n value should be less than vector of numbers
    if (data.size() < n || n <= 0)
    {
        throw std::runtime_error("invalid N!!!");
    }
    float ans = 0.0f;
    int count = 0;
    
    // for(auto itr = data.begin();count<n;count++)
    // {
    //     ans = ans + *itr;
    //     itr++;
    // }

    for(int val : data)
    {
        ans = ans + val;
        count++;
        if(count == n)
        {
            break;
        }
    }
    return ans/n;
}

int main()
{
    std::promise<int> pr; //i make a promise to give you integer
    std::future<int> ft = pr.get_future(); //the promise will fullfilled in future

    //any parameter we pass in async, bind or thread with a funtion pointer
    //SUCH THAT parameter must be received by the function REFERENCE
    //YOU MUST PASS SUCH PARAMETERS BY USING std::ref
    std::future<float> result = std::async(std::launch::async, AverageOfNumbers, std::ref(ft)); // async(launch policy)-->used to run paralally but different threads

    int val {0};
    std::cin>>val;

    pr.set_value(val);

    std::cout<<result.get()<<"\n";
}

/*
    step1: enter the car. start the sccessories of the car.
    step2: 2 activities
        a) sync phone data with car
        b) find directions to my destination
*/

/*  &x : reference of x or pointer of x
    if there is no data type to the left of x, it is pointer
    int& x : this is reference to int

     _/\___/\_
    /        \
    [<.>  <.>]       /\_/\         /\/\
    |   \/   |      ( . . )       (.  .)
    |  (--)  |       \ ! /   \    (    )
    \___  ___/       /   \   /    ( /\ )
        \/          /     \ /
                   (   .   )
*/

/*
    Question: i have 2 classes with attributes and member functions
              i want access of both these set of members in a new class called XYZ
              what mechanisam of OOP will you use to achieve this and why?
    ans: multiple inheritance(WRONG), composition,
*/