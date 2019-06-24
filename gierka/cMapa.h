#ifndef CMAPA_H
#define CMAPA_H
#define NDEBUG
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL\freeglut_ext.h>
#include <errno.h>
#include "cBohater.h"
using namespace std;
class cBohater;
class cMapa
{
    int szerokosc;
    int dlugosc;
    int** tab;
	char *dane;
	char *dane2;

public:
    cMapa();
    cMapa(int sz, int dl); //konstruktor
    cMapa(cMapa &map);
    //~cMapa();


    void wyswietl();
    void zmienPola();
    void poprawaPol();
	void rysujprzejscie(double _x,double _y);
	void przejscie(double _x,double _y);
	
    int getdlugosc(){return this->dlugosc;}
    int getszerokosc(){return this->szerokosc;}
    int** gettab(){return this->tab;}
    int wartoscPola(int x,int y){return this->tab[x][y];}
	void rysujPole();
	void rysujKamien();
    void rysuj();
};

#endif // CMAPA_H
