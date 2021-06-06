#pragma once
#include "Vector2D.h"
#include "Plataforma.h"
#include "Heroe.h"
class PlataformaMovil : public Plataforma{
private:
	int contador;
	int paso;
	float tiempo;
	Vector2D velocidad;
public:
	PlataformaMovil(float x1, float y1, float x2, float y2, float gr,float p,float vx,float vy, unsigned char r, unsigned char v, unsigned char a);
	virtual ~PlataformaMovil();
	void Mueve(float t);

	void Reaccion(Heroe *pers);
};