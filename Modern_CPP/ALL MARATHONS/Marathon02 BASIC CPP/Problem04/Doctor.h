#ifndef DOCTOR_H
#define DOCTOR_H

#include <iostream>
#include "Hospital.h"

class Doctor : public Hospital {
    std::string doctor_id;
    std::string doctor_name;
    std::string doctor_speciality;
    std::string registered_hospital_name;
    float doctor_fees;

    public:
        // Constructors
        Doctor();
        Doctor(std::string, std::string, enum rating, std::string, std::string, std::string, std::string, float);

        // Getters and Setters.
        std::string doctorId() const { return doctor_id; }
        void setDoctorId(const std::string &doctorId) { doctor_id = doctorId; }

        std::string doctorName() const { return doctor_name; }
        void setDoctorName(const std::string &doctorName) { doctor_name = doctorName; }

        std::string doctorSpeciality() const { return doctor_speciality; }
        void setDoctorSpeciality(const std::string &doctorSpeciality) { doctor_speciality = doctorSpeciality; }

        std::string registeredHospitalName() const { return registered_hospital_name; }
        void setRegisteredHospitalName(const std::string &registeredHospitalName) { registered_hospital_name = registeredHospitalName; }

        float doctorFees() const { return doctor_fees; }
        void setDoctorFees(float doctorFees) { doctor_fees = doctorFees; }  

        // User-Defined Functions
        float calculateTax();
        friend void operator<<(std::ostream &, Doctor &);
        void accept();
};

#endif // DOCTOR_H
