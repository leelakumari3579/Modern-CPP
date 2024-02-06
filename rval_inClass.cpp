#include<iostream>
#include<array>

class Demo
{
    private:
        int _id;
        float _age;
        std::string _name;
        std::array<int, 100000>&& _arr; //1 million integers
    public:
        Demo(int id, float age, std::string name, std::array<int, 100000>&& arr)
        :_id(id),_age(age),_name(name),_arr(std::move(arr))
        {}
        ~Demo() {}
};

//stack of GetInput
void GetInput()
{
    int id {-1}; //4 bytes
    float age {-1.0f}; //4 bytes
    std::string name {""}; //32 bytes
    std::array<int, 100000> data {1}; //4 million bytes (40 lakh) bytes for array

    std::cin>>id;
    std::cin>>age;
    std::cin>>name;
    //1 million input for array

    Demo(id, age, name, std::move(data));
}

int main()
{
    GetInput();
}