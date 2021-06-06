#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Araña: public Enemigo{
private:
	float lim_xi;
	float lim_xd;
	float lim_ya;
	float lim_yb;


public:
	SpriteSequence spyder;

	Araña();
	Araña(float px, float py);
	Araña(float px, float py, float limitex, float limitey);
	~Araña();
	void Mueve(float t);
	void Movimiento();
	void Dibuja();
};

