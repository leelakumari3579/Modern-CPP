#ifndef HR_HPP
#define HR_HPP
#include "Employee.hpp"
#include "HRSpecialization.hpp"
#include <ostream>

/*
    [most lenient]
    PUBLIC: 

    PROTECTED:

    [most strict]
    PRIVATE:
*/

/*
    PROTECTED INHERITANCE
    Base Class: private---> protected (reducing security) {not allowed}
                protected---> protected OKAY
                public-----> protected (increasing security)

    PUBLIC INHERITANCE
                private (base class) ----> public (child) [NOT ALLOWED] 
                protected (base class) ---> public (child) [NOT ALLOWED] [stay allowed]
                public (base class) ----> public (child) [ALLOWED]   
*/
class HR : public Employee
{
private:
    int _teamSize {0};
    HRSpecialization _hrSpecialization {HRSpecialization::TAG};
public:
    HR() = default;
    HR(const HR&) = default;  //copy constructor
    HR& operator=(const HR&) = delete;
    HR(HR&&) = delete; //moving constructor
    HR& operator=(HR&&) = delete;
    ~HR(){std::cout<<"hr distructor"<<std::endl;}

    HR(int id, std::string name, float salary,int size, HRSpecialization specialization);

    float CalculateTax() override;

    int teamSize() const { return _teamSize; }
    void setTeamSize(int teamSize) { _teamSize = teamSize; }

    HRSpecialization hrSpecialization() const { return _hrSpecialization; }
    void setHrSpecialization(const HRSpecialization &hrSpecialization) { _hrSpecialization = hrSpecialization; }

    friend std::ostream &operator<<(std::ostream &os, const HR &rhs);
};



#endif // HR_HPP
