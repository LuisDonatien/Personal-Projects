#pragma once
#include <ETSIDI.h>
#include "Arma.h"

using ETSIDI::SpriteSequence;

class Lanza : public Arma {
public:
	SpriteSequence spear;

	Lanza(float x,float y,float v);
	virtual ~Lanza();

	void Dibuja();
	void Mueve(float t);
};