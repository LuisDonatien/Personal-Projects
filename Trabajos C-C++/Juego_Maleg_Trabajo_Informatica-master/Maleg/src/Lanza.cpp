#include "Lanza.h"
#include "glut.h"
Lanza::Lanza(float x,float y,float v): spear("imagenes/lanza.png",1,1) {
	posicion.x = x;
	posicion.y = y;
	velocidad.x = v;
	aceleracion.y = -9.8;
	rojo = 255;
	verde = 45;
	azul = 100;
	lado = 0.5;
}

Lanza::~Lanza() {

}

void Lanza::Dibuja() {
	//Dimensiones del sprite
	spear.setCenter(2.4, 0.2);
	spear.setSize(3, 0.5);

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	if (velocidad.x > 0.01)spear.flip(false, false);
	if (velocidad.x < -0.01)spear.flip(true, false);
	spear.setAngle(-20.0f);
	spear.draw();
	glPopMatrix();
}

void Lanza::Mueve(float t) {
	ObjetoMovil::Mueve(t);
}
