#include <iostream>

int main()
{
    int num;
    
    std::cout<<"Input Multiplication Table number :: ";
    std::cin>>num;

    std::cout<<"Multiplication Table is "<<num<<"\n";

    for (int i=1;i<10;i++)
    {
        std::cout<<num<<" * "<<i<<" = "<<num*i<<"\n";
    }

    return 0;
}