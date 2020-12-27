#ifndef __CIRCLE_CLASS_H__
#define __CIRCLE_CLASS_H__

class Circle
{
private :
    int xpos, ypos, rad;
public :
    void ShowPointInfo() const;
    Circle(int x, int y, int r)
        : xpos(x), ypos(y), rad(r)
    {
    }

};

class Ring
{
private :
    Circle Inner;
    Circle Outter;
public : 
    Ring(int Ix, int Iy, int Ir, int Ox, int Oy, int Or)
        : Inner(Ix,Iy,Ir), Outter(Ox,Oy,Or)
        {}
    void ShowRingInfo() const;
};

#endif