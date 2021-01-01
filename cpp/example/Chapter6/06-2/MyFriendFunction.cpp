#include <iostream>


class Point;        //  Point가 클래스의 이름임을 선언

class PointOP
{
private:
    int opcnt;
public:
    PointOP() : opcnt(0)
    {}

    Point PointAdd(const Point&, const Point&);
    Point PointSub(const Point&, const Point&);
    ~PointOP()
    {
        std::cout<<"Operation times: "<<opcnt<<std::endl;
    }
};

class Point
{
private:
    int x;
    int y;
public:
    Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
    {}
    friend Point PointOP::PointAdd(const Point&, const Point&);
    friend Point PointOP::PointSub(const Point&, const Point&);
    friend void ShowPointPos(const Point&);
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x+pnt2.x, pnt1.y+pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
    opcnt++;
    return Point(pnt1.x-pnt2.x, pnt1.y-pnt2.y);
}

int main(void)
{
    Point pos1(1,2);
    Point pos2(2,4);
    PointOP op;

    ShowPointPos(op.PointAdd(pos1,pos2));
    ShowPointPos(op.PointSub(pos2,pos1));

    return 0;
}

void ShowPointPos(const Point& pos)
{
    std::cout<<"x: "<<pos.x<<", ";
    std::cout<<"y: "<<pos.y<<std::endl;
}