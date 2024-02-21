#ifndef HOSPITAL_H
#define HOSPITAL_H

#include <iostream>

// Enum Declaration for Hospital Rating
enum rating {
    Good,
    Average,
    Poor
};

// Class Definition
class Hospital {
    std::string hospital_id;
    std::string hospital_name;
    enum rating hospital_rating;

    public:
        // Constructors
        Hospital();
        Hospital(std::string, std::string, rating hospital_rating);

        // Getters and Setters.
        std::string hospitalId() const { return hospital_id; }
        void setHospitalId(const std::string &hospitalId) { hospital_id = hospitalId; }

        std::string hospitalName() const { return hospital_name; }
        void setHospitalName(const std::string &hospitalName) { hospital_name = hospitalName; }

        enum rating hospitalRating() const { return hospital_rating; }
        void setHospitalRating(const enum rating &hospitalRating) { hospital_rating = hospitalRating; }

        // Function Overloading.
        friend void operator<<(std::ostream &, Hospital &);
        void accept();
};

#endif // HOSPITAL_H
