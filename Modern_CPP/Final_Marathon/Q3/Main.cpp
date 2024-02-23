#include "ThreadHandler.h"

int main() {
    ThreadHandler ob(10);
    std::thread th1(&ThreadHandler::Operation, &ob);
    std::thread th2(&ThreadHandler::InputCapture, &ob);
    if(th1.joinable()) 
        th1.join();
    if(th2.joinable()) 
        th2.join();
}