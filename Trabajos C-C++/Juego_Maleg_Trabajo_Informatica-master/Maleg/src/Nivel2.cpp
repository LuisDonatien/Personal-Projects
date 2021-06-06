#include "Nivel2.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel2::Nivel2() {
	fin = false;
	ETSIDI::stopMusica();
	ETSIDI::playMusica("sonidos/Ambiente.wav");
}

Nivel2::~Nivel2() {

}

void Nivel2::DestruirContenido() {
	plataformas2.DestruirContenido();
	armas2.DestruirContenido();
	monedas2.destruirContenido();
	corazones2.DestruirContenido();
	puerta2.DestruirContenido();
}
void Nivel2::Inicializa(Heroe h) {
	/////////////////////////////////////Personaje
	heroe2 = h;
	heroe2.SetAlturaMuerte(-15.0);
	heroe2.SetPos(0.0f, 0.0f);
	heroe2.SetVel(0.0f, 0.0f);
	Puerta* puer = new Puerta(204.0f, 29.0f, 208.0f, 29.0f, -5.0f, 255, 0, 0);
	puerta2.AgregarP(puer);
	
	LecturaFichero(Fichero);
}

void Nivel2::Dibuja() {
	gluLookAt(heroe2.GetPos().x, heroe2.GetPos().y + 1, 3,  // posicion del ojo			//Posicion camara sigue posicioon del personaje
		heroe2.GetPos().x, heroe2.GetPos().y + 1, 0.0,									//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);
	
	// Background
	glEnable(GL_TEXTURE_2D);
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/lvl2&3background.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 10, 0.7);
	glTexCoord2d(1, 1); glVertex3f(40, 10, 0.7);
	glTexCoord2d(1, 0); glVertex3f(40, 50, 0.7);
	glTexCoord2d(0, 0); glVertex3f(-40, 50, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(40, 10, 0.7);
	glTexCoord2d(1, 1); glVertex3f(120, 10, 0.7);
	glTexCoord2d(1, 0); glVertex3f(120, 50, 0.7);
	glTexCoord2d(0, 0); glVertex3f(40, 50, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(120, 10, 0.7);
	glTexCoord2d(1, 1); glVertex3f(200, 10, 0.7);
	glTexCoord2d(1, 0); glVertex3f(200, 50, 0.7);
	glTexCoord2d(0, 0); glVertex3f(120, 50, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(200, 10, 0.7);
	glTexCoord2d(1, 1); glVertex3f(280, 10, 0.7);
	glTexCoord2d(1, 0); glVertex3f(280, 50, 0.7);
	glTexCoord2d(0, 0); glVertex3f(200, 50, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bottom2.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 12, 0.6);
	glTexCoord2d(1, 1); glVertex3f(260, 12, 0.6);
	glTexCoord2d(1, 0); glVertex3f(260, -40, 0.6);
	glTexCoord2d(0, 0); glVertex3f(-40, -40, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	heroe2.Dibuja();
	plataformas2.Dibuja();
	monedas2.Dibuja();
	armas2.Dibuja();
	corazones2.Dibuja();
	puerta2.DibujaP();
	enemigos2.Dibuja();
}

void Nivel2::Mueve() {
	///////Mueve
	monedas2.Mueve(0.025f);
	enemigos2.Mueve(0.025f);
	plataformas2.Mueve(0.025f);
	armas2.Mueve(0.05f);
	corazones2.Mueve(0.025f);

	////////Heroe Mueve
	heroe2.Mueve(0.1f);

	//////Colisiones
	plataformas2.Colision(&heroe2);
	monedas2.Colision(&heroe2);	
	enemigos2.Colision(&heroe2);
	corazones2.Colision(&heroe2);

	if (puerta2.Colision(&heroe2) == true) {
		fin = true;
	}
	else
		fin = false;

	for (int i = 0;i < enemigos2.GetNumeroE();i++) {
		for (int j = 0;j < armas2.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas2.GetLista(j), enemigos2.GetListaEnem(i))) {
				armas2.Eliminar(j);
				enemigos2.Eliminar(i);
			}
		}
	}
}

Heroe Nivel2::GetHeroe() {
	heroe2.DestruirContenido();
	return heroe2;
}

bool Nivel2::FinNivel2() {
	if (fin == true) {
		return true;
	}
	else
		return false;
}

void Nivel2::Tecla(unsigned char key) {
	///////Teclas de avance y salto heroe
	if (key == 'w') {
		for (int i = 0; i < plataformas2.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe2, plataformas2.GetListaPlat(i))) {
				heroe2.SetVel(heroe2.GetVel().x, 10.0f);
			}
			else {
				heroe2.SetVel(heroe2.GetVel().x, heroe2.GetVel().y);
			}
		}
	}
	if (key == 'a') {
		heroe2.SetVel(-3.0f, heroe2.GetVel().y);
		heroe2.SetSentido(false);
	}
	if (key == 'd') {
		heroe2.SetVel(3.0f, heroe2.GetVel().y);
		heroe2.SetSentido(true);
	}
	////////Hitbox
	if (key == '1' && estado == ShowHitbox) {
		estado = HideHitbox;
	}
	else if (key == '1' && estado == HideHitbox) {
		estado = ShowHitbox;
	}
	if (estado == ShowHitbox) {
		heroe2.ShowHitbox(true);
		enemigos2.ShowHitbox(true);
	}
	else {
		heroe2.ShowHitbox(false);
		enemigos2.ShowHitbox(false);
	}

	if (key == ' ') {
		if (heroe2.ValidarDisparo()) {
			ETSIDI::play("sonidos/DisparoFlecha.mp3");
			if (heroe2.Disparo()) {
				Lanza* aux = new Lanza(heroe2.GetPos().x + heroe2.GetAltura(), heroe2.GetPos().y, 10);
				armas2.AgregarA(aux);
				heroe2.SumarMonedas(false);
			}
			else if (!heroe2.Disparo()) {
				Lanza* aux = new Lanza(heroe2.GetPos().x - heroe2.GetAltura(), heroe2.GetPos().y, -10);
				armas2.AgregarA(aux);
				heroe2.SumarMonedas(false);
			}
		}
	}
}
void Nivel2::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe2.SetVel(0.0f, heroe2.GetVel().y);
	if (key == 'd')
		heroe2.SetVel(0.0f, heroe2.GetVel().y);
}
bool Nivel2::MuerteHeroe() {
	if (heroe2.Muerte()) {
		heroe2.DestruirContenido();
		return true;
	}
	else
		return false;
}

void Nivel2::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0, pf=0;
	float r = 0, v = 0, a = 0, vx = 0, vy = 0;
	int b = 0, i = 1, longitud = 0, pos = 0, p, suma = 0;
	int opcion = 999;
	string tipo;
	string introduccion = { "X1_Y1_X2_Y2_GROSOR_ROJO_VERDE_AZUL" };
	string comentario;
	fstream archivo;
	archivo.open(Fichero, ios::in);	//Abriendo archivo modo lectura
	if (archivo.fail()) {
		cout << "No se pudo abrir archivo";
		exit(1);
	}
	while (!archivo.eof()) {
		if (opcion == 1) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> r >> v >> a >> comentario;
			Plataforma* aux = new Plataforma(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);///////Creacion Plataforma
			plataformas2.AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> p >> vx >> vy >> r >> v >> a >> comentario;
			PlataformaMovil* aux = new PlataformaMovil(x1, y1, x2, y2, gr, p, vx, vy, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Plataforma Movil
			plataformas2.AgregarP(aux);
		}
		if (opcion == 3) {
			archivo >> x1 >> y1 >> gr >> r >> v >> a >> comentario;
			Moneda* aux = new Moneda(x1, y1, gr, r, v, a);///////Creacion Monedas
			monedas2.AgregarM(aux);
		}
		if (opcion == 4) {
			archivo >> x1 >> y1 >> comentario;
			Sirena* aux = new Sirena(x1, y1);///////////Creacion Sirena
			enemigos2.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);/////////Creacion Pajaro
			enemigos2.AgregarE(aux);
		}
		
		if (opcion == 6) {
			archivo >> x1 >> y1 >> comentario;
			Araña* aux = new Araña(x1, y1);///////Creacion Arana
			enemigos2.AgregarE(aux);
		}
		if (opcion == 7) {
			archivo >> x1 >> y1 >> comentario;
			Murcielago* aux = new Murcielago(x1, y1);///////Creacion Murcielago
			enemigos2.AgregarE(aux);
		}
		if (opcion == 8) {
			archivo >> x1 >> y1 >>a >> vx>> comentario;
			Guerreros* aux = new Guerreros(x1, y1,a,vx);///////Creacion Guerreros
			enemigos2.AgregarE(aux);
		}
		if (opcion == 9) {
			archivo >> x1 >> y1 >> comentario;
			Vector2D* aux = new Vector2D(x1, y1);////////Creacion SetPoints Heroe
			heroe2.AgregarPuntosR(aux);
		}
		if (opcion == 10) {
			archivo >> x1 >> y1 >> pf >> r >> vy >> comentario;
			VidaExtra* aux = new VidaExtra(x1, y1, pf, r, vy);///////Creacion VidaExtra
			corazones2.AgregarC(aux);
		}
		archivo >> tipo;
		if (tipo == "Plataforma")
			opcion = 1;
		if (tipo == "Plataforma_movil")
			opcion = 2;
		if (tipo == "Monedas")
			opcion = 3;
		if (tipo == "Enemigos" || tipo == "Heroe")
			opcion = 300;
		if (tipo == "Sirena")
			opcion = 4;
		if (tipo == "Pajaro")
			opcion = 5;
		if (tipo == "Arana")
			opcion = 6;
		if (tipo == "Murcielago")
			opcion = 7;
		if (tipo == "Guerrero")
			opcion = 8;
		if (tipo == "PuntosReaparicion")
			opcion = 9;
		if (tipo == "VidasExtra")
			opcion = 10;
		if (tipo != "Plataforma" && tipo != "Plataforma_movil" && !archivo.eof() && tipo != introduccion && tipo != "Monedas" &&
			tipo != "Enemigos" && tipo != "Sirena" && tipo != "Pajaro" && tipo != "PuntosReaparicion" && tipo != "Heroe" && tipo != "VidasExtra" 
			&& tipo!="Murcielago"  && tipo !="Arana" && tipo!="Guerrero") {//Como leo todas las lineas con un tipo string, tengo que retornar el carro al inicio
			longitud = tipo.size();									// de esa linea ,si no  leo  plataforma u otro objeto, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tmb que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
	}
	archivo.close();
}