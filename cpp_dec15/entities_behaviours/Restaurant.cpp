#include<iostream>
#include<string>
class Restaurant
{
    private:
        std::string menu[10];
        int menuCount;
    public:
        Restaurant()
        {
            menuCount=0;
        }
    void addMenuItem(std::string item)
    {
        if(menuCount<10)
        {
            menu[menuCount]=item;
            std::cout<<"added '"<<item<<"' to the menu."<<std::endl;
            menuCount++;
        }
        else
        {
            std::cout<<"menu is full. cannot add '"<<item<<"'"<<std::endl;
        }
    }
    void displayMenu()
    {
        std::cout<<"menu: "<<std::endl;
        for(int i=0;i<menuCount;i++)
        {
            std::cout<<"- "<<menu[i]<<std::endl;
        }
    }
    void serverCustomer(std::string item)
    {
        std::cout<<"serving '"<<item<<"' to customer."<<std::endl;
    }
};
int main()
{
    Restaurant myRestaurent;
    myRestaurent.addMenuItem("bhiryani");
    myRestaurent.addMenuItem("Pizza");
    myRestaurent.addMenuItem("burger");
    myRestaurent.displayMenu();
    myRestaurent.serverCustomer("pizza");
    return 0;
}