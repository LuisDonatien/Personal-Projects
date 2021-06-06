#pragma once
#include <ETSIDI.h>
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "Heroe.h"

using ETSIDI::SpriteSequence;

class Boton :public ObjetoMovil
{
public:
	SpriteSequence button;

	Boton();
	Boton(float px, float py, float radio, unsigned char r, unsigned char v, unsigned char a);//para inicializarlas
	~Boton();

	bool Colision(Heroe* p, Boton b);
	void Dibuja();
	void DestruirContenido(Boton* b);
};
