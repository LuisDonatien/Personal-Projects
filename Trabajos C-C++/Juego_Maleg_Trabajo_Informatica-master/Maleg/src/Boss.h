#pragma once
#include <ETSIDI.h>
#include <iostream>
#include "Enemigo.h"
#include "ObjetoMovil.h"
#include "Heroe.h"
#include "Interaccion.h"
#include "ListaArmas.h"

using namespace std;

using ETSIDI::SpriteSequence;

class Boss : public Enemigo{
protected:
	int vida;
public:
	SpriteSequence boss;
	Boss();
	~Boss();

	void Mueve(float t);
	void Dibuja();

	void SetVida(int v);
	int GetVida();

	bool Colision(Heroe* p, Boss b);
	bool Colision(ListaArmas a, Boss b);
};

