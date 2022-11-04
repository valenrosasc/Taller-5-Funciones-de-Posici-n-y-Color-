//Universidad Tecnologica de Pereira.
//Ingeniería en Sistemas y Computación.
//IS284 Programación 2.
//Valentina Rosas Coral.
//Taller 5 Funciones de posicion y color.
//Observaciones.


//Librerias----------------------------------------------------------------------------------------------------------------------

#include<stdio.h>
#include<iostream>
#include<windows.h>
#include<string.h>
using namespace std;

//Funciones----------------------------------------------------------------------------------------------------------------------

void gotoxy( int x, int y );
void color(int c) ;
void listacolor();
void listaascii();
void lineasH(int x, int y, int r, char tipo);
void lineasV(int x, int y, int r, char tipo);
void cuadro(int xi, int yi, int xf, int yf, char tipo);
void relleno(int xin, int yin, int ancho, int alto, int caracter, int c);



//Posicionamiento, GotoXY --------------------------------------------------------------------------------------------------------

void gotoxy( int x, int y )
{
  HANDLE hcon;
  hcon = GetStdHandle ( STD_OUTPUT_HANDLE );
  COORD dwPos;
  dwPos.X = x;
  dwPos.Y = y;
  SetConsoleCursorPosition(hcon, dwPos );
}


//Estilo visual, color-----------------------------------------------------------------------------------------------------------

void color(int c) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c); }

//Lista de colores---------------------------------------------------------------------------------------------------------------

void listacolor()
{
		for(int i=0; i<=51; i++){
		gotoxy(0, i);
		color(i);
		cout<<"color "<<i<<endl;

		gotoxy(25, i);
		color(51+i);
		cout<<"color "<<i+51<<endl;

		gotoxy(50, i);
		color(102+i);
		cout<<"color "<<i+102<<endl;


		gotoxy(75, i);
		color(153+i);
		cout<<"color "<<i+153<<endl;

		gotoxy(100, i);
		color(204+i);
		cout<<"color "<<i+204<<endl;
		}
}

//lista ascii -------------------------------------------------------------------------------------------------------------------

void listaascii(){
		for(int i=0; i<=51; i++){
		gotoxy(0, i);
		cout<<(char)i<<" = "<<i;

		gotoxy(25, i);
		cout<<(char)(i+51)<<" = "<<(i+51);

		gotoxy(50, i);
		cout<<(char)(i+102)<<" = "<<(i+102);


		gotoxy(75, i);
		cout<<(char)(i+153)<<" = "<<(i+153);

		gotoxy(100, i);
		cout<<(char)(i+204)<<" = "<<(i+204);
		}
}


//lineash ----------------------------------------------------------------------------------------------------------------------

void lineasH(int x, int y, int r, char tipo){
for(int i=x;i<=x+r;i++)
{
gotoxy(i, y);
if(tipo=='s'){cout<<(char) (223);}
else {cout<<(char) (205);}


}
}

//lineasv ----------------------------------------------------------------------------------------------------------------------

void lineasV(int x, int y, int r, char tipo){
for(int i=y;i<=y+r;i++)
{
gotoxy(x, i);
if(tipo=='s'){cout<<(char) (219);}
else {cout<<(char) (186);}


}
}



//Cuadro lineas -----------------------------------------------------------------------------------------------------------------

void cuadro(int xi, int yi, int xf, int yf, char tipo)
{
	lineasH(xi,yf,xf-xi,tipo);
	lineasH(xi,yi,xf-xi,tipo);
	lineasV(xi,yi,yf-yi,tipo);
	lineasV(xf,yi,yf-yi,tipo);
	if(tipo =='s')
	{
		gotoxy(xi,yi);
		cout<<(char)(218);
		gotoxy(xi,yf);
		cout<<(char)(192);
		gotoxy(xf,yi);
		cout<<(char)(191);
		gotoxy(xf,yf);
		cout<<(char)(217);
	}
	else
	{
		gotoxy(xi,yi);
		cout<<(char)(201);
		gotoxy(xi,yf);
		cout<<(char)(200);
		gotoxy(xf,yi);
		cout<<(char)(187);	
		gotoxy(xf,yf);
		cout<<(char)(188);
	}
}


//Relleno ----------------------------------------------------------------------------------------------------------------------

void relleno(int xin, int yin, int ancho, int alto, int caracter, int c){
xin=xin-1;
yin=yin-1;

color(c);

    for ( int i=0; i<=ancho; i++)
    {
        for (int j=0; j<=alto; j++)
        {
			gotoxy(xin+i,yin+j);
            cout<<(char)caracter;
        }
        cout<<endl;
    }
}
//Ventana ------------------------------------------------------------------------------------------------------------------------

void ventana1 (int xin,int yin,int ancho,int alto,int colorfondo,int colorSombra)
{
	relleno(xin,yin,ancho,alto,219,colorfondo);
	color(colorSombra);
	lineasV(ancho+xin, yin, alto, 's');
	lineasH(xin, yin+alto, ancho, 's');
}

void ventana2 (int xin,int yin,int ancho,int alto, int colortitulo, int colorfondo,int colorSombra)
{
	ventana1 (42,4,30,7,3,8);
	
}


