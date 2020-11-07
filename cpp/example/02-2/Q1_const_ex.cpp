#include <iostream>

int main(){
    const int num=12;
    const int *ptr= &num;

    const int *(&ptr2)=ptr;

    std::cout<<"pointer : "<<*ptr<<std::endl;
    std::cout<<"Reference : "<<*ptr2<<std::endl;

    return 0;
}