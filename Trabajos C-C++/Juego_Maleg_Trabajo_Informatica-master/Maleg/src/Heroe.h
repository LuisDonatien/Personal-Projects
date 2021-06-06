#pragma once
#include <ETSIDI.h>
#include "Personaje.h"
#include "Enemigo.h"

#define Max_Size 10			//Numero puntos de reaparicion

using ETSIDI::SpriteSequence;

class Heroe: public Personaje{
protected:
	float vida;
	float alturamuerte;
	int monedas;
	int numeroRP;

	Vector2D *puntosR[Max_Size];
	enum Sentido {Izquierda,Derecha};
	Sentido sentido;
	
	SpriteSequence 
		run, jumpUP, jumpDOWN,
		vida1, vida2, vida3,
		spearavailable;
public:
	Heroe();
	virtual ~Heroe();

	//METODOS GET
	int GetVida();
	int GetMonedas();

	//METODOS SET
	void SetAlturaMuerte(float am);
	void SetVida( float v);
	void SetMonedas(int m);
	void SetSentido(bool e);

	//ANIMACIONES
	virtual void Dibuja();
	virtual void Mueve(float t);

	//FUNCIONES
	bool Muerte();
	void SumarMonedas(bool m);
	void PuntoReaparicion();
	bool AgregarPuntosR(Vector2D* p);
	void DestruirContenido();

	bool Disparo();
	bool ValidarDisparo();
};
