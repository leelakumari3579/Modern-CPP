#include "Functionalities.h"
#include <thread>
#include <array>
#include <future>

int main()
{

    MapContainer data;
    AccountContainer accounts;

    //std::array<std::thread,5> threadsArr;

    std::future<void> r1 = std::async(std::launch::async, CreateObjects, std::ref(accounts), std::ref(data));
    //CreateObjects(accounts, data);
    try
    {
        std::future<float> r2 = std::async(std::launch::async, FindBankBalance, std::ref(data));
        //float ans = FindBankBalance(data);
        //std::cout << "total balance: " << ans << "\n";

        std::future<unsigned int> r3 = std::async(std::launch::async, CountAbove50000BalanaceAccounts, std::ref(data));
        // int count = CountAbove50000BalanaceAccounts(data);
        // std::cout << "count of above 50000.0f accounts: " << count << "\n";

        std::future<bool> r4 = std::async(std::launch::async, IsAnyAccountWithNoCard, std::ref(data));
        bool flag = r4.get();
        // if (bool ans = IsAnyAccountWithNoCard(data); ans)
        //     std::cout << "At least one accunt with null card exists!\n ";
        // else
        //     std::cout << "no account exists\n";

        std::future<std::optional<float>> r5 = std::async(std::launch::async, FindBalanceById, std::ref(data), 34567890L);
        
        std::cout<<"Total balance: "<<r2.get()<<"\n";
        std::cout<<"count of above 50000.0f accounts: "<<r3.get()<<"\n";

        if(flag)
            std::cout<< "At least one accunt with null card exists!\n ";
        else
            std::cout << "no account exists\n";
        std::optional<float> result = r5.get();

        if(result.has_value())
            std::cout<<"Account found with balance: "<<result.value()<<"\n";
        else    
            std::cerr << "Account not found!!\n";

        // if (std::optional<float> result = FindBalanceById(data, 234567l); result.has_value())
        //     std::cout << "Account found with balance: " << result.value() << "\n";
        // else
        //     std::cerr << "Account not found!!\n";
    }
    catch(std::runtime_error& ex)
    {
        std::cerr<<ex.what()<<"\n";
    }
}