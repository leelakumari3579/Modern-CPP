#include "Employee.h"
#include <unordered_map>
#include <memory>

using EmprPointer = std::shared_ptr<Employee>;
using MapItem = std::pair<int, Employee>;
using MapContainer = std::unordered_map<int, Employee>;

void Display(MapContainer &data)
{
    for (auto &[k, v] : data)
    {
        std::cout << "key is: " << k << " value is : " << v << "\n";
    }

    for (auto itr = data.begin(); itr != data.end(); itr++)
    {
        std::cout << "key is: " << itr->first << " value is : " << *(itr->second) << "\n";
    }

    for (const MapItem &p : data)
    {
        std::cout << "key is: " << p.first << " value is : " << *(p.second) << "\n";
    }
}

int main()
{
    MapContainer data //;
        {
            std::make_pair<int, EmprPointer>(10, std::make_shared<Employee>(10, "harshit", "pune"))};

    // data.emplace(std::pair<int,Employee>(10,Employee(10,"harsit","pune")));
    data.emplace(std::make_pair<int, EmprPointer>(21, std::make_shared<Employee>(21, "rohan", "mumbai")));
    data.emplace(std::make_pair<int, EmprPointer>(33, std::make_shared<Employee>(33, "kaveri", "delhi")));

    Display(data);

    // search an item by key
    if (auto itr = data.find(10); itr != data.end())
    {
        std::cout << "employee with given ID found: " << *(itr->second) << "\n";
    }
    else
    {
        std::cout << "emplyee not found!..."
                  << "\n";
    }

    std::cout << "number of buckets: " << data.bucket_count() << "\n";
    std::cout << "maximum possible size of hash table: " << data.max_size() << "\n";
    std::cout << "size of bucket 0: " << data.bucket(0) << "\n"; // rows(buckets)
    std::cout << "in which bucket is key 10?: " << data.bucket(10) << "\n";
}

/*
    Applications of hash tables / hash functions / hashing

    a) Data Structures based on hash tables
        eg:- unordered_map or unordered_map

    b) cruptography: secures password
*/