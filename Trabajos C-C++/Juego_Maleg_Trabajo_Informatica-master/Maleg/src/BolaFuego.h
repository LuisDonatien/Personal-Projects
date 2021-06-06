#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;
class BolaFuego:public Enemigo {
protected:

public:
	SpriteSequence fireball;
	BolaFuego(float px, float py,float a);
	virtual ~BolaFuego();
	void Mueve(float t);
	void Dibuja();
};