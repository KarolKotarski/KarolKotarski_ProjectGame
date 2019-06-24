#include "cpotwor.h"

double _xx, _yy;
int wylacz = 0;
int cPotwor::getX() const
{
    return x;
}

void cPotwor::setX(int value)
{
    x = value;
}

int cPotwor::getY() const
{
    return y;
}

void cPotwor::setY(int value)
{
    y = value;
}

int cPotwor::getAtak() const
{
    return Atak;
}

void cPotwor::setAtak(int value)
{
    Atak = value;
}

int cPotwor::getHP() const
{
    return HP;
}

void cPotwor::setHP(int value)
{
    HP = value;
}

cPotwor::cPotwor()
{
    x=0;
    y=0;
    Atak = 5;
    HP= 10;
	przemieszczenieX = 0;
	przemieszczenieY = 0;
	par = 0.1;
	par1 = 0;
}

cPotwor::cPotwor(int X, int Y,double _przemieszczenieX, double _przemieszczenieY)
{
	_xx = X;
	_yy = Y;
    x=X;
    y=Y;
    Atak = 5;
    HP= 10;
	przemieszczenieX = _przemieszczenieX;
	przemieszczenieY = _przemieszczenieY;
	par = 0;
	par1 = 0;
}
void cPotwor::rotacja()
{
	srand(time(NULL));
	//przemieszczenieX = rand()%9*0.1;
	if (wylacz == 0)
	{

		par += przemieszczenieX;
		par1 += przemieszczenieY;
		if (par > 20)
		{
			wylacz = 1;
			par -= przemieszczenieX;
			par1 -= przemieszczenieY;
		}
	}
	else
	{
		par -= przemieszczenieX;
		par1 -= przemieszczenieY;
		if (par < 0)
		{
			par += przemieszczenieX;
			par1 += przemieszczenieY;
			wylacz = 0;
		}
	}

}
void cPotwor::rysuj()
{
    glPushMatrix();
	glTranslated(x, y, 0);
	glTranslated(par,par1, 0);
        glColor3ub(100,200,0);
//        glBegin(GL_POLYGON);

//        glVertex2f(-0.5,-0.5);
//        glVertex2f(0.5,-0.5);
//        glVertex2f(0,0.5);

//        glEnd();
        glBegin(GL_POLYGON);
        for(int i=0;i<361;i++)
        {
            float Xs=0.2*cos(i)+0.2;
            float Ys=0.2*sin(i)+0.2;
            glVertex3f(Xs,Ys,0);
            glVertex3f(Xs,Ys,0.5);
        }
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.1,0.1);
        glVertex2f(0.3,-0.5);
        glVertex2f(0.2,-0.5);
        glVertex2f(0.0,0.1);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.3,-0.4);
        glVertex2f(-0.5,-0.4);
        glEnd();
        glPopMatrix();

}

double cPotwor::getprzemieszczenieX() const
{
	return przemieszczenieX;
}

double cPotwor::getprzemieszczenieY() const
{
	return przemieszczenieY;
}

double cPotwor::getpar() const
{
	return par;
}

double cPotwor::getpar1() const
{
	return par1;
}
