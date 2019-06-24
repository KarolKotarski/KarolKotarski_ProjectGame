#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#define NDEBUG
#include <GL/freeglut.h>
#include <iostream>
#include <cstdlib>
#include "cBohater.h"
#include "cgra.h"
#include "cMapa.h"
#include "cpotwor.h"
#include "cskrzynki.h"
#include "MIniMap.h"
#include "Komunikat.h"
#include "Przegrana.h"
#include "Wygrana.h"
#include "PasekZycia.h"
#include <list>
#include <GL/glu.h>
#include <time.h>
#include <Windows.h>
#include <MMSystem.h>

    list<cSkrzynki> skrzynka;
    list<cPotwor> potwory;
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);


    void on_timer();
    void dodajSkrzynke(float x, float y);
    void dodajPotwora(float x, float y);

#endif // OPENGLWIDGET_H
