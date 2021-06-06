#pragma once
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include "ListaPlataformas.h"
#include "ListaMonedas.h"
#include "ListaEnemigos.h"
#include "ListaArmas.h"
#include "ListaCorazones.h"
#include "Puerta.h"
#include <string>
#include "Heroe.h"
#include "Sirena.h"
#include "Lanza.h"
#include "Puerta.h"
#include "Interaccion.h"
#include <string>
using namespace std;

class Nivel2 {
private:
	Heroe heroe2;
	ListaPlataformas plataformas2;        ///Objeto contiene todas las plataformas Nivel2
	ListaMonedas monedas2;				  ///Objeto contiene todas las monedas Nivel2
	ListaEnemigos enemigos2;			  ///Objeto contiene todos los enemigos Nivel2
	ListaArmas  armas2;					  ///Objeto contiene todas las lanzas
	ListaCorazones corazones2;			  ///Objeto contiene todos los corazones Nivel2
	Puerta puerta2;						  

	enum Estado { ShowHitbox, HideHitbox };
	Estado estado = HideHitbox;
	string Fichero = "Nivel2.txt";		  ///Nombre fichero lectura Nivel1
	bool fin;
public:
	Nivel2();
	void Inicializa(Heroe h);

	virtual ~Nivel2();
	void DestruirContenido();
	bool FinNivel2();
	
	void Mueve();
	void Dibuja();
	
	Heroe GetHeroe();
	bool MuerteHeroe();

	void Tecla(unsigned char);
	void TeclaUp(unsigned char key);

	void LecturaFichero(string Fichero);
};