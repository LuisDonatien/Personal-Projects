#include "Arma.h"
#include "glut.h"

Arma::Arma() {
	estado = Hide;
}

Arma::~Arma() {

}

void Arma::SetColor(unsigned char r, unsigned char v, unsigned char a) {
	rojo = r;
	verde = v;
	azul = a;
}

void Arma::SetLado(float r) {
	lado = r;
}

float Arma::GetLado() {
	return lado;
}

