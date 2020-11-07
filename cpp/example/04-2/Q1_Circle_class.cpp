#include <iostream>
#include "Q1_Circle_class.h"

void Circle::Init(int x, int y)
{
    xpos=x;
    ypos=y;
}
void Circle::ShowPointInfo() const
{
    std::cout<<"["<<xpos<<", "<<ypos<<"]"<<std::endl;
}