#include <iostream>
#include <queue>
#include <vector>
 
//Functor object!!!!!!:   class in which overloaded () is available

struct Less_Equal_Comparator  //gives data in ascending order
{
    bool operator()(int a, int b)
    {
        return a >= b;
    };
};

//min heap: a, b   a will be before b in a min heap if a is greater than b
//max heap: a, b   a will be before b in a max heap if a is less than b
//a is the new value to be added

/*
    pq {11}
    add 25.  a=25, b=11
*/

int main()
{
    std::vector<int> data{11,11,22,13,22,13,11,22};

    std::priority_queue<int, std::vector<int>, Less_Equal_Comparator> pq (data.begin(), data.end());
    while(!pq.empty())
    {
        std::cout<<"Popping: "<<pq.top()<<"\n";
        pq.pop();
    }

    // std::priority_queue<int> pq(data.begin(), data.end());
    // std::cout<<pq.top()<<"\n";
    // pq.push(13);
    // std::cout<<pq.top()<<"\n";
    // pq.pop();
    // std::cout<<pq.top()<<"\n";
}


/*
    std::map: 
        a) key-value pairs for inserting data into the container
        b) order of insertion and order of sccess are same
            i.e elements can be retrieved in the were order
            in the same order as they were inserted

        {1, "leela"}, {2,"nani"}, {3, "vsls"}
    
    - implemented using a tree-based structure (e.g: Red_Black Tree)

    
    std::unordered_map: 
        a) key- value pairs for inserting data into the container
        b) order of insertion and access may not be same

    - Implemented using HashTable( based on some implementing container)


    std::set : Implemented by using of Red_Black Tree
        In a set, a key can only appear once (giving the illusion of uniqueness of entries)


    Priority Queue: 

*/

/*
    Make a priority queue where objects of a class
    Automobile are stored via priority based on "Max Price First"

    the attributes of the class are as follows:
        _id: string
        _price: float
        _type: wither PRIVATE or COMMERTIAL
*/