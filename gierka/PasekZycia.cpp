#include "PasekZycia.h"



CPasekZycia::CPasekZycia()
{
	X = 20;
}

CPasekZycia::CPasekZycia(double _X)
{
	X = _X;
}


CPasekZycia::~CPasekZycia()
{
}

void CPasekZycia::rysuj()
{
	glPushMatrix();
	glTranslated(-10, 8, 0);
	glColor3ub(255,0 , 0);
	glBegin(GL_POLYGON);
	glVertex3f(X*0.1, 0.2,1);
	glVertex3f(X*0.1, -0.2,1);
	glVertex3f(0, -0.2,1);
	glVertex3f(0, 0.2,1);
	glEnd();
	glPopMatrix();
}

void CPasekZycia::setX(double value)
{
	X = value;
}

double CPasekZycia::getX() const
{
	return X;
}
