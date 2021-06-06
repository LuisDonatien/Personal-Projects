#pragma once
#include "Vector2D.h"

class ObjetoMovil
{
protected:
	Vector2D posicion;
	Vector2D velocidad;
	Vector2D aceleracion;

	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
	enum Estado { Show, Hide };
	Estado estado;
public:
	virtual void Mueve(float t);

	// METODOS SET
	void SetPos(float x, float y);
	void SetVel(float vx, float vy);
	void SetAce(float ax, float ay);

	// METODOS GET
	Vector2D GetPos();
	Vector2D GetVel();
	Vector2D GetAce();

	float GetRadio();
	void SetRadio(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
};

