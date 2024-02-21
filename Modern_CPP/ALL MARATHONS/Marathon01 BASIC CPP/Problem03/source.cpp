#include<iostream>
#include<cstring>
#include "header.h"

// Player Default Constructor
Player::Player() {
    playerID = 0;
    pname = new char[10];
    strcpy(pname, "Anonymous");
    for(int i=0; i<3; i++) {
        scores[i] = 0;
    }
}

// Player Parameterized Constructor
Player::Player(int playerId, const char* name, int *scores_) {
    this->playerID = playerId;
    pname = new char[strlen(name) + 1];
    strcpy(pname, name);
    for(int i=0; i<3; i++) {
        scores[i] = scores_[i];
    }
}

// Player Copy Constructor
Player::Player(Player &p) {
    playerID = p.playerID;
    pname = new char[strlen(p.pname) + 1];
    strcpy(pname, p.pname);
    for(int i=0; i<3; i++) {
        scores[i] = p.scores[i];
    }
}

// Method to calculate average scores.
float Player::calculateAverageScores() {
    int sum=0;
    for(int i=0; i<3; i++) {
        sum += scores[i];
    }
    return sum/3.0f;
}

// Method to accept and initialize Players.
void Player::accept() {
    std::cout<<"Enter the ID of the player: ";
    std::cin>>playerID;

    std::cout<<"Enter the name of the player: ";
    std::cin>>pname;

    std::cout<<"Enter the scores of the player: ";
    for(int i=0; i<3; i++) {
        std::cin>>scores[i];
    }

    std::cout<<"\n\n\t\t***Record created successfully***\n"<<std::endl;
}

// Method to display Players.
void Player::display() {
    std::cout<<"Player ID: "<<playerID<<std::endl;
    std::cout<<"Player Name: "<<pname<<std::endl;
    std::cout<<"Player Scores: ";
    for(int i=0; i<2; i++) {
        std::cout<<scores[i]<<", ";
    }
    std::cout<<scores[2]<<std::endl;
    std::cout<<std::endl;  
}

// Method to overload == operator
bool Player::operator==(Player &p) {
    return (strcmp(this->pname, p.pname) == 0 ? true : false);
}

// Method to overload [] operator
char& Player::operator[](int index) {
    return pname[index];
}

// Method to overload < operator
bool Player::operator<(Player &p) {
    return (calculateAverageScores() < p.calculateAverageScores() ? true : false);
}

// Method to overload << operator
void operator<<(std::ostream &out, Player &p) {
    out<<"Player ID: "<<p.playerID<<std::endl;
    out<<"Player Name: "<<p.pname<<std::endl;
    out<<"Player Scores: ";
    for(int i=0; i<2; i++) {
        out<<p.scores[i]<<", ";
    }
    out<<p.scores[2]<<std::endl;
}

// Method to demonstrate Destructor.
Player::~Player() {
    delete pname;
}