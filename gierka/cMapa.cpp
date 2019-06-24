#include "cMapa.h"

unsigned int widthh, heightt;
GLuint textureID;
unsigned int widthh2, heightt2;
GLuint textureID2;
char *loadBMP_custom()
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int imageSize;   // = width*height*3
	char * data;

	// Open the file
	FILE * file = fopen("tlo.bmp", "rb");
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
				widthh = *(int*)&(header[0x12]);
				heightt = *(int*)&(header[0x16]);

				// Some BMP file nie maja wewnych danych
				if (imageSize == 0)    imageSize = widthh*heightt * 3; // 3 : one byte for each Red, Green and Blue component

				cout << "\npozycja aktualna dane: " << dataPos << endl << "wielkosc obrazka " << imageSize << endl << "szerokosc " << widthh << endl << "wysokosc " << heightt << endl << endl;

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

				glGenTextures(1, &textureID);

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

char *loadBMP_2()
{
	unsigned char header2[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos2;     // Position in the file where the actual data begins
	unsigned int imageSize2;   // = width*height*3
	char * data2;
	FILE * file = fopen("kamien.bmp", "rb");
	if (!file)
	{
		printf("nie otwarto obrazka\n");
	}
	else
	{
		cout << "poprawnie otwarto plik" << endl;

		if (fread(header2, 1, 54, file) != 54)
		{
			printf("nie poprawny plik BMP\n");
		}
		else
		{
			cout << "nag³owek jest poprawny" << endl;

			if (header2[0] != 'B' || header2[1] != 'M')
			{
				printf("to nie jest plik BMP\n");
			}
			else
			{
				cout << "Dane pliku sa zgodne, pobieram" << endl;
				dataPos2 = *(int*)&(header2[0x0A]);
				imageSize2 = *(int*)&(header2[0x22]);
				widthh2 = *(int*)&(header2[0x12]);
				heightt2 = *(int*)&(header2[0x16]);

				// Some BMP file nie maja wewnych danych
				if (imageSize2 == 0)    imageSize2 = widthh2*heightt2 * 3; // 3 : one byte for each Red, Green and Blue component

				cout << "\npozycja aktualna dane: " << dataPos2 << endl << "wielkosc obrazka " << imageSize2 << endl << "szerokosc " << widthh2 << endl << "wysokosc " << heightt2 << endl << endl;

				//---------------------------------------------------
				// tworzenie tablicy z danymi
				data2 = new char[imageSize2];

				// wpisanie do tablicy
				fread(data2, 1, imageSize2, file);

				for (int i = 0; i < imageSize2; i += 3)
				{
					char tmp = data2[i];
					data2[i] = data2[i + 2];
					data2[i + 2] = tmp;
				}

				// Create one OpenGL texture
				glEnable(GL_DEPTH_TEST);
				glEnable(GL_TEXTURE_2D);

				glGenTextures(1, &textureID2);

				cout << "plik zamknieto" << endl;
				fclose(file);

				return data2;

			}
		}
	}
	cout << "plik zamknieto" << endl;
	fclose(file);
	return 0;
}

cMapa::cMapa()
{

    this->dlugosc = 100;
    this->szerokosc = 100;
    tab = new int*[szerokosc];
    for(int i = 0; i < szerokosc; i++){
        tab[i] = new int[dlugosc];
    }
    for(int i=0; i<dlugosc; i++)
    {
        for(int j=0;j<szerokosc;j++)
        {
        tab[i][j]=0;
        }
    }
	//dane = loadBMP_custom();
}

cMapa::cMapa(int sz, int dl)
{
	dane = loadBMP_custom();
	dane2 = loadBMP_2();
    this->dlugosc = dl;
    this->szerokosc = sz;
    tab = new int*[szerokosc];
    for(int i = 0; i < szerokosc; i++){
        tab[i] = new int[dlugosc];
    }
    for(int i=0; i<dlugosc; i++)
    {
        for(int j=0;j<szerokosc;j++)
        {
        tab[i][j]=0;
        }
    }
}

void cMapa::wyswietl()
{
    for(int i=0; i<dlugosc; i++)
    {
        for(int j=0;j<szerokosc;j++)
        {
        cout<<tab[i][j];
        }
        cout<<endl;
    }
}
void cMapa::zmienPola()
{
    srand(time(NULL));
    for(int i=0; i<dlugosc; i++)
    {
        for(int j=0;j<szerokosc;j++)
        {
        tab[i][j]=rand()%2;
        }
    }
}
void cMapa::poprawaPol()
{
    for(int i=0; i<dlugosc; i++)
        for(int j=0;j<szerokosc;j++){
                tab[i][j]=0;
                //tab[52][52]=1;
                tab[4][4]=1;
                tab[0][j]=1;
                tab[99][j]=1;
                tab[i][0]=1;
                tab[i][99]=1;
				if ((i > 80)&&(i<98))
					tab[i][25] = 1;
				if (j < 50)
					tab[80][j] = 1;
				
    }
	/*
    int temp;
    for(temp = 2;temp <6;temp++){
        if(rand()%2 == 1){
            tab[dlugosc/temp][szerokosc/temp] = 1;
            tab[dlugosc/temp +1][szerokosc/temp+1] = 1;
            tab[dlugosc/temp +2][szerokosc/temp+1] = 1;
            tab[dlugosc/temp][szerokosc/temp +1] = 1;
            tab[dlugosc-1][szerokosc/temp] = 1;
            tab[dlugosc -1][szerokosc/temp+1] = 1;
            tab[dlugosc -2][szerokosc/temp+1] = 1;

        }

    }
	*/
    for(int i=0; i<10; i++)
    {
        if(rand()%2==1){
            tab[dlugosc-1][szerokosc-1]=1;
            tab[dlugosc-2][szerokosc-2]=1;
        }
		
    }


    /*temp = 3;
    if(rand()%2 == 1)
    {
      tab[dlugosc/temp][szerokosc/temp] = 1;
      tab[dlugosc/temp +1][szerokosc/temp+1] = 1;
      tab[dlugosc/temp +1][szerokosc/temp] = 1;
      tab[dlugosc/temp][szerokosc/temp +1] = 1;
    }*/
}
void cMapa::rysujprzejscie(double _x, double _y)
{
	glPushMatrix();
	glTranslated(_x, _y, 0);
	glColor3ub(0, 0, 200);
	glBegin(GL_POLYGON);
	glVertex2d(0.5, 0.5);
	glVertex2d(-0.5, 0.5);
	glVertex2d(-0.5, -0.5);
	glVertex2d(0.5, -0.5);
	glEnd();

	glTranslated(-_x, -_y, 0);
	glPopMatrix();
}
void cMapa::przejscie(double _x, double _y)
{
	if ((_x == 25)&& (_y == 40))
		tab[80][5] = 0;

}
void cMapa::rysujPole()
{
	
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthh, heightt, 0, GL_RGB, GL_UNSIGNED_BYTE, dane);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, widthh, heightt,GL_RGB, GL_UNSIGNED_BYTE, dane);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, TextureImage[0]->sizeX, TextureImage[0]->sizeY,0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glColor3d(1, 1, 1);
	glBegin(GL_QUADS);
	glTexCoord2f(5, 5);
	glVertex3f(50, 50,0);
	glTexCoord2f(0, 5);
	glVertex3f(-50, 50,0);
	glTexCoord2f(0, 0);
	glVertex3f(-50, -50,0);
	glTexCoord2f(5, 0);
	glVertex3f(50, -50,0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cMapa::rysujKamien()
{
	//glEnable(GL_TEXTURE_2D);
	//glBindTexture(GL_TEXTURE_2D, textureID);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthh2, heightt2, 0, GL_RGB, GL_UNSIGNED_BYTE, dane2);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	//glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glColor3d(1, 1, 0);
	//glDisable(GL_TEXTURE_2D);
	glBegin(GL_POLYGON);
	glTexCoord3f(1, 1,1);
	glVertex3f(0.5, -0.5, 0.5);
	glTexCoord3f(0, 1,1);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord3f(0, 0,1);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord3f(1, 0,1);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();
	glBegin(GL_POLYGON);
	glTexCoord3f(1, 1,0);
	glVertex3f(0.5, -0.5, 0);
	glTexCoord3f(0, 1,0);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord3f(0, 0,1);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord3f(1, 0,1);
	glVertex3f(0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord3f(1, 1,1);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord3f(0, 1,1);
	glVertex3f(-0.5, 0.5, 0.5);
	glTexCoord3f(0, 0,0);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord3f(1, 0,0);
	glVertex3f(-0.5, -0.5, 0);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord3f(1, 1,1);
	glVertex3f(0.5, 0.5, 0.5);
	glTexCoord3f(0, 1,0);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord3f(0, 0,0);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord3f(1, 0,1);
	glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glTexCoord3f(1, 1,0);
	glVertex3f(0.5, -0.5, 0);
	glTexCoord3f(0, 1,1);
	glVertex3f(0.5, -0.5, 0.5);
	glTexCoord3f(0, 0,1);
	glVertex3f(-0.5, -0.5, 0.5);
	glTexCoord3f(1, 0,0);
	glVertex3f(-0.5, -0.5, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
}

void cMapa::rysuj()
    {
		glPushMatrix();

		rysujPole();
//        glPushMatrix();

//        glTranslated(-0.5*this->getszerokosc(),0.5*this->getdlugosc(),0);
//        for(int j=0;j<this->getdlugosc();j++){
//            for(int i=0;i<this->getszerokosc();i++){
//                    glColor3ub(255,0,0);
//                    glLineWidth(2);
//                glBegin(GL_LINE_LOOP);
//                glVertex2f(0.5, 0.5);
//                glVertex2f(-0.5, 0.5);
//                glVertex2f(-0.5, -0.5);
//                glVertex2f(0.5, -0.5);
//                glVertex3f(0.5, 0.5,0);
//                glVertex3f(-0.5, 0.5,0);
//                glVertex3f(-0.5, -0.5,0);
//                glVertex3f(0.5,-0.5,0);
//                glVertex3f(0.5,0.5,0.5);
//                glVertex3f(-0.5,0.5,0.5);
//                glVertex3f(-0.5, -0.5,0.5);
//                glVertex3f(0.5, -0.5,0.5);
//                glEnd();
//                glTranslated(1,0,0);
//            }
//        glTranslated(-this->getszerokosc(),-1,0);
//        }
//        glPopMatrix();
        glTranslated(-0.5*this->getszerokosc(),0.5*this->getdlugosc(),0);
        for(int j=0;j<this->getdlugosc();j++){
            for(int i=0;i<this->getszerokosc();i++){
                if(this->wartoscPola(i,j)==0){
                    glColor3ub(0,245,255);
					/*
                                    glColor3ub(255,0,0);
                                    glLineWidth(2);
                                glBegin(GL_LINE_LOOP);
                                glVertex2f(0.5, 0.5);
                                glVertex2f(-0.5, 0.5);
                                glVertex2f(-0.5, -0.5);
                                glVertex2f(0.5, -0.5);
                                glEnd();
								*/
                }
                else
               {     glColor3ub(0,0,255);
				rysujKamien();
				/*
                    glBegin(GL_POLYGON);
                    glVertex3f(  0.5, -0.5, 0.5 );
                    glVertex3f(  0.5,  0.5, 0.5 );
                    glVertex3f( -0.5,  0.5, 0.5 );
                    glVertex3f( -0.5, -0.5, 0.5 );
                    glEnd();
					
                    glBegin(GL_POLYGON);
                    glVertex3f( 0.5, -0.5, 0);
                    glVertex3f( 0.5,  0.5, 0 );
                    glVertex3f( 0.5,  0.5,  0.5 );
                    glVertex3f( 0.5, -0.5,  0.5 );
                    glEnd();

                    glBegin(GL_POLYGON);
                    glVertex3f( -0.5, -0.5,  0.5 );
                    glVertex3f( -0.5,  0.5,  0.5 );
                    glVertex3f( -0.5,  0.5, 0 );
                    glVertex3f( -0.5, -0.5, 0 );
                    glEnd();

                    glBegin(GL_POLYGON);
                    glVertex3f(  0.5,  0.5,  0.5 );
                    glVertex3f(  0.5,  0.5, 0 );
                    glVertex3f( -0.5,  0.5, 0 );
                    glVertex3f( -0.5,  0.5,  0.5 );
                    glEnd();

                    glBegin(GL_POLYGON);
                    glVertex3f(  0.5, -0.5, 0 );
                    glVertex3f(  0.5, -0.5,  0.5 );
                    glVertex3f( -0.5, -0.5,  0.5 );
                    glVertex3f( -0.5, -0.5, 0 );
                    glEnd();
					*/
                glColor3ub(255,0,0);
                glLineWidth(2);
            glBegin(GL_LINE_LOOP);
            glVertex3f(  0.5, -0.5, 0.5 );
            glVertex3f(  0.5,  0.5, 0.5 );
            glVertex3f( -0.5,  0.5, 0.5 );
            glVertex3f( -0.5, -0.5, 0.5 );
            glEnd();
                        glBegin(GL_LINE_LOOP);
            glVertex3f( 0.5, -0.5, 0);
            glVertex3f( 0.5,  0.5, 0 );
            glVertex3f( 0.5,  0.5,  0.5 );
            glVertex3f( 0.5, -0.5,  0.5 );
            glEnd();
            glBegin(GL_LINE_LOOP);
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5,  0.5,  0.5 );
            glVertex3f( -0.5,  0.5, 0 );
            glVertex3f( -0.5, -0.5, 0 );
            glEnd();
                        glBegin(GL_LINE_LOOP);
            glVertex3f(  0.5,  0.5,  0.5 );
            glVertex3f(  0.5,  0.5, 0 );
            glVertex3f( -0.5,  0.5, 0 );
            glVertex3f( -0.5,  0.5,  0.5 );
            glEnd();
            glBegin(GL_LINE_LOOP);
            glVertex3f(  0.5, -0.5, 0 );
            glVertex3f(  0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5,  0.5 );
            glVertex3f( -0.5, -0.5, 0 );
            glEnd();
                }

                glTranslated(1,0,0);
            }
        glTranslated(-this->getszerokosc(),-1,0);
        }
		



		//glTranslated(35, 35, 0);

			glPopMatrix();
    }
