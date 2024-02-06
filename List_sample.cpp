#include <iostream>
#include <array>
#include <list>
// std::ref
// std::bind

int main()
{
    /*
        std::array is a class in the namespace std
        <int, 2> are template arguments
        where int is type and 2 is fixed size of the array

        base address + (index * size of one element)

        Objective : find average of all entries in the styructure
        In Array:-
                1) intialize total to 0
                2) go to first location of array. add it to total
                3) go to second location(use formula). add it to total
                4) go to third location(use formula). add it to total
                5) divide total/3 and return value
        In Linkedlist:- 
                1) intialize total to 0
                2) find the first node (head node). fetch themiddle part of the node (value) add it to total
                3) now, go to next pointer part of the node. derefrence the pointer.
                    you arrive on 2nd node of the list.
                4) fetch the midlle part of the node(value) add it to total
                5) now, go to next pointer part  of the node. derefence the pointer.
                     you arrive on 3rd node of the list
                6) fetch the midlle part of the node(value) add it to total
                7) devide total by 3 and return the answer

        Objective: for each loop (range-based loop/iterative for loop)
                    SHOULD WORK!
        array iteration: 
            1)record and save the beginning of the array( pointer to base location) begin
            2)record the address JUST BEYOND THE LAST ITEM. this would be the terminating point for the array.
              call this as end
            3)put begin and end (along with other things) and make a iterator objcet
            4)now we can overload [] operator, ++ operator, --operator (and anything else we need). 
               these overload functions will include "LOGIC" for iteration
            5)now for each loop for(int val : arr) is equivalent
                    for(itr = arr.begin(); itr != arr.end(); itr++)
                        int val *= itr;

    */
    std::array<int, 2> arr {9,10};

    std::list<int> data {9,10};
    int total =0;
    for(int val : data)
        total = total + val;
    std::cout<<total/data.size()<<std::endl;
}