#include <iostream>

class SoSimple
{
private:
    int num;
public:
    SoSimple(int n) : num(n)
    {}
    SoSimple(const SoSimple & copy) : num(copy.num)
    {
        std::cout<<"Called SoSimple(const SoSimple & copy)"<<std::endl;
    }
    SoSimple & AddNum(int n)
    {
        num+=n;
        return *this;
    }
    void ShowData()
    {
        std::cout<<"num: "<<num<<std::endl;
    }
};

SoSimple SimpleFuncObj(SoSimple ob)
{
    std::cout<<"return 이전"<<std::endl;
    return ob; /* 반환형이 참조형이 아니기 때문에 ob객체의 복사본이 만들어지면서(임시객체!!) 반환이 진행 */
}

int main(void)
{
    SoSimple obj(7);
    SimpleFuncObj(obj).AddNum(30).ShowData();
    obj.ShowData();
    return 0;
}