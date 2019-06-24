#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cMapa.h"
#include <math.h>
using namespace std;
class CMIniMap
{

	double x;
	double y;
public:
	CMIniMap();
	~CMIniMap();
	
	void rysuj(double a, double b);

};

