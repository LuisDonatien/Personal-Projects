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
using namespace std;

class Nivel1 {
private:
	Heroe heroe;
	ListaPlataformas plataformas;        ///Objeto contiene todas las plataformas Nivel1
	ListaMonedas monedas;				 ///Objeto contiene todas las monedas Nivel1
	ListaEnemigos enemigos;				 ///Objeto contiene todos los enemigos Nivel1
	ListaArmas armas;					 ///Objeto contiene todas las lanzas
	ListaCorazones corazones;			 ///Objeto contiene todos los corazones Nivel1
	Puerta puerta;					
	
	enum Estado { ShowHitbox,HideHitbox};
	Estado estado = HideHitbox;
	string Fichero = "Nivel1.txt";		 ///Nombre fichero lectura Nivel1
	bool fin;
public:
	Nivel1();
	void Inicializa(Heroe h);

	virtual~Nivel1();
	void DestruirContenido();
	bool FinNivel1();
	
	void Dibuja();
	void Mueve();
	
	void Tecla(unsigned char);
	void TeclaUp(unsigned char);

	Heroe GetHeroe();
	bool MuerteHeroe();

	void LecturaFichero(string Fichero);

};
