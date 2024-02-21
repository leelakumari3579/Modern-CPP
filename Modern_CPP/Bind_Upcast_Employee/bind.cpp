#include <cstring>
#include <functional>

int formula(int x, int y, int z)
{
    return ((x+y)-z);
}

int main()
{
    char* x = "leela";
    char* y = "nani";
    auto strcpy_binded = std::bind(strcpy,std::placeholders::_2,std::placeholders::_1);
    strcpy_binded(x,y); //x has to go to source, y has to go to destination

    auto formula_binded = std::bind(formula, 100,200,std::placeholders::_1);
    formula_binded(70); //fromula(100,200,70) ---->

    formula_binded(70,80,90,20); //formula(100,200,70). discard everything else
}