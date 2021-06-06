#include "Boton.h"
#include "Interaccion.h"
#include <iostream>
#include "glut.h"

using namespace std;

Boton::Boton(): button("imagenes/button.png", 1, 1) {
	rojo = 255;
	verde = azul = 0;
	radio = 1.0f;
}

Boton::Boton(float px, float py, float rad, unsigned char r, unsigned char v, unsigned char a) : button("imagenes/button.png", 1, 1){
	posicion.x = px;
	posicion.y = py;
	rojo = r;
	verde = v;
	azul = a;
	radio = rad;
}
Boton::~Boton() {

}

void Boton::Dibuja() {
	//Dimensiones del sprite
	button.setCenter(1.2, 1.2);
	button.setSize(2.4, 2.4);
	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	button.draw();
	glTranslatef(-posicion.x,- posicion.y,- 0.5);
	glPopMatrix();
}

bool Boton::Colision(Heroe* p, Boton b) {
	if (Interaccion::ColisionBoton(p, b))
	{
		return true;
	}
	return false;
}

void Boton::DestruirContenido(Boton* b) {
	delete b;
}
