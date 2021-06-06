#include "Enemigo.h"

Enemigo::Enemigo()
{
	verde = 255;
	rojo = 100;
	azul = 100;
}

Enemigo::~Enemigo()
{
}

float Enemigo::GetRadio() {
	return altura;
}