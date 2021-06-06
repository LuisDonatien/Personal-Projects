#include "ListaCorazones.h"
#include <iostream>
using namespace std;
ListaCorazones::ListaCorazones() {
	num = 0;//numero inicial de vidas extra
	for (int i = 0;i < MAX_COR;i++) {
		Lista_c[i] = 0; //todo el puntero esta a NULL
	}
}
ListaCorazones::~ListaCorazones() {

}
bool ListaCorazones::AgregarC(VidaExtra* v) {
	if (num < MAX_COR) {
		Lista_c[num] = v;
		num++;
	}
	else return false;

}

void ListaCorazones::DestruirContenido() {
	for (int i = 0;i < num;i++) {
		delete Lista_c[i];
	}
	num = 0;
}

void ListaCorazones::Dibuja() {
	for (int i = 0;i < num;i++) {
		Lista_c[i]->Dibuja(); //recorre una a una la lista  que tenemos y las dibuja
	}                      
}
void ListaCorazones::Mueve(float t) {
	for (int i = 0;i < num;i++) {
		Lista_c[i]->Mueve(t);
	}
}
bool ListaCorazones::Colision(Heroe* h) {
	for (int i = 0; i < num;i++) {
		
		if (Interaccion::ColisionVida(h, *(Lista_c[i]))) {
			if(h->GetVida()<3)
				h->SetVida(h->GetVida() + 1);
			Eliminar(Lista_c[i]);
			ETSIDI::play("sonidos/vida.wav");
			return true;
		}
		
	}
	
	return false;
}

void ListaCorazones::Eliminar(VidaExtra* v) {
	for (int i = 0;i < num;i++) {
		if (Lista_c[i] == v) {
			Eliminar(i);
			return;
		}
	}
}
void ListaCorazones::Eliminar(int index) {
	if ((index < 0) || (index >= num)) {//si el indice esta fuera de rango
		return;
	}
	delete Lista_c[index];
	num--;
	for (int i = index;i < num;i++) {
		Lista_c[i] = Lista_c[1 + i];
	}
	
}

