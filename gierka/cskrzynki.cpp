#include "cskrzynki.h"

unsigned int widthh1, heightt1;
GLuint textureID1;

char *loadBMP_1()
{
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int imageSize;   // = width*height*3
	char * data;

	// Open the file
	FILE * file = fopen("kufer.bmp", "rb");
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
				widthh1 = *(int*)&(header[0x12]);
				heightt1 = *(int*)&(header[0x16]);

				// Some BMP file nie maja wewnych danych
				if (imageSize == 0)    imageSize = widthh1*heightt1 * 3; // 3 : one byte for each Red, Green and Blue component
				
				cout << "\npozycja aktualna dane: " << dataPos << endl << "wielkosc obrazka " << imageSize << endl << "szerokosc " << widthh1 << endl << "wysokosc " << heightt1 << endl << endl;

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

				glGenTextures(1, &textureID1);

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

int cSkrzynki::getY() const
{
    return y;
}

void cSkrzynki::setY(int value)
{
    y = value;
}

int cSkrzynki::getX() const
{
    return x;
}

void cSkrzynki::setX(int value)
{
    x = value;
}
cSkrzynki::cSkrzynki()
{
    x=0;
    y=0;
}

cSkrzynki::cSkrzynki(int X, int Y)
{
    x=X;
    y=Y;
	dane1 = loadBMP_1();
}

void cSkrzynki::rysujSkrzynke()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureID1);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, widthh1, heightt1, 0, GL_RGB, GL_UNSIGNED_BYTE, dane1);
	//gluBuild2DMipmaps(GL_TEXTURE_2D, 3, widthh, heightt,GL_RGB, GL_UNSIGNED_BYTE, dane);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, TextureImage[0]->sizeX, TextureImage[0]->sizeY,0, GL_RGB, GL_UNSIGNED_BYTE, TextureImage[0]->data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	glColor3d(1, 1, 0);
	glBegin(GL_QUADS);
	glTexCoord3f(1, 1,0);
	glVertex3f(0.5, 0.5, 0);
	glTexCoord3f(0, 1,0);
	glVertex3f(-0.5, 0.5, 0);
	glTexCoord3f(0, 0,0);
	glVertex3f(-0.5, -0.5, 0);
	glTexCoord3f(1, 0,0);
	glVertex3f(0.5, -0.5, 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);

}

void cSkrzynki::rysuj()
{

    glPushMatrix();

        glTranslated(x,y,0);
        glColor3ub(255,0,0);
		rysujSkrzynke();


        glPopMatrix();
}
