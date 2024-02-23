#ifndef THREADHANDLER_H
#define THREADHANDLER_H

#include <vector>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <ostream>


class ThreadHandler
{
private:
    std::mutex _mt;
    std::condition_variable _cv;
    int _N;
    bool _isValAvailable;
public:
    ThreadHandler() = default;
    ThreadHandler(const ThreadHandler &) = default;
    ThreadHandler &operator=(const ThreadHandler &) = delete;
    ThreadHandler &operator=(ThreadHandler &&) = delete;
    ThreadHandler(ThreadHandler &&) = delete;
    ~ThreadHandler() = default;

    explicit ThreadHandler(int val) : _N(val) { }

    void Operation();

    bool InputCapture();


};



#endif // THREADHANDLER_H
