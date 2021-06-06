#include "BolaFuego.h"

BolaFuego::BolaFuego(float px,float py,float a): fireball("imagenes/fireball.png", 4, 3) {
	posicion.x = px;
	posicion.y = py;
	rojo = 255;
	verde = 0;
	azul = 0;
	aceleracion.y = a;
	altura = 1.45;

}

BolaFuego::~BolaFuego() {

}

void BolaFuego::Dibuja() {
	//Dimensiones del sprite
	fireball.setCenter(7, 2.5);
	fireball.setSize(12, 12);

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	fireball.draw();
	fireball.loop();
	glPopMatrix();

	if (estado == Show) {
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 0.5);
		glColor3f(rojo, verde, azul);
		glutWireSphere(altura, 40, 40);
		glTranslatef(-posicion.x, -posicion.y, 0.5);
		glPopMatrix();
	}
}

void BolaFuego::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}