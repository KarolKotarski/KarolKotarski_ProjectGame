#include "MIniMap.h"



CMIniMap::CMIniMap()
{
	x = 0;
	y = 0;
}


CMIniMap::~CMIniMap()
{
}

void CMIniMap::rysuj(double a, double b)
{
	
	glPushMatrix();
	glColor3ub(100, 150, 12);
	glBegin(GL_POLYGON);
	glVertex2f(-10,10);
	glVertex2f(-10,8);
	glVertex2f(-8,8);
	glVertex2f(-8,10);
	glEnd();

	glPopMatrix();
}
