#include "Functionalities.h"
#include <algorithm>
#include <numeric>
#include "EmptyContainerException.h"
#include "NoMatchingInstanceException.h"

void CreateObjects(AutomobileContainer &data)
{
    data.fill(std::make_shared<Automobile>("202","BMW",Category::PRIVATE,70000.0f,"SUV"));
    data.fill(std::make_shared<Automobile>("203","HONDA",Category::TRANSPORT,18000.0f,"SEDAN"));
    data.fill(std::make_shared<Automobile>("102","HYUNDI",Category::DEFENSE,27000.0f,"SUV"));
}

float GreenPassCostById(AutomobileContainer &data, std::string id)
{
    if(data.empty())
        throw EmptyContainerException("Container is empty!!");
    auto ans = std::find_if(
        data.begin(),
        data.end(),
        [&](AutomobilePointer& data){
            return data->id() == id;
        }
    );
    if(ans == 0)
        throw NoMatchingInstanceException("there is no matching data!!");
    return (*ans)->GreenPassCost();
}

float AveragePrice(AutomobileContainer &data)
{
    if(data.empty())
        throw EmptyContainerException("Container is empty!!");
    int count = 0;
    auto sum = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](float total, AutomobilePointer& data){
            count++;
            return total + data->price();
        }
    );
    if(sum == 0)
        throw NoMatchingInstanceException("there is no matching data!!");
    return sum/count;
}

PrivilegeCategory DisplayFindPrivilegeType(AutomobileContainer &data)
{
    if(data.empty())
        throw EmptyContainerException("Container is empty!!");
    auto ans = std::find_if(
        data.begin(),
        data.end(),
        [](AutomobilePointer& data){
            return data->category();
        }
    );
    if(ans == 0)
        throw NoMatchingInstanceException("there is no matching data!!");
    return ans->get()->FindPrivilegeType();
}

