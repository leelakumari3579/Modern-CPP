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
    std::vector<int> _n;
    std::mutex mt;
    bool _flag{false};
    std::condition_variable cv;
public:
    ThreadHandler() = default;
    ThreadHandler(const ThreadHandler &) = default;
    ThreadHandler &operator=(const ThreadHandler &) = delete;
    ThreadHandler &operator=(ThreadHandler &&) = delete;
    ThreadHandler(ThreadHandler &&) = delete;
    ~ThreadHandler() = default;

    //parameterized constructor
    ThreadHandler(std::vector<int> n) :_n(n){}

    //member functions
    void InputCapture(std::vector<int>& data);
    void Operation();

    std::vector<int> n() const { return _n; }
    void setN(const std::vector<int> &n) { _n = n; }

    bool flag() const { return _flag; }
    void setFlag(bool flag) { _flag = flag; }

    friend std::ostream &operator<<(std::ostream &os, const ThreadHandler &rhs);

};



#endif // THREADHANDLER_H
