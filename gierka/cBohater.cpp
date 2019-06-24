#include "cBohater.h"

unsigned int widthh3, heightt3;
GLuint textureID3;

char *loadBMP_3()
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int imageSize;   // = width*height*3
	char * data;

	// Open the file
	FILE * file = fopen("rycerz.bmp", "rb");
	if (!file)
	{
		printf("nie otwarto obrazka\n");
	}
	else
	{
		cout << "poprawnie otwarto plik" << endl;

		if (fread(header, 1, 54, file) != 54)
		{
			printf("nie poprawny plik BMP\n");
		}
		else
		{
			cout << "nag³owek jest poprawny" << endl;

			if (header[0] != 'B' || header[1] != 'M')
			{
				printf("to nie jest plik BMP\n");
			}
			else
			{
				cout << "Dane pliku sa zgodne, pobieram" << endl;
				dataPos = *(int*)&(header[0x0A]);
				imageSize = *(int*)&(header[0x22]);
				widthh3 = *(int*)&(header[0x12]);
				heightt3 = *(int*)&(header[0x16]);

				// Some BMP file nie maja wewnych danych
				if (imageSize == 0)    imageSize = widthh3*heightt3 * 3; // 3 : one byte for each Red, Green and Blue component

				cout << "\npozycja aktualna dane: " << dataPos << endl << "wielkosc obrazka " << imageSize << endl << "szerokosc " << widthh3 << endl << "wysokosc " << heightt3 << endl << endl;

				//---------------------------------------------------
				// tworzenie tablicy z danymi
				data = new char[imageSize];

				// wpisanie do tablicy
				fread(data, 1, imageSize, file);

				for (int i = 0; i < imageSize; i += 3)
				{
					char tmp = data[i];
					data[i] = data[i + 2];
					data[i + 2] = tmp;
				}

				// Create one OpenGL texture
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_TEXTURE_2D);

				glGenTextures(1, &textureID3);

				cout << "plik zamknieto" << endl;
				fclose(file);

				return data;

			}
		}
	}
	cout << "plik zamknieto" << endl;
	fclose(file);
	return 0;
}

int cBohater::getRuch() const
{
    return ruch;
}

void cBohater::setRuch(int value)
{
    ruch = value;
}

int cBohater::getAtak() const
{
    return Atak;
}

void cBohater::setAtak(int value)
{
    Atak = value;
}

int cBohater::getCon() const
{
    return Con;
}

void cBohater::setCon(int value)
{
    Con = value;
}

int cBohater::getZr() const
{
    return Zr;
}

void cBohater::setZr(int value)
{
    Zr = value;
}

int cBohater::getHP() const
{
    return HP;
}

void cBohater::setHP(int value)
{
    HP = value;
}

float cBohater::getX() const
{
    return X;
}

void cBohater::setX(int value)
{
    X = value;
}

float cBohater::getY() const
{
    return Y;
}

void cBohater::setY(int value)
{
    Y = value;
}
cBohater::cBohater ()
{

    X=0;
    Y=0;
    ruch = 5;
    Atak = 11;
    Zr = 1;
    Con = 1;
    HP= 20;
}

cBohater::cBohater(int x, int y)
{

    X=x;
    Y=y;
    ruch = 5;
    Atak = 11;
    Zr = 1;
    Con = 1;
    HP = 20;
}

cBohater::cBohater(string klasa)
{
	dane3 = loadBMP_3();
    if(klasa=="Warrior")
    {

        X=0;
        Y=0;
        ruch = 5;
		Atak = 11;
        Con = 5;
        Zr = 2;
        HP = 20;
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
        HP = 20;
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
        HP = 20;
        cout<<"Wybrales/as podstawowa nacje"<<endl;
    }
}
void cBohater::rysujTeksture()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID3);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthh3, heightt3, 0, GL_RGB, GL_UNSIGNED_BYTE, dane3);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glColor3d(1, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 1);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord2f(0, 1);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord2f(0, 0);
	glVertex3f(-0.5, -0.5, 0);
	glTexCoord2f(1, 0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}
/*
void cBohater::przemiescBoh(char kier, cMapa& map)
{
if(ruch>0){
    switch(kier){
    case 's':

        if(X  <( map.getszerokosc() - 1))
            if(map.gettab()[X + 1][Y] != 1){
                this->X = this->X + 1;
                ruch -= 1;}
        break;
    case 'w':

        if(X  > 0)
            if(map.gettab()[X - 1][Y] != 1){
                this->X = this->X  - 1;
                ruch -= 1;}
        break;
    case 'd':
        if(Y  <( map.getdlugosc() - 1)){
            if(map.gettab()[X][Y+1] != 1)
                this->Y = this->Y + 1;
                ruch -= 1;}
        break;
    case 'a':
        if(Y  >0)
            if(map.gettab()[X][Y - 1] != 1){
                this->Y = this->Y - 1;
                ruch -= 1;}
        break;
    default:
        break;
    }}
}
*/
void cBohater::rysuj()
{
    glPushMatrix();
    //glTranslated(-0.5*100+1,0.5*100-1,0);
    //glTranslated(X,Y,0);
    glColor3ub(255,0,0);
	rysujTeksture();
	/*
    glBegin(GL_POLYGON);
    for(int i=0; i<361; i++)
    {
        float iy;
        float ix;
        iy=0.1*cos(i)+0.3;
        ix=0.1*sin(i);
        glVertex2f(ix,iy);
    }
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.05,0.2);
    glVertex2f(0.05,0.2);
    glVertex2f(0.05,-0.3);
    glVertex2f(-0.05,-0.3);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(-0.03,0.2);
    glVertex2f(-0.04,0.2);
    glVertex2f(-0.4,0);
    glVertex2f(-0.35,0);
    glEnd();
	*/
//                       glBegin(GL_POLYGON);
//                       glVertex3f(  0.5, -0.5, 0.2 );
//                       glVertex3f(  0.5,  0.5, 0.2 );
//                       glVertex3f( -0.5,  0.5, 0.2 );
//                       glVertex3f( -0.5, -0.5, 0.2 );
//                       glEnd();
//                       glBegin(GL_POLYGON);
//                       glVertex3f( 0.5, -0.5, 0);
//                       glVertex3f( 0.5,  0.5, 0 );
//                       glVertex3f( 0.5,  0.5,  0.2 );
//                       glVertex3f( 0.5, -0.5,  0.2 );
//                       glEnd();

//                       glBegin(GL_POLYGON);
//                       glVertex3f( -0.5, -0.5,  0.2 );
//                       glVertex3f( -0.5,  0.5,  0.2 );
//                       glVertex3f( -0.5,  0.5, 0 );
//                       glVertex3f( -0.5, -0.5, 0 );
//                       glEnd();

//                       glBegin(GL_POLYGON);
//                       glVertex3f(  0.5,  0.5,  0.2 );
//                       glVertex3f(  0.5,  0.5, 0 );
//                       glVertex3f( -0.5,  0.5, 0 );
//                       glVertex3f( -0.5,  0.5,  0.2 );
//                       glEnd();

//                       glBegin(GL_POLYGON);
//                       glVertex3f(  0.5, -0.5, 0 );
//                       glVertex3f(  0.5, -0.5,  0.2 );
//                       glVertex3f( -0.5, -0.5,  0.2 );
//                       glVertex3f( -0.5, -0.5, 0 );
//                       glEnd();

//                   glColor3ub(255,255,255);
//                   glLineWidth(2);
//               glBegin(GL_LINE_LOOP);
//               glVertex3f(  0.5, -0.5, 0.2 );
//               glVertex3f(  0.5,  0.5, 0.2 );
//               glVertex3f( -0.5,  0.5, 0.2 );
//               glVertex3f( -0.5, -0.5, 0.2 );
//               glEnd();
//                           glBegin(GL_LINE_LOOP);
//               glVertex3f( 0.5, -0.5, 0);
//               glVertex3f( 0.5,  0.5, 0 );
//               glVertex3f( 0.5,  0.5,  0.2 );
//               glVertex3f( 0.5, -0.5,  0.2 );
//               glEnd();
//               glBegin(GL_LINE_LOOP);
//               glVertex3f( -0.5, -0.5,  0.2 );
//               glVertex3f( -0.5,  0.5,  0.2 );
//               glVertex3f( -0.5,  0.5, 0 );
//               glVertex3f( -0.5, -0.5, 0 );
//               glEnd();
//                           glBegin(GL_LINE_LOOP);
//               glVertex3f(  0.5,  0.5,  0.2 );
//               glVertex3f(  0.5,  0.5, 0 );
//               glVertex3f( -0.5,  0.5, 0 );
//               glVertex3f( -0.5,  0.5,  0.2 );
//               glEnd();
//               glBegin(GL_LINE_LOOP);
//               glVertex3f(  0.5, -0.5, 0 );
//               glVertex3f(  0.5, -0.5,  0.2 );
//               glVertex3f( -0.5, -0.5,  0.2 );
//               glVertex3f( -0.5, -0.5, 0 );
//               glEnd();
               glPopMatrix();
}
