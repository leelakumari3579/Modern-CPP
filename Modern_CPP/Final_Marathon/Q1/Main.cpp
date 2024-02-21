#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingInstanceException.h"

int main()
{
    AutomobileContainer data;
    Automobile autoData;
    CreateObjects(data);
    autoData.FindPrivilegeType();
    autoData.GreenPassCost();
    try
    {
        std::cout << "Green Pass cost Based on id: " << GreenPassCostById(data, "102") << "\n";
        std::cout << "" << AveragePrice(data) << "\n";
        auto ans = DisplayFindPrivilegeType(data);
        switch (ans)
        {
        case PrivilegeCategory::GOVT:
            std::cout << "Govt"
                      << "\n";
            break;
        case PrivilegeCategory::PERSONAL:
            std::cout << "Personal"
                      << "\n";
            break;
        case PrivilegeCategory::VIP:
            std::cout << "Vip"
                      << "\n";
            break;

        default:
            break;
        }
    }
    catch (EmptyContainerException &ex1)
    {
        std::cout << ex1.what() << '\n';
    }
    catch (NoMatchingInstanceException &ex2)
    {
        std::cout << ex2.what() << '\n';
    }
}