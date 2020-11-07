#include <iostream>

int main(){

    int price,sale_salary=0,salary;
    int org_salary=50;

    while(1)
    {
        std::cout<<"판매 급액을 만원 단위로 입력(-1 to end): ";
        std::cin>>price;;
        
        if(price==-1){
            std::cout<<"Quit\n";
            return 0;
        }
        
        salary=org_salary+price*0.12;
        std::cout<<"이번 달 급여: "<<salary<<"만원\n";
    }
}