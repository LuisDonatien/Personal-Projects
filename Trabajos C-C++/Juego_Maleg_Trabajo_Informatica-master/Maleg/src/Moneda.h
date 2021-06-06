#pragma once
#include <ETSIDI.h>
#include "Vector2D.h"
#include "ObjetoMovil.h"

using ETSIDI::SpriteSequence;

class Moneda:public ObjetoMovil
{
private:
	
	float radio_min;
	float radio_max;
	float pulso;
	
public:

	SpriteSequence coin;
	Moneda();
	Moneda(float px, float py,float radio,unsigned char r,unsigned char v,unsigned char a);//para inicializarlas
	~Moneda();

	void Dibuja();
	void Mueve(float t);
};
