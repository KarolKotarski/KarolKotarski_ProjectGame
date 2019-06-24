#include "cbohater2.h"

int cBohater2::getRuch() const
{
    return ruch;
}

void cBohater2::setRuch(int value)
{
    ruch = value;
}

int cBohater2::getAtak() const
{
    return Atak;
}

void cBohater2::setAtak(int value)
{
    Atak = value;
}

int cBohater2::getCon() const
{
    return Con;
}

void cBohater2::setCon(int value)
{
    Con = value;
}

int cBohater2::getZr() const
{
    return Zr;
}

void cBohater2::setZr(int value)
{
    Zr = value;
}

int cBohater2::getHP() const
{
    return HP;
}

void cBohater2::setHP(int value)
{
    HP = value;
}

float cBohater2::getX() const
{
    return X;
}

void cBohater2::setX(int value)
{
    X = value;
}

float cBohater2::getY() const
{
    return Y;
}

void cBohater2::setY(int value)
{
    Y = value;
}
cBohater2::cBohater2 ()
{
    X=0;
    Y=0;
    ruch = 5;
    Atak = 1;
    Zr = 1;
    Con = 1;
    HP= 10;
}

cBohater2::cBohater2(int x, int y)
{
    X=x;
    Y=y;
    ruch = 5;
    Atak = 3;
    Zr = 1;
    Con = 1;
    HP = 10;
}

cBohater2::cBohater2(string klasa)
{
    if(klasa=="Warrior")
    {
        X=0;
        Y=0;
        ruch = 5;
        Atak = 5;
        Con = 5;
        Zr = 2;
        HP = 10;
        cout<<"Wybrales/as wojownika"<<endl;
    }
    else if(klasa=="Druid")
    {
        X=0;
        Y=0;
        ruch = 5;
        Atak = 2;
        Con = 9;
        Zr = 1;
        HP = 8;
        cout<<"Wybrales/as druida"<<endl;
    }
    else
    {
        X=0;
        Y=0;
        ruch = 5;
        Atak = 15;
        Zr = 1;
        Con = 1;
        HP = 5;
        cout<<"Wybrales/as podstawowa nacje"<<endl;
    }
}
void cBohater2::rysuj()
{
    glPushMatrix();
    glTranslated(X,Y,0);
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    for(int i=0;i<361;i++)
    {
        float Xs=0.2*cos(i)+0.2;
        float Ys=0.2*sin(i)+0.2;
        glVertex2f(Xs,Ys);
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
