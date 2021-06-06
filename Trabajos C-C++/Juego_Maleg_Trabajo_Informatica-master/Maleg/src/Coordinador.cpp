#include "Coordinador.h"
#include "ETSIDI.h"
#include "glut.h"
//#include <locale.h>
#include <iostream>

using namespace std;
//char setlocale(LC_CTYPE, "spanish");

Coordinador::Coordinador(){
	ETSIDI::stopMusica();
	estado == INICIO;
	ETSIDI::playMusica("sonidos/Intro.wav");
}

Coordinador::~Coordinador(){
}

void Coordinador::TeclaEspecial(unsigned char key) {
	if (estado = JUEGO)
		mundo.TeclaEspecial(key);
}

void Coordinador::Tecla(unsigned char key) 
{
	if (estado == INICIO)
	{
		if (key == 's' || key == 'S')
		{
			cout << "INTRO" << endl;
			estado = INTRO;
		}
		else if (key == 'e' || key == 'E') 
			exit(0);
	}
	else if (estado == INTRO) 
	{
		if (key == ' ')
		{
			estado = CARGA;
			cout << "CARGA" << endl;
		}
	}
	else if (estado == CARGA) 
	{
		if (key == 'c' || key == 'C')
		{
			mundo.Inicializa();
			estado = JUEGO;
			cout << "JUEGO" << endl;
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Ambiente2.wav", true);
		}
	}
	else if (estado == JUEGO)
	{
		mundo.Tecla(key);
		if (key == 'p' || key == 'P')
			estado = PAUSA;
	}
	else if (estado == GAMEOVER)
	{
		if (key == 'c' || key == 'C') {
			mundo.resetNiv();

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

			estado = INICIO;
		}
		else if (key == 'e' || key == 'E')
			exit(0);
	}
	else if (estado == FIN)
	{
		if (key == 'c' || key == 'C') {
			mundo.resetNiv();
			
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

			estado = INICIO;

		}
		else if (key == 'e' || key == 'E')
			exit(0);
	}

	else if (estado == PAUSA) 
	{
		if (key == 'c' || key == 'C')
			estado = JUEGO;
		else if (key == 'e' || key == 'E')
		{
			mundo.resetNiv();

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/Intro.wav");

			estado = INICIO;
		}
	}
}

void Coordinador::TeclaUp(unsigned char key) 
{
	if (estado == JUEGO) {
		mundo.TeclaUp(key);
	}
}

void Coordinador::Mueve() {
	if (estado == JUEGO)
	{
		mundo.Mover();
		if (mundo.Muerte() == true)
		{
			estado = GAMEOVER;

			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/GameOver.wav");
		}

		if (mundo.GetFin() == true)
		{
			estado = FIN;
			mundo.SetFin(false);
			ETSIDI::stopMusica();
			ETSIDI::playMusica("sonidos/victory.wav");
		}
	}
}

void Coordinador::Dibuja() 
{
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		//Ponemos fondo a la pantalla de incicio
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/portada.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-20, -3, 0);
		glTexCoord2d(1, 1); glVertex3f(20, -3, 0); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(20, 28, 0);
		glTexCoord2d(0, 0); glVertex3f(-20, 28, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0.0f, 0.0f, 0.0f); //r g b
		ETSIDI::setFont("fuentes/The-Poster-King.ttf", 45);
		ETSIDI::printxy("MALEG", -15, 20);
		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f);
		ETSIDI::setFont("fuentes/War.ttf", 20);
		ETSIDI::printxy("PRESS S TO START", 4, -4);
		ETSIDI::printxy("PRESS E TO EXIT", 4, -6); //const char* txt ,int x,int y,int z=0
		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 14);
		ETSIDI::printxy("Maria Lahoz Arriscado", -18, -2);
		ETSIDI::printxy("Gema Novillo Villafranca", -18, -4);
		ETSIDI::printxy("Elvira Reyes Ballesteros", -18, -6);
		ETSIDI::printxy("Adrian Sanchez Atienza", -18, -8);
		ETSIDI::printxy("Luis Waucquez Jimenez", -18, -10);
	}
	else if (estado == INTRO)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/comandos.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//Ajuste imagen 
		glTexCoord2d(0, 1); glVertex3f(-22, -15, 0);
		glTexCoord2d(1, 1); glVertex3f(22, -15, 0); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(22, 28, 0);
		glTexCoord2d(0, 0); glVertex3f(-22, 28, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//Texto introductorio
		ETSIDI::setTextColor(0.0f, 0.0f, 0.0f); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("1250 a.c. La guerra de Troya llega a su fin. Ulises decide poner rumbo a Itaca, su hogar.", -19, 25);
		ETSIDI::printxy("Para acortar el camino decide ir por la isla de los ciclopes. Avistando a lo lejos Itaca,", -19, 24);
		ETSIDI::printxy("Polifemo, el mas grande y cruel de los monstruos se interpone en su camino.", -19, 23);

		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Ulises luchara por escapar y sobrevivir, ¿estas list@ para luchar? ", -19, 21);

		ETSIDI::setFont("fuentes/Bitwise.ttf", 15);
		ETSIDI::printxy("PRESS SPACE TO CONINUE ", -7, -12);
	
	}
	else if (estado == JUEGO)
	{
		mundo.Dibuja();
		mundo.Muerte();///Para comprobar si la colision mataba al personaje
	}
	else if (estado == PAUSA) 
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/pause.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//Ajuste imagen 
		glTexCoord2d(0, 1); glVertex3f(0.5, -0.5, 0);
		glTexCoord2d(1, 1); glVertex3f(0.5, -0.5, 0); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(0.5, 0.5, 0);
		glTexCoord2d(0, 0); glVertex3f(-0.5, 0.5, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		//Código de dibujo de la pantalla PAUSA
		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
		ETSIDI::setFont("fuentes/War.ttf", 70);
		ETSIDI::printxy("PAUSE", -16, 12);
		ETSIDI::setFont("fuentes/War.ttf", 30);
		ETSIDI::printxy("PRESS  C  T0 C0NTINUE", -10, 0);
		ETSIDI::printxy("PRESS  E  T0 EXIT", -10, -5);
	}
	else if (estado == CARGA)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/loading.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//Ajuste imagen 
		glTexCoord2d(0, 1); glVertex3f(-10, -3, 0);
		glTexCoord2d(1, 1); glVertex3f(10, -3, 0);
		glTexCoord2d(1, 0); glVertex3f(10, 20, 0);
		glTexCoord2d(0, 0); glVertex3f(-10, 20, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f); //r g b
		ETSIDI::setFont("fuentes/Bitwise.ttf", 25);
		ETSIDI::printxy("PRESS  C  T0 C0NTINUE", -11, -4);
	}
	else if (estado == GAMEOVER) 
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/GameOver.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		//Ajuste imagen 
		glTexCoord2d(0, 1); glVertex3f(-22, -3, 0);
		glTexCoord2d(1, 1); glVertex3f(18, -3, 0); 
		glTexCoord2d(1, 0); glVertex3f(18, 28, 0);
		glTexCoord2d(0, 0); glVertex3f(-22, 28, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(255.0f, 255.0f, 255.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 25);
		ETSIDI::printxy("PRESS C TO START A NEW GAME", -16, -3);
		ETSIDI::printxy("PRESS E TO EXIT", -8, -6);
	}
	else if (estado == FIN)
	{
		gluLookAt(0, 7.5, 3, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		//Ponemos fondo a la pantalla de incicio

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/win.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex3f(-20, -15, 0);
		glTexCoord2d(1, 1); glVertex3f(20, -15, 0); //se elige donde poner la imagen de fondo. ponemos -0.1 en z para que esté de fondo
		glTexCoord2d(1, 0); glVertex3f(20, 28, 0);
		glTexCoord2d(0, 0); glVertex3f(-20, 28, 0);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		
		//Parte inferior
		ETSIDI::setTextColor(0.0f, 0.0f, 0.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 25);
		ETSIDI::printxy("PRESS C TO START A NEW GAME", -15, -9);
		ETSIDI::printxy("PRESS E TO EXIT", -8, -12);
		
		//Texto parte superior
		ETSIDI::setTextColor(0.0f, 0.0f, 0.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 19);
		ETSIDI::printxy("Tras derrotar a los monstruos de la isla de los ciclopes, Ulises ", -19, 25);
		ETSIDI::printxy("libera a sus amigos y por fin ponen rumbo a Itaca", -15, 23);

		//Texto has ganado
		ETSIDI::setTextColor(0.0f, 0.0f, 0.0f);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 18);
		ETSIDI::printxy("Gracias a tu ayuda ", 7, 15);
		ETSIDI::printxy("Ulises ha conseguido ", 7, 13);
		ETSIDI::printxy("escapar y volver ", 7, 11);
		ETSIDI::printxy("a casa ", 10, 9);
	}
}