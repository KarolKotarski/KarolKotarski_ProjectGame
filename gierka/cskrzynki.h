#ifndef CSKRZYNKI_H
#define CSKRZYNKI_H
#define NDEBUG

#include <math.h>
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL\freeglut_ext.h>
#include <errno.h>
#include "cBohater.h"
class cSkrzynki
{
    int x;
    int y;
	double z;
	char *dane1;

public:

    cSkrzynki();
    cSkrzynki(int X, int Y);
	void rysujSkrzynke();
    virtual void rysuj();


    int getY() const;
    void setY(int value);
   int getX() const;
    void setX(int value);

};

#endif // CSKRZYNKI_H
