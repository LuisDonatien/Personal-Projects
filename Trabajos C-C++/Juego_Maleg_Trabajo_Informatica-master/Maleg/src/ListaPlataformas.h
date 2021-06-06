#pragma once
#include "Plataforma.h"
#include "PlataformaMovil.h"
#include <string>
#include "Heroe.h"

using namespace std;
#define MAX_SIZE 100

class ListaPlataformas {
private:
	int numerop;
	Plataforma* Listap[MAX_SIZE];
public:
	ListaPlataformas();
	virtual ~ListaPlataformas();
	void Dibuja();
	void Mueve(float t);
	bool AgregarP(Plataforma* p);
	void DestruirContenido();

	Plataforma GetListaPlat(int num);
	int GetNumPlat();

	void Colision(Heroe* p);
};
