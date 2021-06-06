#include "ObjetoMovil.h"

void ObjetoMovil::Mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
}

// METODOS SET
void ObjetoMovil::SetPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}
void ObjetoMovil::SetVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
void ObjetoMovil::SetAce(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

// METODOS GET
Vector2D ObjetoMovil::GetPos() {
	return posicion;
}
Vector2D ObjetoMovil::GetVel() {
	return velocidad;
}
Vector2D ObjetoMovil::GetAce() {
	return aceleracion;
}
void ObjetoMovil::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}
void ObjetoMovil::SetRadio(float r) {
	radio = r;
}
float ObjetoMovil::GetRadio() {
	return radio;
}
