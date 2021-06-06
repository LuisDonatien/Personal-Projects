#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;
class Guerreros: public Enemigo{
private:
	float lim_xd;
	float lim_xi;
	int vida;

public:
	SpriteSequence skeleton;

	Guerreros();
	Guerreros(float px, float py, float max, float v);
	~Guerreros();

	void Mueve(float t);
	void Dibuja();
	void Movimiento();
};

