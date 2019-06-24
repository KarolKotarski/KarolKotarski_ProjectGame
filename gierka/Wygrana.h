#pragma once
#include <GL/freeglut.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "cMapa.h"
#include <math.h>
using namespace std;
class CWygrana
{
	char *dane13;
public:
	CWygrana();
	~CWygrana();
	void rysujWygrana();
	void rysuj();
};

