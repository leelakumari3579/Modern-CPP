#include <iostream>

#include "Hospital.h"
#include "Doctor.h"

// Global Function
void printTax(Doctor doctors[], int size) {
    float max = doctors[0].doctorFees();
    Doctor temp;
    for(int i=1; i<size; i++) {
        if(doctors[i].doctorFees() > max) {
            max = doctors[i].doctorFees();
            temp = doctors[i];
        }
    }
    temp.calculateTax();
}

// Global Function
void searchByName(Doctor doctors[], int size, std::string name) {
    for(int i=0; i<size; i++) {
        if(doctors[i].doctorName() == name) {
            std::cout<<name<<" works at "<<doctors[i].hospitalName()<<std::endl;
            break;
        }
    }
}

// Global Function
void searchByRating(Hospital hospitals[], int size, enum rating rating) {
    int flag = 0;
    for(int i=0; i<size; i++) {
        if(hospitals[i].hospitalRating() == rating) {
            std::cout<<hospitals[i];
            flag = 1;
        }
    }
    if(flag == 0) {
        if(rating == Good) {
            std::cout<<"No hospitals with rating Good."<<std::endl;
        } else if(rating == Poor) {
            std::cout<<"No hospitals with rating Poor."<<std::endl;
        } else if(rating == Average) {
            std::cout<<"No hospitals with rating Average."<<std::endl;
        }
    }
}

// Driver Code
int main() {
    int numOfHospitals, numOfDoctors, rating;
    std::string name;
    std::cout<<"Enter the number of hospital records to be stored: ";
    std::cin>>numOfHospitals;

    Hospital hospitals[numOfHospitals];
    for(int i=0; i<numOfHospitals; i++)
        hospitals[i].accept();

    std::cout<<"Enter the number of Doctor records to be stored: ";
    std::cin>>numOfDoctors;

    Doctor doctors[numOfDoctors];
    for(int i=0; i<numOfDoctors; i++)
        doctors[i].accept();

    printTax(doctors, numOfDoctors);

    std::cout<<"Enter the name of the doctor to find out where he works: ";
    std::cin>>name;

    searchByName(doctors, numOfDoctors, name);

    std::cout<<"Enter the rating of the hospital: "<<std::endl;
    std::cout<<"1->Good\n2->Average\n3->Poor"<<std::endl;
    std::cin>>rating;

    if(rating == 1) {
        searchByRating(hospitals, numOfHospitals, Good);
    } else if(rating == 2) {
        searchByRating(hospitals, numOfHospitals, Average);
    } else if(rating == 3) {
        searchByRating(hospitals, numOfHospitals, Poor);
    }
}