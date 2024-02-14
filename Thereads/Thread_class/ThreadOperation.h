#ifndef THREADOPERATION_H
#define THREADOPERATION_H
#include <thread>
#include <mutex>
#include <ostream>

class ThreadOperation
{
private:
    std::mutex mt; //declaration
    int _value;
public:
    ThreadOperation() = delete;
    ThreadOperation(const ThreadOperation&) = delete;
    ThreadOperation& operator=(const ThreadOperation&) = delete;
    ThreadOperation(ThreadOperation&&) = delete;
    ThreadOperation& operator=(ThreadOperation&&) = delete;
    ~ThreadOperation() = default;

    void Square();
    void Cube();

    int value() const { return _value; }
    void setValue(int value) { _value = value; }

    friend std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs);

    explicit ThreadOperation(int val) : _value(val) {}

};



#endif // THREADOPERATION_H
