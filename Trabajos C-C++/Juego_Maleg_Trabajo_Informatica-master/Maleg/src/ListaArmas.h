#pragma once
#include "Arma.h"
#include "Heroe.h"
using namespace std;
#define MAX_SIZE 100
class ListaArmas {
private:
	int numeroA;
	Arma* ListaA[MAX_SIZE];
public:
	ListaArmas();
	virtual ~ListaArmas();
	void Dibuja();
	void Mueve(float t);
	bool AgregarA(Arma* a);

	void DestruirContenido();
	void Eliminar(Arma* a);
	void Eliminar(int index);

	Arma  GetLista(int num);
	int GetNum();
};