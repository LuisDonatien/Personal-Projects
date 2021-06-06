#pragma once
#include <ETSIDI.h>
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;

class VidaExtra : public ObjetoMovil
{
private:
	float posicionfin;
public:
	
	SpriteSequence apple;
	VidaExtra();
	VidaExtra(float px, float py, float posfin,float r,float vy);
	~VidaExtra();
	void Dibuja();
	void Mueve(float t);

};
