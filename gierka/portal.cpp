#include "portal.h"


double portal::getX() const
{
    return x;
}

void portal::setX(int value)
{
    x = value;
}

double portal::getY() const
{
    return y;
}

void portal::setY(int value)
{
    y = value;
}

double portal::getAngle() const
{
    return angle;
}

void portal::setAngle(int value)
{
    angle = value;
}
void portal::Obrot()
{
	angle = angle + 0.1;
}
portal::portal()
{
    x=-15;
    y=-15;
    angle=0;
}

portal::portal(double X, double Y, double Angle)
{
    x=X;
    y=Y;
    angle=Angle;
}
void portal::rysuj()
{
    glPushMatrix();
    x=0.5*cos(angle)+40;
    y=0.5*sin(angle)+40;
    glTranslated(x,y,0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.5,+0.5);
    glVertex2f(+0.5,+0.5);
    glVertex2f(+0.5,-0.5);
    glVertex2f(-0.5,-0.5);
    glEnd();
    glPopMatrix();

}
