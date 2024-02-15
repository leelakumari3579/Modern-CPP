// #include "Functionalities.h"

// void Square(ThreadContainer &data)
// {
//     for (ThreadPointer &itr : data)
//     {
//         std::lock_guard<std::mutex> lg(mt);
//         std::cout << "Square: " << itr->value() * itr->value() << "\n";
//     }
// }

// void Cube(ThreadContainer &data)
// {
//     for (ThreadPointer &itr : data)
//     {
//         std::unique_lock<std::mutex> lk(mt);
//         cv.wait(lk, [&]()
//                 { return itr->cubeValAvilable(); });
//         std::cout << "Cube: " << itr->value() * itr->value() * itr->value() << "\n";
//     }
// }

// void Producer_value_cube(ThreadContainer &data)
// {
//     for (ThreadPointer &itr : data)
//     {
//         std::cout<<"enter the value: ";
//         itr->setValue(2);
//         itr->setCubeValAvilable(true);
//         cv.notify_one();
//     }
// }
