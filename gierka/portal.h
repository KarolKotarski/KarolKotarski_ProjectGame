#ifndef PORTAL_H
#define PORTAL_H
#define NDEBUG
#include <GL/freeglut.h>
#include <math.h>

class portal
{
    double x;
	double y;
	double angle;

public:
    portal();
    portal(double X, double Y, double Angle);
    virtual void rysuj();
	double getX() const;
    void setX(int value);
	double getY() const;
    void setY(int value);
	double getAngle() const;
    void setAngle(int value);
	void Obrot();
};

#endif // PORTAL_H
