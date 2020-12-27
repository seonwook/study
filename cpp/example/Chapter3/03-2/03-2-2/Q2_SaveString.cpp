#include <iostream>
#include "Q2_SaveString.h"

void Printer::SetString(char *c)
{
    strcpy(str,c);
}

void Printer::ShowString()
{
    std::cout<<str<<std::endl;
}