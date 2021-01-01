#include <iostream>

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    { }
    SoSimple& Addnum(int n)
    {
        num+=n;
        return *this;
    }   
    void ShowData() const
    {
        std::cout<<"num: "<<num<<std::endl;
    }
};

int main(void)
{
    const SoSimple obj(7);
    // obj.AddNum(20);
    obj.ShowData();
    return 0;
}