#include <iostream>
#include "Heroe.h"
using namespace std;

Heroe::Heroe() :
	run("imagenes/spartanRUN.png", 4, 3),
	jumpUP("imagenes/spartanJUMPup.png", 4, 2),
	jumpDOWN("imagenes/spartanJUMPdown.png", 4, 3),

	vida1("imagenes/VIDA1.png", 1, 1),
	vida2("imagenes/VIDA2.png", 1, 1),
	vida3("imagenes/VIDA3.png", 1, 1),

	spearavailable("imagenes/lanza.png", 1, 1) 

{
	// Relativo a los atributos
	altura = 2.0f;
	rojo = azul = 0;
	verde = 255;
	monedas = 0;
	numeroRP = 0;
	sentido = Derecha;
}
Heroe::~Heroe(){
}
void Heroe::Mueve(float t) {
	if (velocidad.y < -10)
		velocidad.y = -10;
	ObjetoMovil::Mueve(t);
}

void Heroe::Dibuja() {
	//Dimensiones del sprite
	run.setCenter(1.5, 1.1);
	run.setSize(3.0, 3.0);

	jumpUP.setCenter(1.8f, 1.0f);
	jumpUP.setSize(3.0f, 3.0f);

	jumpDOWN.setCenter(1.8f, 1.0f);
	jumpDOWN.setSize(3.0f, 3.0f);

	vida1.setCenter(-15.0f, -18.0f);
	vida1.setSize(4.5f, 2.0f);

	vida2.setCenter(-15.0f, -18.0f);
	vida2.setSize(4.5f, 2.0f);

	vida3.setCenter(-15, -18);
	vida3.setSize(4.5f, 2.0f);

	spearavailable.setCenter(-14.5f, -16.0f);
	spearavailable.setSize(5.0f, 2.0f);

	//Dibujo
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);

	//tratamiento AnimationRUN
	if (velocidad.x > 0.01)run.flip(false, false);
	if (velocidad.x < -0.01)run.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		run.setState(0);
	else if (run.getState() == 0)
		run.setState(1, false);
	//tratamiento AnimationJUMPup
	if (velocidad.x > 0.01)jumpUP.flip(false, false);
	if (velocidad.x < -0.01)jumpUP.flip(true, false);

	//tratamiento AnimationJUMPdown
	if (velocidad.x > 0.01)jumpDOWN.flip(false, false);
	if (velocidad.x < -0.01)jumpDOWN.flip(true, false);

	// OPERANDI DIBUJO HEROE
	if (velocidad.y == 0) {
		run.draw();
		run.loop();
	}
	else if (velocidad.y > 0.01f) {
		jumpUP.draw();
		jumpUP.loop();
	}
	else if (velocidad.y < -0.01f) {
		jumpDOWN.draw();
		jumpDOWN.loop();
	}
	glPopMatrix();

	// DIBUJO HITBOX
	if (estado == Show) {
		//////////Dibuja el Hitbox de pajaro
		glPushMatrix();
		glColor3ub(rojo, verde, azul);
		glTranslatef(posicion.x, posicion.y, 1.0);
		glColor3f(rojo, verde, azul);
		glutWireCube(altura);
		glTranslatef(-posicion.x, -posicion.y, 1.0);
		glPopMatrix();
	}

	// DIBUJO VIDA
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (vida >= 3)
		vida3.draw();
	else if (vida == 2)
		vida2.draw();
	else if (vida == 1)
		vida1.draw();
	glPopMatrix();

	// DIBUJO LANZA DISPONIBLE
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.5);
	if (monedas > 0)
		spearavailable.draw();
	glPopMatrix();
}

void Heroe::SetAlturaMuerte(float am) {
	alturamuerte = am;
}
void Heroe::SetVida(float v) {
	vida = v;
}

void Heroe::SetMonedas(int m) {
	monedas = m;
}
bool Heroe::Muerte() {
	if (alturamuerte >= posicion.y) {	
		vida -= 1;
		if(vida==0)
			return true;
		else {
			velocidad.y = 0;
			PuntoReaparicion();
			return false;
		}
	}
	 if (vida==0) {
		return true;
	}
	else
		return false;
}

int Heroe::GetVida() {
	return vida;
}

int Heroe::GetMonedas() {
	return monedas;
}

void Heroe::SumarMonedas(bool m) {
	if(m == true)
		monedas ++;
	if (m == false)
		monedas--;
}

void Heroe::PuntoReaparicion() {
	velocidad.x = 0;
	velocidad.y = 0;
	aceleracion.y = 0;
	for (int i = 0;i < numeroRP;i++) {
		if (posicion.x < 0.0f){
		posicion = (*puntosR[0]);
		break;
		}
		else if (posicion.x < puntosR[i]->x) {
			posicion = (*(puntosR[i-1]));
			break;
		}
	}
}

bool Heroe::AgregarPuntosR(Vector2D *e) {
	for (int i = 0;i < numeroRP;i++) {
		if ((puntosR[i]) == e)
			return false;
	}
	if (numeroRP < Max_Size) {
		puntosR[numeroRP++] = e;
		
	}
	else {
		return false;
	}
		return true;
}

void Heroe::DestruirContenido() {
	for (int i = 0;i < numeroRP;i++) {
		delete puntosR[i];
	}
	numeroRP = 0;
}

bool Heroe::Disparo() {
	if (sentido == Izquierda)
		return false;
	if (sentido == Derecha)
		return true;
}

bool Heroe::ValidarDisparo() {
	if (monedas > 0)
		return true;
	else if(monedas ==0)
		return false;
}

void Heroe::SetSentido(bool e) {
	if (e == true)
		sentido = Derecha;

	else if (e == false)
		sentido = Izquierda;
}