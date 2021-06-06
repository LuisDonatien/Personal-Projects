#pragma once
#include "Vector2D.h"
#include "Heroe.h"
class Plataforma {
protected:
	Vector2D limite1;
	Vector2D limite2;
	float grosor;
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
public:
	Plataforma();
	Plataforma(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a);
virtual ~Plataforma();

void SetPos(float x1, float y1,float x2,float y2,float gr);
void SetColor(unsigned char r, unsigned char v, unsigned char a);

Vector2D Getlimite1();
Vector2D Getlimite2();
float GetGrosor();

	    void Dibuja();
virtual void Mueve(float t);

virtual void Reaccion(Heroe* pers);

};