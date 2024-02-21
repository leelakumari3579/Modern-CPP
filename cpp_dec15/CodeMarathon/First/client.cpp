#include<iostream>
#include"header.h"
#include<cstring>

void search(User *u1,std::string dpt,int count);
int main()
{
   User u1[3];
   for(int i=0;i<3;i++)
   {
    std::cout<<"enter user details "<<std::endl;
    std::cin>>u1[i];
   }
   std::string dpt;
   std::cout<<"enter department name "<<std::endl;
   std::cin>>dpt;
   int count=0;
   
    try
    {
        search(u1,dpt,count);
    }
    catch (const char* msg)
    {
        std::cout<<msg<<std::endl;
    }
    catch(...)
    {
        std::cout<<"\n Some error accured ";
    }

 //   for(int i=0;i<3;i++)
    if(u1[0]==u1[1])
        std::cout<<"these objects having same department";
    else
        std::cout<<"objects not having same department";



//    catch ( DepartmentExecption obj)
//     {
//         std::cout <<"\n"<< obj.what() << "\n";
//     }
//     catch(std::exception  e )// generic handler
//     {
//         std::cout<<e.what();
//     }
}