#ifndef CBOHATER_H
#define CBOHATER_H
#define NDEBUG
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cMapa.h"
#include "CzytajTekstury.h"
#include <math.h>

using namespace std;
class cMapa;
class cBohater
{
    int X;
    int Y;
    int ruch;
    int Atak;
    int Con;
    int Zr;
    int HP;
	char *dane3;

public:
    cBohater ();
    cBohater (int x, int y);
    cBohater (string klasa);
	void rysujTeksture();
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

#endif // CBOHATER_H
