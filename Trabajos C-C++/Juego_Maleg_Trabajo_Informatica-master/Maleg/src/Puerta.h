#pragma once
#include "Plataforma.h"
#include "Interaccion.h"
#define MAX_PUER 3

using ETSIDI::SpriteSequence;

class Puerta :public Plataforma
{
public:
	Puerta();
	~Puerta();
	Puerta(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a);
	void Dibuja();//Gestiona la textura
	void DibujaP();//Gestiona la lista
	void DestruirContenido();
	bool Colision(Heroe* p);
	int numPuertas() { return num; }
	
	bool AgregarP(Puerta* p);
	int num;
	Puerta* lista[MAX_PUER];

};
