#ifndef __Q2_SAVESTRING_H__
#define __Q2_SAVESTRING_H__

class Printer
{
private:
    char str[100];
public:
    void SetString(char *c);
    void ShowString();
};

#endif