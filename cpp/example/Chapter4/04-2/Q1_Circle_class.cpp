#include <iostream>
#include "Q1_Circle_class.h"

void Circle::Init(int x, int y, int r)
{
    xpos=x;
    ypos=y;
    rad=r;
}
void Circle::ShowPointInfo() const
{
    std::cout<<"radius: "<<rad<<std::endl;
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}

void Ring::Init(int Ix, int Iy, int Ir, int Ox, int Oy, int Or)
{
    Inner.Init(Ix,Iy,Ir);
    Outter.Init(Ox,Oy,Or);
}

void Ring::ShowRingInfo() const
{
    std::cout<<"Inner Circle Info..."<<std::endl;
    Inner.ShowPointInfo();

    std::cout<<"Outter Circle Info..."<<std::endl;
    Outter.ShowPointInfo();
}