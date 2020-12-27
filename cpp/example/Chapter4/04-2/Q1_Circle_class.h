#ifndef __CIRCLE_CLASS_H__
#define __CIRCLE_CLASS_H__

class Circle
{
private :
    int xpos, ypos, rad;
public :
    void Init(int x, int y, int r);
    void ShowPointInfo() const;
};

class Ring
{
private :
    Circle Inner;
    Circle Outter;
public : 
    void Init(int Ix, int Iy, int Ir, int Ox, int Oy, int Or);
    void ShowRingInfo() const;
};

#endif