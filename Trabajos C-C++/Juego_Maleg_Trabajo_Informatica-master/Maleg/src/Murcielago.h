#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Murcielago: public Enemigo{

private:
	float lim_xd;
	float lim_xi;
	float lim_ya;
	float lim_yb;

public:

	SpriteSequence bat;

	Murcielago();
	Murcielago(float px, float py);
	~Murcielago();
	void Dibuja();
	void Mueve(float t);
	void Movimiento();

};

