#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cMapa.h"
#include <math.h>
using namespace std;
class CPrzegrana
{
	char *dane12;
public:
	CPrzegrana();
	~CPrzegrana();
	void rysujPrzegrana();
	void rysuj();
};

