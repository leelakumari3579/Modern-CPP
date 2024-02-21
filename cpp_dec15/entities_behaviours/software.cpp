#include<iostream>
class software
{
private:
    std::string softwareName;
    int version;
    bool isActivated;
public:
    software(std::string name,int initialVersion)
    {
        softwareName = name;
        version = initialVersion;
        isActivated = false;
    }
    void upgradeSoftware()
    {
        version++;
        std::cout<<"upgraded "<<softwareName<<" to version "<<version<<std::endl;
    }
    void activateSoftware()
    {
        if(!isActivated)
        {
            isActivated=true;
            std::cout<<softwareName<<" is activated."<<std::endl;
        }
        else
        {
            std::cout<<softwareName<<" is already activated."<<std::endl;
        }
    }
    void deactivateSoftware()
    {
        if(isActivated)
        {
            isActivated=false;
            std::cout<<" is deactivated."<<std::endl;
        }
        else
        {
            std::cout<<" is already deactivated."<<std::endl;
        }
    }
    void displaySoftware()
    {
        std::cout<<"software name: "<<softwareName<<std::endl;
        std::cout<<"version: "<<version<<std::endl;
        std::cout<<"activation status: "<<(isActivated ? "activated":"deactivated")<<std::endl;
    }
};

int main()
{
    software mySoftware("linux",1);
    mySoftware.displaySoftware();
    mySoftware.upgradeSoftware();
    mySoftware.activateSoftware();
    mySoftware.deactivateSoftware();
    mySoftware.displaySoftware();
    return 0;
}