#include <iostream>

class Rectangle
{
private:
    int x;
    int y;
public:
    Rectangle(int xpos, int ypos) : x(xpos), y(ypos)
    {}
    void ShowAreaInfo()
    {
        std::cout<<"면적: "<<(x*y)<<std::endl;
    }
};

class Square : public Rectangle
{
public:
    Square(int dis) : Rectangle(dis,dis)
    {}
};

int main(void)
{
    Rectangle rec(4,3);
    rec.ShowAreaInfo();     // 면적: 12

    Square sqr(7);
    sqr.ShowAreaInfo();     // 면적: 49
    return 0;
}