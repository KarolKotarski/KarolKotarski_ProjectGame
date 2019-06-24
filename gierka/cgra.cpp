
#include "cgra.h"


list<cSkrzynki> &CGra::getSkrzynka()
{
    return skrzynka;
}

void CGra::setSkrzynka(const list<cSkrzynki> &value)
{
    skrzynka = value;
}

list<cPotwor> &CGra::getPotwory()
{
    return potwory;
}

void CGra::setPotwory(const list<cPotwor> &value)
{
    potwory = value;
}

CGra::CGra()
{

    mapa = cMapa(100,100);
    mapa.poprawaPol();
    string prof;
	cout << "Podaj profesje:";
	//cin >> prof;
    //string prof2;
   // cin>>prof;
    //cin.ignore();
    bohater = cBohater(prof);
    //bohater2 = cBohater2(prof2);
    dodajSkrzynke(10,10);
	dodajSkrzynke(20, 20);
	dodajSkrzynke(-10, -10);
	dodajSkrzynke(100, 100);
	dodajSkrzynke(40, 24);
    dodajPotwora(29,15,0.2,0);
	dodajPotwora(31, 15,0.4,0);
	dodajPotwora(30, 10, 0.2, 0.1);
	dodajPotwora(29, 20, 0.3, 0);
	dodajPotwora(37, 24, 0.1, 0.001);
	dodajPotwora(43, 20, 0.09, 0.05);
	dodajPotwora(45, 15, 0.05, 0);
	dodajPotwora(111, 121, 0, 0);
	dodajPotwora(111, 121, 0, 0);
	dodajPotwora(48, 25,0,0);
	dodajPotwora(48, 25, 0, 0);
	dodajPotwora(48, 25, 0, 0);
	dodajPotwora(48, 25, 0, 0);
	dodajPotwora(48, 25, 0, 0);
    ortx=0;
    orty=0;
    zj1=0;
    zj2=0;
    zj3=0;
    zj4=0;
    Portal = portal();
	PasekCzerwony = CPasekZycia();
}
/*
void CGra::grafika()
{
    int x_= mapa.getdlugosc();
    int y_= mapa.getszerokosc();

    int** tab = new int*[x_];
    for(int i= 0;i<x_;i++){
        tab[i] = new int[y_];
    }
    for(int i= 0;i<x_;i++)
        for(int j= 0;j<y_;j++)
            tab[i][j]= mapa.gettab()[i][j];

    tab[bohater.getX()][bohater.getY()]=2;

     list<cPotwor>::iterator it;
     for (it=potwory.begin(); it!=potwory.end(); ++it)
        tab[it->getX()][it->getY()]=3;
     list<cSkrzynki>::iterator to;
     for (to=skrzynka.begin(); to!=skrzynka.end(); ++to)
        tab[to->getX()][to->getY()]=7;

    for(int i= 0;i<x_;i++){
        for(int j= 0;j<y_;j++){
            cout<<tab[i][j];
        }
        cout<<endl;
    }
}


void CGra::aktualizuj_stangry(char kier)
{

    if(kier =='x'){
        koniecTury();
    }
//    cout<<"HP: "<<bohater.getHP()<<endl;
    bohater.przemiescBoh(kier,mapa);

    sprawdzWalki();
    sprawdzSkrzynki();
//    if(bohater.getHP()<=0)
//        cout<<"Przegrana"<<endl;
}
*/
void CGra::dodajSkrzynke(int x, int y)
{
    cSkrzynki temp(x,y);
    skrzynka.push_back(temp);
    //temp.rysuj();
}


void CGra::dodajPotwora(int x, int y, double _parametrX, double _parametrY)
{
    cPotwor temp(x,y, _parametrX,_parametrY);
    potwory.push_back(temp);
}


//void CGra::koniecTury()
//{
//    bohater.setRuch(5);
//}

void CGra::sprawdzWalki()
{
    list<cPotwor>::iterator it;
    int tempx = bohater.getX();
    int tempy = bohater.getY();

    for (it=potwory.begin(); it!=potwory.end(); it++){
		//int xx;
		//int yy;
		//xx = it->getX() - ortx;
		//yy = it->getY() - orty;

		//if ((xx == tempx) && (yy == tempy))

		if (((tempx<(it->getX() - ortx + it->getpar()+0.5)) && (tempx>(it->getX() - ortx + it->getpar()-0.5) )) && (( tempy<(it->getY() - orty + it->getpar1()+0.5) ) && (tempy>(it->getY() - orty + it->getpar1()-0.5))))
	   {
         // for(it->getHP(); it->getHP()<=0; (it->setHP(it->getHP()-bohater.getAtak()))){

           if(bohater.getAtak()>=it->getHP())
           {
			   bohater.setHP(bohater.getHP() - it->getAtak());
			   PasekCzerwony.setX(PasekCzerwony.getX() - it->getAtak());

           potwory.erase(it);
           it=potwory.begin();

           }

           else
           {
           it->setHP(it->getHP()-bohater.getAtak());
           bohater.setHP(bohater.getHP()-it->getAtak());
           }
           //}
       }
    }
    //if(bohater.getHP()<=0)
     //   bohater.setX(bohater.getX()+100);

}

void CGra::sprawdzSkrzynki()
{
    list<cSkrzynki>::iterator to;
    int tempx = bohater.getX();
    int tempy = bohater.getY();

    for (to=skrzynka.begin(); to!=skrzynka.end();to++)
	{
		//if (skrzynka.size()>0)
		//{
			int xx;
			int yy;
			xx = to->getX() - ortx;
			yy = to->getY() - orty;
			if ((xx == tempx) && (yy == tempy)) {
				int temp = rand() % 1;
				switch (temp)
				{
				case 0: bohater.setHP(bohater.getHP() + 5);

					PasekCzerwony.setX(PasekCzerwony.getX() +5);
					break;
				//case 1: bohater.setAtak(bohater.getAtak() + 2);
					//break;
				default:break;
				}
				//if(to.z>2)
				

					skrzynka.erase(to);
					to = skrzynka.begin();
		}
		//else
		//{
		//	break;
		//}
    }
}

void CGra::sprawdzkratki()
{
    glTranslated(-0.5*mapa.getszerokosc(),0.5*mapa.getdlugosc(),0);
    for(int j=0;j<mapa.getdlugosc();j++){
        for(int i=0;i<mapa.getszerokosc();i++){
            if(mapa.wartoscPola(i,j)==1)
            {

                if((i-0.5*mapa.getszerokosc()-ortx+1==bohater.getX())&&(j-0.5*mapa.getdlugosc()+orty==bohater.getY()))
                {
                    zj1=1;

                }
                if((i-0.5*mapa.getszerokosc()-ortx-1==bohater.getX())&&(j-0.5*mapa.getdlugosc()+orty==bohater.getY()))
                {
                    zj2=1;

                }
                if((i-0.5*mapa.getszerokosc()-ortx==bohater.getX())&&(j-0.5*mapa.getdlugosc()+orty+1==bohater.getY()))
                {
                    zj3=1;

                }
                if((i-0.5*mapa.getszerokosc()-ortx==bohater.getX())&&(j-0.5*mapa.getdlugosc()+orty-1==bohater.getY()))
                {
                    zj4=1;

                }

        }

}
}
}


