#include <iostream>
#include <cstring>


class Gun
{
private:
    int bullet;     // 장전된 총알의 수
public:
    Gun(int bnum) : bullet(bnum)
    {}
    void Shot()
    {
        std::cout<<"BBANG!"<<std::endl;
        bullet--;
    }
};

class Police : public Gun
{
private:
    int handcuffs;      // 소유한 수갑의 수
public:
    Police(int bnum, int bcuff)
        : Gun(bnum), handcuffs(bcuff)
    {}
    void PutHandcuff()
    {
        std::cout<<"SNAP!"<<std::endl;
        handcuffs--;
    }
};

int main(void)
{
    Police pman(5,3);       // 총알 5, 수갑 3
    pman.Shot();
    pman.PutHandcuff();
    return 0;
}