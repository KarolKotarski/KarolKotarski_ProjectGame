#ifndef CGRA_H
#define CGRA_H
#define NDEBUG
#include <GL/freeglut.h>
#include "cMapa.h"
#include "cBohater.h"
//#include "cbohater2.h"
#include "cpotwor.h"
#include "cskrzynki.h"
#include <list>
#include "portal.h"
#include <string>
#include "PasekZycia.h"

using namespace std;
class CGra
{

    //cPotwor potwor;
    list<cSkrzynki> skrzynka;
    list<cPotwor> potwory;


public:
    cMapa mapa;
    cBohater bohater;
    portal Portal;
	CPasekZycia PasekCzerwony;
    //cBohater2 bohater2;
    CGra();
    void grafika();
    void aktualizuj_stangry(char kier);
    void dodajSkrzynke(int x, int y);
    void dodajPotwora(int x, int y, double _parametrX, double _parametrY);
    void koniecTury();
    void sprawdzWalki();
    void sprawdzSkrzynki();
    void sprawdzkratki();
    double ortx;
    double orty;
    int zj1;
    int zj2;
    int zj3;
    int zj4;

    // dopisać metodę walki

    list<cSkrzynki> &getSkrzynka();
    void setSkrzynka(const list<cSkrzynki> &value);
    list<cPotwor> &getPotwory();
    void setPotwory(const list<cPotwor> &value);

};

#endif // CGRA_H
