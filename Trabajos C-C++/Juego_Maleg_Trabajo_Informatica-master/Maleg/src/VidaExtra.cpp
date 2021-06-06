#include "VidaExtra.h"
#include "glut.h"

VidaExtra::VidaExtra(): apple("imagenes/apple.png", 1, 1) {
	radio = 0.5f;
	rojo = 255;
	verde = azul = 0;
	velocidad.x = 0;
	velocidad.y = -3.0f;
}

VidaExtra::VidaExtra(float px, float py, float posfin,float r, float vy): apple("imagenes/extralife.png", 3, 1) {
	posicion.x = px;
	posicion.y = py;
	posicionfin = posfin;
	radio = r;
	rojo = 255;
	verde = azul = 0;
	velocidad.x = 0;
	velocidad.y = vy;

}

VidaExtra::~VidaExtra() {

}
void VidaExtra::Dibuja() {
	//Dimensiones del sprite
	apple.setCenter(1, 1);
	apple.setSize(2, 2);

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	apple.draw();
	apple.loop();
	glPopMatrix();

}
void VidaExtra::Mueve(float t) {
	ObjetoMovil::Mueve(t);
	if (posicion.y = posicionfin)//las vidas caen del cielo
		velocidad.y = 0.0;
}

