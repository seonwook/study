#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

class Calculator
{
private :
    double sum,min,div,mul;
    int cnt_add, cnt_div, cnt_min, cnt_mul;
public :
    void Init();
    double Add(double x, double y);
    double Min(double x, double y);
    double Div(double x, double y);
    double Mul(double x, double y);
    void ShowOpCount();
};

#endif