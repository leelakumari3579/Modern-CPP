#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cstring>

class Player {
    int playerID;
    char *pname;
    int scores[3];

    public:

        // Default Constructor Definition
        Player();

        // Parameterized Constructor Definition
        Player(int, const char *, int []);

        // Copy Constructor
        Player(Player &);

        //Getters and Setters.
        int getPlayerID() const { return playerID; }
        void setPlayerID(int playerID_) { playerID = playerID_; }

        char *getPname() { return pname; }
        void setPname(char *pname_) { 
            strcpy(pname, pname_);
        }

        int *getScores() { return scores; }
        void setScores(int *scores_) { 
            for(int i=0; i<3; i++) {
                scores[i] = scores_[i];
            }
        }

        //User Defined Declaration
        float calculateAverageScores();
        void accept();
        void display();

        // Declarations for operator overloading.
        bool operator==(Player &);
        char& operator[](int index);
        bool operator<(Player &);
        friend void operator<<(std::ostream &, Player &);

        //Destructor Declaration
        ~Player();


};

#endif // HEADER_H
