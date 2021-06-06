#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
class Arma :public ObjetoMovil
{
protected:
	float lado;

public:
	Arma();
	~Arma();
	float GetLado();
	void SetLado(float r);
	void SetColor(unsigned char r, unsigned char v, unsigned char a);
	virtual void Dibuja() {}
	virtual void Mueve(float t) {}
};