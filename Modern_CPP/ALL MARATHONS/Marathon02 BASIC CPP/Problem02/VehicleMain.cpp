#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"

void searchByChassisNumber(Vehicle *bikeInventory, int bsize, Vehicle *carInventory, int csize, std::string chassisNumber) {
    int flag=0;
    for(int i=0; i<bsize; i++) {
        if(bikeInventory[i].getVehicleChassisNumber() == chassisNumber) {
            bikeInventory[i].display();
            flag=1;
            break;
        }
    }

    for(int i=0; i<csize; i++) {
        if(carInventory[i].getVehicleChassisNumber() == chassisNumber) {
            carInventory[i].display();
            flag=1;
            break;
        }
    }
    if(!flag) {
        std::cout<<"\n\t\t***No Vehicle with Chassis Number "<<chassisNumber<<" found!!***"<<std::endl;
    }
}

int countByBikeCategory(Vehicle *inventory, int size, btype type) {
    int count=0;
    for(int i=0; i<size; i++) {
            Bike *temp = dynamic_cast<Bike*>(&inventory[i]);
            if(temp->getBikeType() == type) {
                count++;
            }
    }
    return count;
}

int countByCarCategory(Vehicle *inventory, int size, ctype type) {
    int count=0;
    for(int i=0; i<size; i++) {
            Car *temp = dynamic_cast<Car*>(&inventory[i]);
            if(temp->getCarType() == type) {
                count++;
            }
    }
    return count;
}

float calculateAverageByBikeCategory(Vehicle *inventory, int size, btype type) {
    float sum=0;
    for(int i=0; i<size; i++) {
        Bike *temp = dynamic_cast<Bike*>(&inventory[i]);
        if(temp->getBikeType() == type) {
            sum+=temp->getVehicleExShowroomPrice();
        }
    }
    return sum/size;
}

float calculateAverageByCarCategory(Vehicle *inventory, int size, ctype type) {
    float sum=0;
    for(int i=0; i<size; i++) {
        Car *temp = dynamic_cast<Car*>(&inventory[i]);
        if(temp->getCarType() == type) {
            sum+=temp->getVehicleExShowroomPrice();
        }
    }
    return sum/size;
}



int main() {
    int bsize, csize, vtype, vcat;
    std::string chassisNumber;

    std::cout<<"Enter the size of the bike inventory: ";
    std::cin>>bsize;

    std::cout<<"Enter the size of the car inventory: ";
    std::cin>>csize;


    Vehicle *bikeInventory = new Bike[bsize];
    Vehicle *carInventory = new Car[csize];

    std::cout<<"Enter the details for Bikes: "<<std::endl;
    for(int i=0; i<bsize; i++)
        bikeInventory[i].accept();

    std::cout<<std::endl<<std::endl;

    std::cout<<"Enter the details for Cars: "<<std::endl;
    for(int i=0; i<csize; i++)
        carInventory[i].accept();

    std::cout<<std::endl<<std::endl;

    std::cout<<"Enter the chassis number to seach for a vehicle: ";
    std::cin>>chassisNumber;

    searchByChassisNumber(bikeInventory, bsize, carInventory, csize, chassisNumber);

    std::cout<<"To get the count of vehicle with a particular category select the below option: \n"<<std::endl;
    std::cout<<"Enter 1 for Bike Categories."<<std::endl;
    std::cout<<"Enter 2 for Car Categories."<<std::endl;
    std::cin>>vtype;

    switch(vtype) {
        int count;
        case 1: std::cout<<"To get the count of Bike with a particular category select one of the below options: \n"<<std::endl;
                std::cout<<"Enter 1 for Commute Bike."<<std::endl;
                std::cout<<"Enter 2 for Sports Bike."<<std::endl;
                std::cout<<"Enter 3 for Offroader Bike."<<std::endl;
                std::cin>>vcat;

                switch(vcat) {
                    case 1: count = countByBikeCategory(bikeInventory, bsize, Commute);
                            std::cout<<"Vehicles (Bikes) with category Commute: "<<count<<std::endl;
                            break;
                    case 2: count = countByBikeCategory(bikeInventory, bsize, Sports);
                            std::cout<<"Vehicles (Bikes) with category Sports: "<<count<<std::endl;
                            break;
                    case 3: count = countByBikeCategory(bikeInventory, bsize, Offroader);
                            std::cout<<"Vehicles (Bikes) with category Offroader: "<<count<<std::endl;
                            break;
                    default: std::cout<<"Enter a right choice, please.";
                }
                
                break;
        case 2: std::cout<<"To get the count of Car with a particular category select one of the below options: \n"<<std::endl;
                std::cout<<"Enter 1 for SUV Car."<<std::endl;
                std::cout<<"Enter 2 for HatchBack Car."<<std::endl;
                std::cout<<"Enter 3 for Sedan Car."<<std::endl;
                std::cin>>vcat;

                switch(vcat) {
                    case 1: count = countByCarCategory(carInventory, csize, SUV);
                            std::cout<<"Vehicles (Cars) with category SUV: "<<count<<std::endl;
                            break;
                    case 2: count = countByCarCategory(carInventory, csize, HatchBack);
                            std::cout<<"Vehicles (Cars) with category HatchBack: "<<count<<std::endl;
                            break;
                    case 3: count = countByCarCategory(carInventory, csize, Sedan);
                            std::cout<<"Vehicles (Cars) with category Sedan: "<<count<<std::endl;
                            break;
                    default: std::cout<<"Enter a right choice, please.";
                }
                break;

        default: std::cout<<"Please enter a right choice.";
    }

    std::cout<<"To get the average price of vehicle with a particular category select the below option: \n"<<std::endl;
    std::cout<<"Enter 1 for Bike Categories."<<std::endl;
    std::cout<<"Enter 2 for Car Categories."<<std::endl;
    std::cin>>vtype;

    switch(vtype) {
        case 1: float average;
                std::cout<<"To get the count of Bike with a particular category select one of the below options: \n"<<std::endl;
                std::cout<<"Enter 1 for Commute Bike."<<std::endl;
                std::cout<<"Enter 2 for Sports Bike."<<std::endl;
                std::cout<<"Enter 3 for Offroader Bike."<<std::endl;
                std::cin>>vcat;

                switch(vcat) {
                    case 1: average = calculateAverageByBikeCategory(bikeInventory, bsize, Commute);
                            std::cout<<"Vehicles (Bikes) with category Commute: "<<average<<std::endl;
                            break;
                    case 2: average = calculateAverageByBikeCategory(bikeInventory, bsize, Sports);
                            std::cout<<"Vehicles (Bikes) with category Sports: "<<average<<std::endl;
                            break;
                    case 3: average = calculateAverageByBikeCategory(bikeInventory, bsize, Offroader);
                            std::cout<<"Vehicles (Bikes) with category Offroader: "<<average<<std::endl;
                            break;
                    default: std::cout<<"Enter a right choice, please.";
                }
                
                break;
        case 2: int count;
                std::cout<<"To get the average of Car with a particular category select one of the below options: \n"<<std::endl;
                std::cout<<"Enter 1 for SUV Car."<<std::endl;
                std::cout<<"Enter 2 for HatchBack Car."<<std::endl;
                std::cout<<"Enter 3 for Sedan Car."<<std::endl;
                std::cin>>vcat;

                switch(vcat) {
                    case 1: average = calculateAverageByCarCategory(carInventory, csize, SUV);
                            std::cout<<"Vehicles (Cars) with category SUV: "<<average<<std::endl;
                            break;
                    case 2: average = calculateAverageByCarCategory(carInventory, csize, HatchBack);
                            std::cout<<"Vehicles (Cars) with category HatchBack: "<<average<<std::endl;
                            break;
                    case 3: average = calculateAverageByCarCategory(carInventory, csize, Sedan);
                            std::cout<<"Vehicles (Cars) with category Sedan: "<<average<<std::endl;
                            break;
                    default: std::cout<<"Enter a right choice, please.";
                }
                break;

        default: std::cout<<"Please enter a right choice.";
    }


}