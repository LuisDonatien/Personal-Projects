#include "Moneda.h"
#include "glut.h"

Moneda::Moneda(): coin("imagenes/coin.png", 6, 1) {
	rojo = verde = 255;
	azul = 0;
	radio = 0.5;
	radio_max = 0.5f;
	radio_min = 0.35f;
	pulso = 0.5f;
}
Moneda::Moneda(float px, float py, float rad, unsigned char r, unsigned char v, unsigned char a): coin("imagenes/coin.png", 6, 1) {
	posicion.x = px;
	posicion.y = py;
	rojo = r;
	verde = v;
	azul = a;
	radio = rad;
	radio_max = 0.5f;
	radio_min = 0.35f;
	pulso = 0.5f;
}

Moneda::~Moneda(){

}


void Moneda::Dibuja() {
	//Dimensiones del sprite
	coin.setCenter(0.5, 0.5);
	coin.setSize(1, 1);

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	coin.draw();
	coin.loop();
	glPopMatrix();
}

void Moneda::Mueve(float t) {
	if (radio > radio_max)
		pulso = -pulso;

	if (radio < radio_min)
		pulso = -pulso;

	radio += pulso * t;
}
