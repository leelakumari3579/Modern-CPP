#include <iostream>
#include "Doctor.h"

// DEfault Constructor
Doctor::Doctor(): Hospital(), doctor_id("0"), doctor_name("Anonymous"), doctor_speciality("NIL"), registered_hospital_name("NA"), doctor_fees(0.0f) {}

// Para Constructor
Doctor::Doctor(std::string hospital_id, std::string hospital_name, rating hospital_rating, std::string doctor_id, std::string doctor_name, std::string doctor_speciality, std::string registered_hospital_name, float doctor_fees) {
    Hospital(hospital_id, hospital_name, hospital_rating);
    this->doctor_id = doctor_id;
    this->doctor_name = doctor_name;
    this->doctor_speciality = doctor_speciality;
    this->registered_hospital_name = registered_hospital_name;
    this->doctor_fees = doctor_fees;
}

// User-Defined Function.
float Doctor::calculateTax() {
    return 0.20 * doctor_fees;
}

// Operator << Overloading
void operator<<(std::ostream &out, Doctor &d) {
    Hospital h = (Hospital)d;
    out<<h;
    out<<"Doctor ID: "<<d.doctor_id<<std::endl;
    out<<"Doctor Name: "<<d.doctor_name<<std::endl;
    out<<"Doctor Speciality: "<<d.doctor_speciality<<std::endl;
    out<<"Registered Hospital of the Doctor: "<<d.registered_hospital_name<<std::endl;
    out<<"Fees of the Doctor: "<<d.doctor_fees<<std::endl;    
}

// User-Defined Function.
void Doctor::accept() {
    Hospital::accept();
    std::cout<<"Enter the ID of the doctor: ";
    std::cin>>doctor_id;

    std::cout<<"Enter the name of the doctor: ";
    std::cin>>doctor_name;

    std::cout<<"Enter the name of the registered hospital where doctor works: ";
    std::cin>>registered_hospital_name;

    std::cout<<"Enter the consulting fees of the doctoer: ";
    std::cin>>doctor_fees;

    std::cout<<"\nDoctor's Record Added successfully!"<<std::endl;
}