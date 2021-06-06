#include "Puerta.h"
#include <iostream>
#include "glut.h"

using namespace std;
Puerta::Puerta(){
    rojo = 255;
    azul = 0;
    verde = 0;
    num = 0;
}
Puerta::~Puerta() {

}
bool Puerta::AgregarP(Puerta* p) {
    if (num < MAX_PUER) {
        lista[num] = p;
        num++;
    }
    else return false;


}
void Puerta::DestruirContenido() {
    for (int i = 0;i < numPuertas();i++) {

        delete lista[i];
    }
}
Puerta::Puerta(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a){
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
    grosor = gr;
    rojo = r;
    verde = v;
    azul = a;
}

void Puerta::Dibuja() {

    glEnable(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/door.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glTexCoord2d(0, 1); glVertex3d(limite1.x, limite1.y, 0.5);
    glTexCoord2d(1, 1); glVertex3d(limite2.x, limite2.y, 0.5);
    glTexCoord2d(1, 0); glVertex3d(limite2.x, limite2.y - grosor, 0.5);
    glTexCoord2d(0, 0); glVertex3d(limite1.x, limite1.y - grosor, 0.5);
    glEnd();

    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
}
void Puerta::DibujaP() {
    for (int i = 0;i < num;i++) {
        lista[i]->Dibuja();//direccion de memoria del elemento(puerta)
    }                       //recorre una a una la lista de monedas que tenemos y las dibuja
}
bool Puerta::Colision(Heroe* p) {//Devuelve el true cada vez que el hombre "Atraviesa" una puerta
    for (int i = 0; i < num;i++) {
        if (Interaccion::ColisionLat(p, *(lista[i]))){
            return true;
        }

    }
    for (int i = 0;i < num;i++) {
        if (Interaccion::ColisionInf(p, *(lista[i]))) {
            return true;
        }
    }

    for (int i = 0;i < num; i++) {
        if (Interaccion::ColisionSup(p, *(lista[i]))) {
            return true;
        }
        
    }
    return false;

    
}
