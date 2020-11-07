#include <iostream>

int Addnum(int &num){
    std::cout<<++num<<std::endl;
    return num;
}

int convertnum(int &num){
    std::cout<<-num<<std::endl;
    return num;
}

int main(){
    int n;
    
    std::cout<<"Please Input number : ";
    std::cin>>n;

    Addnum(n);
    std::cout<<"main n : "<<n<<std::endl;
    convertnum(n);
    std::cout<<"main n : "<<n<<std::endl;

    return 0;
}

