#include <iostream>
#include "Q1_Calculator.h"

void Calculator::Init()
{
    sum=0,min=0,div=0,mul=0;
    cnt_add=0, cnt_div=0, cnt_min=0, cnt_mul=0;
}
double Calculator::Add(double x, double y)
{
    sum=x+y;
    cnt_add++;

    return sum;
}
double Calculator::Min(double x, double y)
{
    min=x-y;
    cnt_min++;

    return min;   
}
double Calculator::Div(double x, double y)
{
    div=x/y;
    cnt_div++;

    return div;
}
double Calculator::Mul(double x, double y)
{
    mul=x*y;
    cnt_mul++;

    return mul;
}
void Calculator::ShowOpCount()
{
    std::cout<<"Add: "<<cnt_add<<" Min: "<<cnt_min<<" Mul: "<<cnt_mul<<" Div: "<<cnt_div<<std::endl;
}