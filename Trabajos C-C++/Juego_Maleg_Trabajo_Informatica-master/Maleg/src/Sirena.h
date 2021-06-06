#pragma once
#include <ETSIDI.h>
#include "Enemigo.h"

using ETSIDI::SpriteSequence;

class Sirena: public Enemigo
{
private:
	float salto_max;
	float salto_min;
	
public:

	SpriteSequence mermaidUP, mermaidDOWN;

	Sirena();
	~Sirena();
	Sirena(float px, float py);
	void Salto(); 
	void Dibuja();
    void Mueve(float t);

};

