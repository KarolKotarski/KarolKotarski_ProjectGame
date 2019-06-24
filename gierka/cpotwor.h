#ifndef CPOTWOR_H
#define CPOTWOR_H
#define NDEBUG
#include <GL/freeglut.h>
#include <math.h>
#include <time.h>

class cPotwor
{
    int x;
    int y;
    int Atak;
    int HP;
	double przemieszczenieX;
	double przemieszczenieY;
	double par;
	double par1;

public:
    cPotwor();
    cPotwor(int X, int Y, double _przemieszczenieX, double _przemieszczenieY);
    virtual void rysuj();
	double getprzemieszczenieX() const;
	double getprzemieszczenieY() const;
	double getpar() const;
	double getpar1() const;
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getAtak() const;
    void setAtak(int value);
    int getHP() const;
    void setHP(int value);
	void rotacja();
};

#endif // CPOTWOR_H

