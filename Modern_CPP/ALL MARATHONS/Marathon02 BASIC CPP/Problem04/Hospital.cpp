#include "Hospital.h"

// Default Constructor.
Hospital::Hospital(): hospital_id("0"), hospital_name("NA"), hospital_rating(Average) {}

// Para Constructor
Hospital::Hospital(std::string hospital_id, std::string hospital_name, rating hospital_rating):
hospital_id{hospital_id}, hospital_name{hospital_name}, hospital_rating{hospital_rating} {}

// Operator << Overloading
void operator<<(std::ostream &out, Hospital &h) {
    out<<"Hospital ID: "<<h.hospital_id<<" Hospital Name: "<<h.hospital_name<<" Hospital Rating: "<<h.hospital_rating<<std::endl;
}

// User-Defined Accept Function.
void Hospital::accept() {
    int temp;

    std::cout<<"Enter the ID of the hospital: ";
    std::cin>>hospital_id;

    std::cout<<"Enter the name of the hospital: ";
    std::cin>>hospital_name;

    std::cout<<"Enter the rating of the hospital from 1 of the options below: ";
    std::cout<<"1->Good\n2->Average\n3->Poor"<<std::endl;
    std::cin>>temp;

    if(temp == 1) {
        hospital_rating = Good;
    } else if(temp == 2) {
        hospital_rating = Average;
    } else if(temp == 3) {
        hospital_rating = Poor;
    }

    std::cout<<"\nHospital Record Added Successfully!!"<<std::endl;
}