#ifndef __CIRCLE_CLASS_H__
#define __CIRCLE_CLASS_H__

class Circle
{
private :
    int xpos, ypos;
public :
    void Init(int x, int y);
    void ShowPointInfo() const;
};

class Ring
{
private :
    Circle Inner;
    Circle Outter;
public : 
    void ShowInfo() const;
};

#endif