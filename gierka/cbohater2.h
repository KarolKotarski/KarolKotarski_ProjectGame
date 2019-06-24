#ifndef CBOHATER2_H
#define CBOHATER2_H
#define NDEBUG
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cMapa.h"
#include <math.h>
class cBohater2
{
    int X;
    int Y;
    int ruch;
    int Atak;
    int Con;
    int Zr;
    int HP;

public:
    cBohater2();
    cBohater2 (int x, int y);
    cBohater2 (string klasa);
    virtual void rysuj();
    //float getX(){return this->X;}
    //float getY(){return this->Y;}
    void przemiescBoh (char kier, cMapa &map);
    int getRuch() const;
    void setRuch(int value);
    int getAtak() const;
    void setAtak(int value);
    int getCon() const;
    void setCon(int value);
    int getZr() const;
    void setZr(int value);
    int getHP() const;
    void setHP(int value);
    float getX() const;
    void setX(int value);
    float getY() const;
    void setY(int value);
};

#endif // CBOHATER2_H
