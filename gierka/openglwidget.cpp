#include "openglwidget.h"
#include <time.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;
CGra gra;
CMIniMap MiniMapa;
CKomunikat Komunik;
CPrzegrana Przegrana;
CWygrana Wygrana;
int wygrana = 0;
bool wylacznik = 0;
double iks=0, igrek=0;
/*
void on_timer()
{
    for(int i = 0 ; i<=360 ; i++)
        gra.Portal.setAngle(gra.Portal.getAngle()+i);
 }
*/

void passiveMouseMotion(int mouse_x, int mouse_y)
{
	double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
	double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

	//double Xx = (mouse_x - 600) / 1200.0 * 70;
	//double Yy = (mouse_y - 800) / 1200.0 * 70;
	double Xx = (mouse_x - 600) / 1200.0 * 70;
	double Yy = (mouse_y - 800) / 1200.0 * 70;
	if (GLUT_LEFT_BUTTON)
	{
			iks = Xx*1;
			igrek = Yy*1;
	}
	//gra.ortx = Xx;
	//gra.orty = -Yy;
	

	// MOUSE - TODO!

}
void FunkcjaDoObslugiKlawiatury(unsigned char key, int _x, int _y)
{
	//std::cout << "Naciœniêto klawisz: " << key << ", a bohater znajduje siê w pozycji: " << gra.bohater.getX() << ", " << gra.bohater.getY() << "XY" << std::endl;
	
	if ((key == ' ') && (wygrana ==0))
		wygrana = 4;
	if ((key == ' ') && (wylacznik==1))
	{
		exit(0);
	}
	if (key == 'w')
	{
		if ((gra.zj3 == 1) || ((gra.zj3 == 1) && (gra.zj1 == 1)) || ((gra.zj3 == 1) && (gra.zj2 == 1)) || ((gra.zj3 == 1) && (gra.zj4 == 1)))
			gra.orty = gra.orty;

		else {
			gra.orty += 1;
			gra.bohater.setRuch(gra.bohater.getRuch() - 1);
		}
		gra.zj1 = 0;
		gra.zj2 = 0;
		gra.zj3 = 0;
		gra.zj4 = 0;

	}
	if (key == 's')
	{
		if ((gra.zj4 == 1) || ((gra.zj4 == 1) && (gra.zj1 == 1)) || ((gra.zj4 == 1) && (gra.zj2 == 1)) || ((gra.zj4 == 1) && (gra.zj3 == 1)))
			gra.orty = gra.orty;

		else {
			gra.orty -= 1;
			gra.bohater.setRuch(gra.bohater.getRuch() - 1);
		}
		gra.zj1 = 0;
		gra.zj2 = 0;
		gra.zj3 = 0;
		gra.zj4 = 0;
	}
	if (key == 'a')
	{
		if ((gra.zj1 == 1) || ((gra.zj1 == 1) && (gra.zj2 == 1)) || ((gra.zj1 == 1) && (gra.zj3 == 1)) || ((gra.zj1 == 1) && (gra.zj4 == 1)))

			gra.ortx = gra.ortx;

		else {
			gra.ortx -= 1;
			gra.bohater.setRuch(gra.bohater.getRuch() - 1);
		}
		gra.zj1 = 0;
		gra.zj2 = 0;
		gra.zj3 = 0;
		gra.zj4 = 0;

	}
	if (key == 'd')
	{
		if ((gra.zj2 == 1) || ((gra.zj2 == 1) && (gra.zj1 == 1)) || ((gra.zj2 == 1) && (gra.zj3 == 1)) || ((gra.zj2 == 1) && (gra.zj4 == 1)))
			gra.ortx = gra.ortx;

		else {
			gra.ortx += 1;
			gra.bohater.setRuch(gra.bohater.getRuch() - 1);
		}
		gra.zj1 = 0;
		gra.zj2 = 0;
		gra.zj3 = 0;
		gra.zj4 = 0;
	}


}
void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
	glFrustum(-4, 4, -3.0, 3.0, 1.0, 15.0);
//	gluLookAt(0, 0, 5, 0, 0, 0, 0, 1, 0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void idle()
{

	glutPostRedisplay();
}
void Draw(double width, double height)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gluLookAt(iks, igrek, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, -1.0, 0.0, 5.0, 5.0);
	//glScaled(0.9, 0.9, 0.9);
	// glRotatef(45,1,0.0,0.0);
	// glTranslated(10,10,0);
	//glTranslated(-0.5*gra.mapa.getdlugosc()+1,0.5*gra.mapa.getszerokosc()-1,0);
	//MiniMapa.rysuj(0,0);

	gra.bohater.rysuj();
	gra.PasekCzerwony.rysuj();
	//glTranslated(0.5*100-1,-0.5*100+1,0);
	glTranslated(-gra.ortx, -gra.orty, 0);
	gra.Portal.rysuj();
	list<cPotwor>::iterator it;
	for (it = gra.getPotwory().begin(); it != gra.getPotwory().end(); ++it)
		it->rysuj();
	list<cSkrzynki>::iterator to;
	for (to = gra.getSkrzynka().begin(); to != gra.getSkrzynka().end(); ++to)
		to->rysuj();
	gra.mapa.rysujprzejscie(25, 40);
	gra.mapa.rysuj();
	//glScaled(0.1, 0.1, 0.1);
	//gra.mapa.rysuj();
}

void display()
{
	// clear the scene
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glRotated(180, 0, 0, 0);
	//glTranslated(0, 0, 0);
	double time = glutGet(GLUT_ELAPSED_TIME);
	//if (gra.PasekCzerwony.getX() < -0.5)
	//{

	//}
	if (time > 36000)
	{
		wygrana = 1;
	}
	//cout << gra.ortx << " a igrek" << gra.orty;
	if ((gra.bohater.getX()  ==( 40 - gra.ortx)) && (gra.bohater.getY() == (40 - gra.orty)))
	{
		wygrana = 2;
	}
	if ((wygrana==0)||(wygrana==4))
	{
		if ((time < 10000)&&(wygrana==0))
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glLoadIdentity();

			gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
			Komunik.rysuj();
		}
	else
			Draw(2.0, 1.0);
	}
	if (wygrana == 2)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();

		gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//Sleep(1000);
		glutSwapBuffers;
		glutPostRedisplay();
		Wygrana.rysuj();
		//double time1 = glutGet(GLUT_ELAPSED_TIME);
		//clock_t klok=clock() ;
		//clock_t endwait;
		double time1 = 0;
		if (wylacznik == 0)
		{
			time1 = glutGet(GLUT_ELAPSED_TIME);
			wylacznik = 1;
		}
		//endwait = clock() + CLOCKS_PER_SEC;
		//time_t start;
		//double tick = GetTickCount();
		//double g = GLUT_ELAPSED_TIME;
		
		//SetTimer
		//cout << "Time" << time << "Time1" << g << "klok" << klok << "tick"<<tick<< endl;
		//if(time1>2000)
		//delay(100);
		//cout << "clock" << clock() << "endwait" << endwait << "Time" << time <<endl;
		glutSwapBuffers;
		glutPostRedisplay();
		//Sleep(1);
		
		//_sleep(1000);
		glutPostRedisplay();
		if(time-time1>200000)
		exit(0);
		
		//Wygrana.rysuj();
	}
	if ((wygrana == 1)||gra.bohater.getHP()<0)
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		gluLookAt(0.0, 0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		Przegrana.rysuj();
		//getchar();
		double time1 = 0;
		if (wylacznik == 0)
		{
			time1 = glutGet(GLUT_ELAPSED_TIME);
			wylacznik = 1;
		}
		if (time - time1 > 2000000)
			//exit(0);
			//RegisterApplicationRestart;
			//_fcloseall;
		//system("gierka.exe");
		exit(0);
			//system("cls");
	}
	glutSwapBuffers();
	gra.sprawdzSkrzynki();
	gra.sprawdzWalki();
	gra.sprawdzkratki();
	gra.mapa.przejscie(gra.ortx,gra.orty);
}

void InitGLUTScene(char* window_name)
{
	glutInitWindowSize(1960, 800);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow(window_name);

	// set white as the clear colour
	glClearColor(1, 1, 1, 1);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
}

void aktualizujCzas(int tmp)
{

	gra.Portal.Obrot();
	srand(time(NULL));
	list<cPotwor>::iterator it;
	for (it = gra.getPotwory().begin(); it != gra.getPotwory().end(); ++it)
		it->rotacja();
	glutTimerFunc(20, aktualizujCzas, NULL);
}
/*
void bohaterRuch(int tmp)
{
	gra.bohater.getRuch();
	glutTimerFunc(20, bohaterRuch, NULL);
}
*/
void SetCallbackFunctions()
{
	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutPassiveMotionFunc(passiveMouseMotion);
	glutKeyboardFunc(FunkcjaDoObslugiKlawiatury);
	
	PlaySound(TEXT("sound1.wav"), NULL, SND_ASYNC);
	//glutTimerFunc(20, bohaterRuch, 0);
}


int main(int argc, char *argv[])
{

	printf("Hello openGL world!");
	glutInit(&argc, argv);
	glutTimerFunc(20, aktualizujCzas, NULL);
	InitGLUTScene("dojdz do celu");
	
	SetCallbackFunctions();

	glutMainLoop();

	return 0;
}