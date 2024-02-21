#include<iostream>
#include<cstring>
#include "header.h"

int main() {
    
    // 3 arrays of marks for 3 players.
    int p1[3] = {33, 34, 35};
    int p2[3] = {37, 38, 39};
    int p3[3] = {39, 41, 40};


    // Initialization of Objects in stack.
    Player pl1(101, "Kartik", p1);
    Player pl2(102, "Aashutosh", p2);
    Player pl3(103, "Mallikarjun", p3);
    Player pl4(pl3);


    // Displaying all the operators with << operator.
    std::cout<<"Displaying all the players: "<<std::endl;
    pl1.display();
    pl2.display();
    pl3.display();
    pl4.display();

    // Demonstrating == operator overloading.
    std::cout<<"\n\nChecking if names of 1st and 2nd player are equal: ";
    (pl1 == pl2) ?
        std::cout<<"Names of players 1 and 2 are same, i.e : "<<pl1.getPname()<<std::endl :
        std::cout<<"Names of players 1 and 2 are not same, i.e : "<<pl1.getPname()<<" and "<<pl2.getPname()<<std::endl;

    // std::cout<<std::endl;

    std::cout<<"\n\nChecking if names of 3rd and 4th player are equal: ";
    (pl3 == pl4) ?
        std::cout<<"Names of players 2 and 2 are same, i.e : "<<pl1.getPname() :
        std::cout<<"Names of players 2 and 3 are not same, i.e : "<<pl3.getPname()<<" and "<<pl4.getPname();

    // Demonstrating < operator overloading.
    std::cout<<"\n\nChecking if average of 1st is less than 2nd player: ";
    pl1 < pl2 ?
        std::cout<<"True: "<<pl1.calculateAverageScores()<<" < "<<pl2.calculateAverageScores()<<std::endl :
        std::cout<<"False: "<<pl1.calculateAverageScores()<<" > "<<pl2.calculateAverageScores()<<std::endl;

    std::cout<<std::endl;

    // Demonstrating [] operator overloading.
    std::cout<<"Demonstrating overloading of subscript-[] operator"<<std::endl;
    std::cout<<"\nTrying to modify name of the first player. Present name: "<<pl1.getPname()<<std::endl;
    std::cout<<"\nCharacter at 3rd index: "<<pl1[2]<<std::endl;
    std::cout<<"Changing it to: 'X'"<<std::endl;
    pl1[2] = 'X';
    std::cout<<"Name after changing: "<<pl1.getPname()<<std::endl; 

}