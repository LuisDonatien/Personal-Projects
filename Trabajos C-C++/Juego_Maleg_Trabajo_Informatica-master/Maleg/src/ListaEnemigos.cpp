#include <iostream>
#include "ListaEnemigos.h"
using namespace std;


ListaEnemigos::ListaEnemigos(){

	nume = 0;
	
	for (int i = 0; i < MAX_ENEM; i++) {
		Lista_e[i] = 0;
	}
}

ListaEnemigos::~ListaEnemigos() {


}

bool ListaEnemigos::AgregarE(Enemigo* e) {

	if (nume < MAX_ENEM) {
		Lista_e[nume] = e;
		nume++;
		return true;
	}
	else
		return false;
}


void ListaEnemigos::DestruirContenido() {
	for (int i = 0;i < nume;i++) {
		delete Lista_e[i];
	}
	nume = 0;

}

void ListaEnemigos::Dibuja() {

	for (int i = 0; i < nume; i++) {
			Lista_e[i]->Dibuja();
	}

}

void ListaEnemigos::Mueve(float t) {

	for (int i = 0;i < nume;i++) {
		Lista_e[i]->Mueve(t);
	}
}

bool ListaEnemigos::Colision(Heroe* p) {
	
	for (int i = 0; i < nume;i++) {
		if (Interaccion::ColisionEnemigo(p, *(Lista_e[i]))) {
			p->SetVida(p->GetVida() - 1);
			p->SetVel(0.0f, 0.0f);
			p->PuntoReaparicion();
			return true;

		}
	}
	return false;
}

Enemigo ListaEnemigos::GetListaEnem(int num) {
	return *(Lista_e[num]);
}

void ListaEnemigos::ShowHitbox(bool e) {
	for (int i = 0;i < nume;i++) {
		Lista_e[i]->ShowHitbox(e);
	}
}

int ListaEnemigos::GetNumeroE() {
	return nume;
}

void ListaEnemigos::Eliminar(Enemigo* e) {//borrar esfera según su dirección de memoria
	for (int i = 0;i < nume;i++) {
		if (Lista_e[i] == e) {
			Eliminar(i);
			return;
		}
	}
}
void ListaEnemigos::Eliminar(int index) {//borrar una esfera segun su indice
	if ((index < 0) || (index >= nume)) {//si el indice esta fuera de rango
		return;
	}
	delete Lista_e[index];
	nume--;
	for (int i = index;i < nume;i++) {
		Lista_e[i] = Lista_e[1 + i];
	}
}