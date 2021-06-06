#include "Mundo.h"
#include "Personaje.h"
#include "ETSIDI.h"
#include <iostream>
#include "glut.h"
using namespace std;

Mundo::Mundo()
{
	fin = false;
}


Mundo::~Mundo() 
{
	
}

void Mundo::Inicializa() {
	heroe.SetVida(3);
	nivel = 1;
	CargarNivel();
}

void Mundo::CargarNivel() {
	
	if (nivel == 1) {
		nivel1 = new Nivel1();
		nivel1->Inicializa(heroe);		
		cout << "Inicializamundonivel1" << endl;
	}
	else if (nivel == 2) {
		nivel2 = new Nivel2();
		nivel2->Inicializa(heroe);
		cout << "Inicializamundonivel2" << endl;
	}
	else if (nivel == 3) {
		nivel3 = new Nivel3();
		nivel3->Inicializa(heroe);
		cout << "Inicializamundonivel3" << endl;
	}
	else if (nivel == 4) {
		nivelfinal = new NivelFinal();
		nivelfinal->Inicializa(heroe);
		cout << "InicializamundonivelFinal" << endl;
	}
}

void Mundo::Dibuja() {
	////////////////////////////////Dibujar aqui
	if (nivel == 1){
		nivel1->Dibuja();
	}
	else if (nivel == 2) {
		nivel2->Dibuja();
	}
	else if (nivel == 3) {
		nivel3->Dibuja();
	}
	else if (nivel == 4) {
		nivelfinal->Dibuja();
	}
}

void Mundo::TeclaEspecial(unsigned char key){

}

void Mundo::Mover(){
	if (nivel == 1) {
		if (nivel1->FinNivel1() == true) {
			nivel = nivel + 1;		
			heroe = nivel1->GetHeroe();
			nivel1->DestruirContenido();
			delete nivel1;
			cout << "Deletenivel1" << endl;
			CargarNivel();
		}
		else {
			nivel1->Mueve();
		}
	}

	if (nivel == 2) {
		if (nivel2->FinNivel2() == true) {
			nivel = nivel + 1;
			heroe = nivel2->GetHeroe();
			nivel2->DestruirContenido();
			delete nivel2;
			cout << "Deletenivel2" << endl;
			CargarNivel();
		}
		else {
			nivel2->Mueve();
		}
	}
	if (nivel == 3) {
		if (nivel3->FinNivel3() == true) {
			nivel = nivel + 1;
			heroe = nivel3->GetHeroe();
			nivel3->DestruirContenido();
			delete nivel3;
			cout << "Deletenivel3" << endl;
			CargarNivel();
		}
		else {
			nivel3->Mueve();
		}
	}
	if(nivel == 4)
		if (nivelfinal->FinNivelFinal() == true) {
			heroe = nivelfinal->GetHeroe();
			nivelfinal->DestruirContenido();
			delete nivelfinal;
			cout << "DeletenivelFinal" << endl;
			fin = true;
		}
		else 
		{
			nivelfinal->Mueve();
		}

	
}

bool Mundo::GetFin(){
	return fin;
}

void Mundo::SetFin(bool f) {
	fin = f;
}

void Mundo::Tecla(unsigned char key)
{	
	
	if(nivel==1)
		nivel1->Tecla(key);
	
	if(nivel==2)
		nivel2->Tecla(key);

	if (nivel == 3)
		nivel3->Tecla(key);

	if (nivel == 4)
	
		nivelfinal->Tecla(key);
		
}

void Mundo::TeclaUp(unsigned char key) {
	if(nivel==1)
		nivel1->TeclaUp(key);
	
	if(nivel==2)
		nivel2->TeclaUp(key);

	if (nivel == 3)
		nivel3->TeclaUp(key);

	if (nivel == 4)
		nivelfinal->TeclaUp(key);
}

bool Mundo::Muerte() {
	if (nivel == 1) {
		if (nivel1->MuerteHeroe()) {
			nivel1->DestruirContenido();
			delete nivel1;
			heroe.SetMonedas(0);
			return true;
		}else if(!nivel1->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 2) {
		if (nivel2->MuerteHeroe()) {
			nivel2->DestruirContenido();
			delete nivel2;
			heroe.SetMonedas(0);
			return true;
		}
		else if (!nivel2->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 3) {
		if (nivel3->MuerteHeroe()) {
			nivel3->DestruirContenido();
			delete nivel3;
			heroe.SetMonedas(0);
			return true;
		}
		else if (!nivel3->MuerteHeroe()) {
			return false;
		}
	}
	else if (nivel == 4) {
		if (nivelfinal->MuerteHeroe()) {
			nivelfinal->DestruirContenido();
			delete nivelfinal;
			heroe.SetMonedas(0);
			return true;
		}
		else if (!nivelfinal->MuerteHeroe()) {
			return false;
		}
	}
	
}

