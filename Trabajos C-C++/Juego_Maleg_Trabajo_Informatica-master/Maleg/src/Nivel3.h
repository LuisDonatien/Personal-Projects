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

class Nivel3 {
private:
	Heroe heroe3;
	ListaPlataformas plataformas3;        ///Objeto contiene todas las plataformas Nivel3
	ListaMonedas monedas3;				  ///Objeto contiene todas las monedas Nivel3
	ListaEnemigos enemigos3;			  ///Objeto contiene todos los enemigos Nivel3
	ListaArmas armas3;				      ///Objeto contiene todas las lanzas
	ListaCorazones corazones3;			  ///Objeto contiene todos los corazones Nivel3
	Puerta puerta3;
	Puerta puertaextra;

	enum Estado { ShowHitbox, HideHitbox };
	Estado estado = HideHitbox;
	string Fichero = "Nivel3.txt";		 ///Nombre fichero lectura Nivel1
	bool fin;
public:
	Nivel3();
	void Inicializa(Heroe h);

	virtual~Nivel3();
	void DestruirContenido();
	bool FinNivel3();

	void Dibuja();
	void Mueve();

	void Tecla(unsigned char);
	void TeclaUp(unsigned char);

	Heroe GetHeroe();
	bool MuerteHeroe();

	void LecturaFichero(string Fichero);
};
