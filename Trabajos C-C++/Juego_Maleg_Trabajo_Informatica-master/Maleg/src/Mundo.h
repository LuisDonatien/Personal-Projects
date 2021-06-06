#pragma once
#include "Plataforma.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "NivelFinal.h"
#include "Interaccion.h"
#include "Personaje.h"

class Mundo {

private:
	Heroe heroe;
	Nivel1* nivel1;
	Nivel2* nivel2;
	Nivel3* nivel3;
	NivelFinal* nivelfinal;
	int nivel;
	bool fin;
public:
	Mundo();
	void Inicializa();
	
	virtual ~Mundo();


	void Dibuja();
	void Mover();

	void CargarNivel();
	void resetNiv() { nivel = 0; }

	void Tecla(unsigned char key);
	void TeclaUp(unsigned char key);
	void TeclaEspecial(unsigned char key);

	bool Muerte();
	bool GetFin();
	void SetFin(bool f);

};