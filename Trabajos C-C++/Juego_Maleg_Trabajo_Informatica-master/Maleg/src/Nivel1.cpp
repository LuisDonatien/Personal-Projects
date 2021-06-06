#include "Nivel1.h"
#include <iostream>
#include <fstream>
#include "glut.h"
using namespace std;

Nivel1::Nivel1() {
	fin = false;
}

Nivel1::~Nivel1() {

}

void Nivel1::DestruirContenido() {
	monedas.destruirContenido();
	enemigos.DestruirContenido();
	plataformas.DestruirContenido();
	puerta.DestruirContenido();
	corazones.DestruirContenido();
	armas.DestruirContenido();
}

Heroe Nivel1::GetHeroe() {
	heroe.DestruirContenido();
	return heroe;
}

void Nivel1::Inicializa(Heroe h) {
	/////////////////////////////////////Personaje
	heroe = h;
	heroe.SetAlturaMuerte(-15.0f);
	heroe.SetPos(0.0f, 0.0f);//180.0f, 7.5f
	heroe.SetVel(0.0f, 0.0f);

	//puerta.SetPos(174.0f,8.0f,175.0f,8.0f,-8.0f);
	//puerta.SetColor(255, 0, 0);
	Puerta* puer = new Puerta(181.0f, 7.5f, 185.0f, 7.5f, -5.0f, 255, 0, 0);
	puerta.AgregarP(puer);
	////////////////////////////////////Inicializa Plataformas, Monedas , Enemigos, Vidas
	LecturaFichero(Fichero);
}

void Nivel1::Dibuja() {
	// Vista
	gluLookAt(heroe.GetPos().x,heroe.GetPos().y+ 1, 3,  // posicion del ojo						//EL centro de la camara sigue la posicion del heroe
		heroe.GetPos().x, heroe.GetPos().y + 1, 0.0,      // hacia que punto mira  (0,0,0)		//la posicion x e y del ojo deben ser iguales al punto x e y al que mira el ojo
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	// Background
	glEnable(GL_TEXTURE_2D);
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/lvl1background.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 0, 0.6);
	glTexCoord2d(1, 1); glVertex3f(40, 0, 0.6); 
	glTexCoord2d(1, 0); glVertex3f(40, 40, 0.6);
	glTexCoord2d(0, 0); glVertex3f(-40, 40, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(40, 0, 0.6);
	glTexCoord2d(1, 1); glVertex3f(120, 0, 0.6);
	glTexCoord2d(1, 0); glVertex3f(120, 40, 0.6);
	glTexCoord2d(0, 0); glVertex3f(40, 40, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(120, 0, 0.6);
	glTexCoord2d(1, 1); glVertex3f(200, 0, 0.6);
	glTexCoord2d(1, 0); glVertex3f(200, 40, 0.6);
	glTexCoord2d(0, 0); glVertex3f(120, 40, 0.6);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/bottom.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-40, 0, 0.7);
	glTexCoord2d(1, 1); glVertex3f(220, 0, 0.7);
	glTexCoord2d(1, 0); glVertex3f(220, -60, 0.7);
	glTexCoord2d(0, 0); glVertex3f(-40, -60, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/top.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1); 
	glTexCoord2d(0, 1); glVertex3f(-40, 40, 0.7);
	glTexCoord2d(1, 1); glVertex3f(220, 40, 0.7);
	glTexCoord2d(1, 0); glVertex3f(220, 100, 0.7);
	glTexCoord2d(0, 0); glVertex3f(-40, 100, 0.7);
	glEnd();
	//------------------------------------------------------------------------------------------
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	// Enemigos
	enemigos.Dibuja();

	// Heroe
	heroe.Dibuja();

    //Plataformas, Monedas y otros.
	plataformas.Dibuja();
	monedas.Dibuja();
	armas.Dibuja();
	
	corazones.Dibuja();
	puerta.DibujaP();

}

void Nivel1::Mueve() {
	// Mueve
	enemigos.Mueve(0.025f);	
	monedas.Mueve(0.025f);
	armas.Mueve(0.05f);
	plataformas.Mueve(0.025f);
	corazones.Mueve(0.025f);
	
	// Heroe Mueve
	heroe.Mueve(0.1f);

	// Colisiones Plataforma, Monedas y otros.
	plataformas.Colision(&heroe);
	monedas.Colision(&heroe);
	enemigos.Colision(&heroe);
	corazones.Colision(&heroe);

	if (puerta.Colision(&heroe) == true) {
		fin = true;
	}
	else
		fin = false;

	for (int i = 0;i < enemigos.GetNumeroE();i++) {
		for (int j = 0;j < armas.GetNum();j++) {
			if (Interaccion::ColisionEnemigo(armas.GetLista(j), enemigos.GetListaEnem(i))) {
				armas.Eliminar(j);
				enemigos.Eliminar(i);
			}
		}
	}
}

bool Nivel1::FinNivel1() {
	if (fin == true) {
		return true;
	}
	else
		return false;
}

void Nivel1::Tecla(unsigned char key) {
	////////Teclas control avance lateral y salto heroe
	if (key == 'w') {
		for (int i = 0; i < plataformas.GetNumPlat(); i++) {
			if (Interaccion::ColisionSup(&heroe, plataformas.GetListaPlat(i))) {
				heroe.SetVel(heroe.GetVel().x, 10.0f);
			}
			else {
				heroe.SetVel(heroe.GetVel().x, heroe.GetVel().y);
			}
		}
	}
	if (key == 'a') {
		heroe.SetVel(-3.0f, heroe.GetVel().y);
		heroe.SetSentido(false);
	}
	if (key == 'd') {
		heroe.SetVel(3.0f, heroe.GetVel().y);
		heroe.SetSentido(true);
	}
	////////Hitbox
	if (key == '1' && estado == ShowHitbox) {
		estado = HideHitbox;
	}
	else if (key == '1' && estado == HideHitbox) {
		estado = ShowHitbox;
	}
	if (estado == ShowHitbox) {
		heroe.ShowHitbox(true);
		enemigos.ShowHitbox(true);
	}
	else {
		heroe.ShowHitbox(false);
		enemigos.ShowHitbox(false);
	}
	////////////Disparo lanza heroe
	if (key == ' ') {
		if (heroe.ValidarDisparo()) {
			ETSIDI::play("sonidos/DisparoFlecha.mp3");
			if (heroe.Disparo()) {
				Lanza* aux = new Lanza(heroe.GetPos().x+heroe.GetAltura(), heroe.GetPos().y, 10);
				armas.AgregarA(aux);
				heroe.SumarMonedas(false);
			}
			else if (!heroe.Disparo()) {
				Lanza* aux = new Lanza(heroe.GetPos().x - heroe.GetAltura(), heroe.GetPos().y, -10);
				armas.AgregarA(aux);
				heroe.SumarMonedas(false);
			}
		}
	}
}

void Nivel1::TeclaUp(unsigned char key) {
	if (key == 'a')
		heroe.SetVel(0.0f, heroe.GetVel().y);
	if (key == 'd')
		heroe.SetVel(0.0f, heroe.GetVel().y);
}

bool Nivel1::MuerteHeroe() {
	if (heroe.Muerte()) {
		heroe.DestruirContenido();
		return true;
	}else
		return false;
}

void Nivel1::LecturaFichero(string Fichero) {
	float x1 = 0, x2 = 0, y1 = 0, y2 = 0, gr = 0,pf=0;
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
			Plataforma* aux = new Plataforma(x1, y1, x2, y2, gr, (unsigned char)r, (unsigned char)v, (unsigned char)a);///////Creacion Plataformas
			plataformas.AgregarP(aux);
		}
		if (opcion == 2) {
			archivo >> x1 >> y1 >> x2 >> y2 >> gr >> p >> vx >> vy >> r >> v >> a >> comentario;
			PlataformaMovil* aux = new PlataformaMovil(x1, y1, x2, y2, gr, p, vx, vy, (unsigned char)r, (unsigned char)v, (unsigned char)a);	///////Creacion Plataforma Movil
			plataformas.AgregarP(aux);
		}
		if (opcion == 3) {
			archivo >> x1 >> y1 >> gr >> r >> v >> a >> comentario;
			Moneda* aux = new Moneda(x1, y1, gr, r, v, a);///////Creacion Monedas
			monedas.AgregarM(aux);
		}
		if (opcion == 4) {
			archivo >> x1 >> y1 >> comentario;
			Sirena* aux = new Sirena(x1, y1);//////////Creacion Sirenas
			enemigos.AgregarE(aux);
		}
		if (opcion == 5) {
			archivo >> x1 >> y1 >> comentario;
			Pajaro* aux = new Pajaro(x1, y1);//////////Creacion Pajaro
			enemigos.AgregarE(aux);
		}
		if (opcion == 6) {
			archivo >> x1 >> y1 >> comentario;
			Vector2D* aux = new Vector2D(x1, y1);//////////Creacion Setpoints Heroe
			heroe.AgregarPuntosR(aux);
		}
		if (opcion == 7) {
			archivo >> x1 >> y1 >> pf >> r >> vy  >> comentario;
			VidaExtra* aux = new VidaExtra(x1, y1, pf, r, vy);///////Creacion VidaExtra
			corazones.AgregarC(aux);
		}
		archivo >> tipo;
		if (tipo == "Plataforma")
			opcion = 1;
		if (tipo == "Plataforma_movil")
			opcion = 2;
		if (tipo == "Monedas")
			opcion = 3;
		if (tipo == "Enemigos" || tipo=="Heroe")
			opcion = 300;
		if (tipo == "Sirena")
			opcion = 4;
		if (tipo == "Pajaro")
			opcion = 5;
		if (tipo == "PuntosReaparicion")
			opcion = 6;
		if (tipo == "VidasExtra")
			opcion = 7;
		if (tipo != "Plataforma" && tipo != "Plataforma_movil" && !archivo.eof() && tipo != introduccion && tipo != "Monedas" &&
			tipo!="Enemigos" &&tipo !="Sirena" && tipo !="Pajaro" && tipo!="PuntosReaparicion" && tipo!="Heroe" && tipo != "VidasExtra") {//Como leo todas las lineas con un string tipo , tengo que retornar el carro al inicio 
			longitud = tipo.size();									// de esa linea si no leo  plataforma u otro objeto, ya que estoy leyendo datos.
			pos = archivo.tellg();									//hay que indicar tambien que no retorne carro en la ultima linea de coordenadas con !eof sino se 
			pos = pos - longitud;									//se genera un bucle infinito de retorno de carro
			archivo.seekg(pos);
		}
	}
	archivo.close();
}


