#pragma once
#include <GL/freeglut.h>
#include <math.h>
class CPasekZycia
{
	double X;
public:
	CPasekZycia();
	CPasekZycia(double _X);
	~CPasekZycia();
	void rysuj();
	void setX(double value);
	double getX() const;
};

