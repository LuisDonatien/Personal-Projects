#include "ListaPlataformas.h"
#include <fstream>
#include <iostream>
#include <string>
#include "Interaccion.h"
using namespace std;


ListaPlataformas::ListaPlataformas() {
	numerop = 0;
	for (int i = 0;i < MAX_SIZE;i++)
		Listap[i] = 0;
}

ListaPlataformas::~ListaPlataformas() {

}

void ListaPlataformas::DestruirContenido() {
	for (int i = 0;i < numerop;i++) {
		delete Listap[i];
	}
	numerop = 0;
}

Plataforma ListaPlataformas::GetListaPlat(int num){
	return *(Listap[num]);
}

int ListaPlataformas::GetNumPlat(){
	return numerop;
}

void ListaPlataformas::Dibuja() {
	for (int i = 0;i < numerop;i++)
		Listap[i]->Dibuja();
}

bool ListaPlataformas::AgregarP(Plataforma* p) {
	for (int i = 0;i < numerop;i++) {
		if ((Listap[i]) == p)
			return false;
	}
	if (numerop < MAX_SIZE)
		Listap[numerop++] = p;
	else
		return false;
	return true;
}

void ListaPlataformas::Colision(Heroe* pers) {
	for (int i = 0;i < numerop;i++) {
		if (Interaccion::ColisionLat(pers, *(Listap[i]))) {
			pers->SetVel(0.0f, pers->GetVel().y);
			break;
		}
	}

	for (int i = 0;i < numerop; i++) {
		if (Interaccion::ColisionSup(pers, *(Listap[i]))) {
			Listap[i]->Reaccion(pers);

			break;
		}
		else
			pers->SetAce(pers->GetAce().x, -9.8f);
	}

	for (int i = 0;i < numerop;i++) {
		if (Interaccion::ColisionInf(pers, *(Listap[i]))) {
			if (pers->GetVel().y > 0) {
				pers->SetVel(pers->GetVel().x, 0.0f);
				break;
			}
		}
	}
}
void ListaPlataformas::Mueve(float t) {
	for (int i = 0;i < numerop;i++) {
		Listap[i]->Mueve(t);
	}
}