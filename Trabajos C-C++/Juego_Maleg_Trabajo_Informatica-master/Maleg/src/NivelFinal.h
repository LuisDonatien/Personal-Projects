#pragma once
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "ListaArmas.h"
#include "ListaCorazones.h"
#include <string>
#include "Heroe.h"
#include "Sirena.h"
#include "Lanza.h"
#include "Puerta.h"
#include "Interaccion.h"
#include "Boton.h"
#include "BolaFuego.h"
#include "Boss.h"

using namespace std;

class NivelFinal {
private:
	Heroe heroe;
	ListaPlataformas plataformas;			///Objeto contiene todas las plataformas NivelFinal
	ListaMonedas monedas;					///Objeto contiene todas las monedas NivelFinal
	ListaEnemigos ciclopes;					///Objeto contiene todos los ciclopes NivelFinal
	ListaEnemigos bolasdefuego;				///Objeto contiene todos los bolasdeFuego NivelFinal
	ListaEnemigos enemigos;
	ListaArmas armas;					    ///Objeto contiene todas las lanzas
	ListaCorazones corazones;
	Puerta puerta;
	Boton boton;							//Objeto gestiona el boton
	Boss boss;

	
	enum Estado { ShowHitbox, HideHitbox };
	Estado estado = HideHitbox;
	Vector2D spawn_enemigos;
	string Fichero = "NivelFinal.txt";
	int vida;
	bool fin;
	bool invocar;
	bool ONboton;
	bool OFFboton;
	int sumac = 0;
public:
	Moneda moneda1;
	NivelFinal();
	virtual~NivelFinal();
	Heroe GetHeroe();
	/////Funciones
	void Inicializa(Heroe h);
	bool FinNivelFinal();
	void Dibuja();
	void Mueve();
	void Tecla(unsigned char);
	void TeclaUp(unsigned char);

	bool MuerteHeroe();
	void DestruirContenido();

	void LecturaFichero(string Fichero);

};