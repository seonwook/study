#include <iostream>
#include "Q1_Circle_class.h"

void Circle::ShowPointInfo() const
{
    std::cout<<"radius: "<<rad<<std::endl;
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}

void Ring::ShowRingInfo() const
{
    std::cout<<"Inner Circle Info..."<<std::endl;
    Inner.ShowPointInfo();

    std::cout<<"Outter Circle Info..."<<std::endl;
    Outter.ShowPointInfo();
}