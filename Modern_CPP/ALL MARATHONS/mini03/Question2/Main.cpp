#include "Functionalities.h"
#include<future>
#include<mutex>
std::mutex mt;
int main(int argc, char const *argv[])
{
    Container data;
    createObjects(data);

   // std::cout<<*std::get<DeveloperPointer>(data[0]);

    try
    {               
        std::future<Container> res= std::async(std::launch::async,EmployeeAbove6yrsExper,std::ref(data));
       
        std::future<float> avg=std::async(std::launch::async,findAvgSalaryCodeTester,std::ref(data));

        std::future<std::optional<skills>> skil=std::async(std::launch::async,FindSkills,std::ref(data),"1");

        std::future<bool> isAny=std::async(std::launch::async,isSalaryGreaterThan60000,std::ref(data));

        std::future<std::optional<float>> bonus=std::async(std::launch::async,GetBonus,std::ref(data),"1");

        std::cout<<" NUmber of EmployeeAbove6yrsExper  :"<<res.get().size() <<std::endl;
        std::cout<<"findAvgSalaryCodeTester   :" <<avg.get()<<std::endl;
        std::optional<skills> sk=skil.get();
        if(sk.has_value()){
            std::cout<<"Skills are present for given string id  "<<std::endl;
            for(auto& skl:sk.value()){
               
                switch (skl)
                {
                case SkillSet::CODE_REVIEW:
                std::cout<<" CODE_REVIEW "<<" ";
                    break;
                case SkillSet::CODING_UNIT:
                    /* code */
                    std::cout<<"CODING_UNIT "<<" ";
                    break;
                case SkillSet::INTEGRATION_TESTING:
                    std::cout<<" INTEGRATION_TESTING "<<" ";
                    /* code */
                    break;
                case SkillSet::TESTING_CODE:
                    std::cout<<" TESTING_CODE "<<" ";
                    break;
                }
            }
            std::cout<<""<<std::endl;
        
        }else{
            std::cout<<"No Id present in Container"<<std::endl;
        }

        if(isAny.get()){
             std::cout<<"Yes !! There is SalaryGreaterThan60000" <<std::endl;
        }else{
            std::cout<<"No !! There is SalaryGreaterThan60000" <<std::endl;
        }
        std::optional<float> ans=bonus.get();
        if(ans.has_value()){
            std::cout<<"Bonus is "<<ans.value() <<std::endl;
        }else{
            std::cout<<"No Id Matches"<<std::endl;
        }
        
    }
     catch(NoCodeTester & e)
    {
        std::cerr << e.what() << '\n';
    }
     catch(EmptyContainer & e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(const std::future_error & e)
    {
        std::cerr << e.what() << '\n';
    }
    
  
    return 0;
}
