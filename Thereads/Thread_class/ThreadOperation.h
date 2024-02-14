#ifndef THREADOPERATION_H
#define THREADOPERATION_H
#include <thread>
#include <mutex>
#include <ostream>
#include <condition_variable>

class ThreadOperation
{
private:
    std::mutex mt; //declaration
    int _cube_val {-1};
    bool _cube_val_avilable {false};
    int _value;
    std::condition_variable cv;
public:
    ThreadOperation() = delete;
    ThreadOperation(const ThreadOperation&) = delete;
    ThreadOperation& operator=(const ThreadOperation&) = delete;
    ThreadOperation(ThreadOperation&&) = delete;
    ThreadOperation& operator=(ThreadOperation&&) = delete;
    ~ThreadOperation() = default;

    void Square();

    //consumer
    void Cube();

    //producer
    void Produce_value_for_cube();

    int value() const { return _value; }
    void setValue(int value) { _value = value; }

    friend std::ostream &operator<<(std::ostream &os, const ThreadOperation &rhs);

    explicit ThreadOperation(int val) : _value(val) {}

};



#endif // THREADOPERATION_H
