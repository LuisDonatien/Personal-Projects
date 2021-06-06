#include "Sirena.h"

Sirena::Sirena(): mermaidUP("imagenes/mermaid.png", 1, 1),
				  mermaidDOWN("imagenes/mermaidDOWN.png", 7, 5){

}

Sirena::~Sirena() {

}

Sirena::Sirena(float px, float py): mermaidUP("imagenes/mermaid.png", 1, 1),
									mermaidDOWN("imagenes/mermaidDOWN.png", 7, 5) {
	verde = 0;
	rojo = 255;
	azul = 0;
	altura = 1.0f;
	salto_max = 20.0f;
	salto_min = 3.0f;
	velocidad.y = 5.0;
	posicion.x = px;
	posicion.y = py;
}

void Sirena::Mueve(float t) {
	
	ObjetoMovil::Mueve(t);
	Salto();
}

void Sirena::Salto() {
	if (posicion.y < salto_min) {
		posicion.y = salto_min;
		velocidad.y = 10.0f;
		aceleracion.y = 1.5f;
	}

	else if (posicion.y > salto_max) {
		posicion.y = salto_max;
		aceleracion.y = -10.0f;
		velocidad.y = -0.1;
	}
}

void Sirena::Dibuja() {
	
//Dimensiones del sprite
	mermaidUP.setCenter(1.4, 1);
	mermaidUP.setSize(2.5, 2.5);

	mermaidDOWN.setCenter(1.8, 1.8);
	mermaidDOWN.setSize(3.5, 3.5);
//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (velocidad.y > 0.01f) {
		mermaidUP.flip(true, false);
		mermaidUP.draw();
		mermaidUP.loop();
	}
	else if (velocidad.y < 0.01f) {
		mermaidDOWN.draw();
		mermaidDOWN.loop();
	}
	glPopMatrix();

	//////////Dibuja el Hitbox de sirena
	if (estado == Show) {
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 0);
		glColor3f(rojo, verde, azul);
		glutWireSphere(altura, 10, 10);
		glTranslatef(-posicion.x, -posicion.y, 0);
		glPopMatrix();
	}
}
