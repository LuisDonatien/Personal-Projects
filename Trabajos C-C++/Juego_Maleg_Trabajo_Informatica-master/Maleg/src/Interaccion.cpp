#include <iostream>
#include "Interaccion.h"
using namespace std;
Interaccion::Interaccion() {

}

Interaccion::~Interaccion() {

}

bool Interaccion::ColisionSup(Heroe* pers, Plataforma pl) {
    Vector2D posicion = pers->GetPos();
    float altura = (pers->GetAltura()) / 2;
    float diferencia = posicion.y - pl.Getlimite1().y;
    if ((diferencia>=altura-1.5f) && (diferencia <=altura) && (pl.Getlimite1().x < posicion.x + altura) && (posicion.x - altura < pl.Getlimite2().x)) {
        pers->SetPos(pers->GetPos().x,pl.Getlimite1().y+altura);
        return true;
    }
    else
        return false;
}

bool Interaccion::ColisionLat(Heroe* pers, Plataforma pl) {
    Vector2D posicion = pers->GetPos();
    float altura = pers->GetAltura() / 2;
     float diferencia1 = pl.Getlimite1().x - posicion.x;
     float diferencia2 = posicion.x - pl.Getlimite2().x;
        if ((pers->GetVel().x>=0)&&(diferencia1 <= altura)&& (diferencia1>altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) &&(pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura)&&(pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y-pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite1().x - altura, pers->GetPos().y);
            return true;
        }
        if ((pers->GetVel().x <= 0)&&(diferencia2 <= altura) && (diferencia2 >altura-0.5f) && (((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y + altura) && (pers->GetPos().y + altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y - pl.GetGrosor() < pers->GetPos().y - altura) && (pers->GetPos().y - altura < pl.Getlimite1().y)) || ((pl.Getlimite1().y < pers->GetPos().y + altura) && (pers->GetPos().y - altura < pl.Getlimite1().y -pl.GetGrosor())))) {
            pers->SetPos(pl.Getlimite2().x + altura, pers->GetPos().y);
            return true;
        }

        return false;
}

bool Interaccion::ColisionInf(Heroe* pers, Plataforma pl) {
   Vector2D posicion = pers->GetPos();
   float altura = pers->GetAltura() / 2;
   float diferencia = pl.Getlimite1().y-pl.GetGrosor() - posicion.y;
   if ((diferencia <= altura) && (diferencia > altura-1.0f) && (pl.Getlimite1().x < pers->GetPos().x + altura) && (pers->GetPos().x - altura < pl.Getlimite2().x)) {
       pers->SetPos(pers->GetPos().x, pl.Getlimite2().y-pl.GetGrosor()-altura);
       return true;
   }
   else
       return false;

}
bool Interaccion::ColisionMoneda(Heroe* pers, Moneda m) {
    Vector2D posicion = pers->GetPos();
    float altura = pers->GetAltura() / 2;
    Vector2D posicionm = m.GetPos();

    float distanciarxi = posicionm.x - m.GetRadio();
    float distanciarxd = posicionm.x + m.GetRadio();
    float distanciapxd = posicion.x + altura;
    float distanciapxi = posicion.x - altura;
    float distanciapysup = posicion.y + altura;
    float distanciapyinf = posicion.y - altura;
    float distanciamsup = posicionm.y + m.GetRadio();
    float distanciaminf = posicionm.y - m.GetRadio();
    if ((distanciarxi <= distanciapxd)&&(distanciarxd>=distanciapxi) && ((distanciapysup >= distanciaminf) && (distanciapyinf <= distanciamsup))) {

        return true;
    }
 

    return false;
}
 bool Interaccion::ColisionEnemigo(Heroe* pers, Enemigo e) {
     Vector2D posicion = pers->GetPos();
     float altura = pers->GetAltura() / 2;
     Vector2D posicione = e.GetPos();
     float distanciaexi = posicione.x - e.GetRadio();
     float distanciaexd = posicione.x + e.GetRadio();
     float distanciapxd = posicion.x + altura;
     float distanciapxi = posicion.x - altura;
     float distanciapysup = posicion.y + altura;
     float distanciapyinf = posicion.y - altura;
     float distanciaesup = posicione.y + e.GetRadio();
     float distanciaeinf = posicione.y - e.GetRadio();
     if ((distanciaexi <= distanciapxd) && (distanciaexd >= distanciapxi) && ((distanciapysup >= distanciaeinf) && (distanciapyinf <= distanciaesup))) {
         return true;
     }
     return false;

}

 bool Interaccion::ColisionEnemigo(Arma a, Enemigo e) {
     Vector2D posicion = a.GetPos();
     float altura = a.GetLado() / 2;
     Vector2D posicione = e.GetPos();
     float distanciaexi = posicione.x - e.GetRadio();
     float distanciaexd = posicione.x + e.GetRadio();
     float distanciapxd = posicion.x + altura;
     float distanciapxi = posicion.x - altura;
     float distanciapysup = posicion.y + altura;
     float distanciapyinf = posicion.y - altura;
     float distanciaesup = posicione.y + e.GetRadio();
     float distanciaeinf = posicione.y - e.GetRadio();
     if ((distanciaexi <= distanciapxd) && (distanciaexd >= distanciapxi) && ((distanciapysup >= distanciaeinf) && (distanciapyinf <= distanciaesup))) {
         return true;
     }
     return false;
 }
 bool Interaccion::ColisionVida(Heroe* pers, VidaExtra v) {
     Vector2D posicion = pers->GetPos();
     float altura = pers->GetAltura() / 2;
     Vector2D posicionm = v.GetPos();

     float distanciarxi = posicionm.x - v.GetRadio();
     float distanciarxd = posicionm.x + v.GetRadio();
     float distanciapxd = posicion.x + altura;
     float distanciapxi = posicion.x - altura;
     float distanciapysup = posicion.y + altura;
     float distanciapyinf = posicion.y - altura;
     float distanciamsup = posicionm.y + v.GetRadio();
     float distanciaminf = posicionm.y - v.GetRadio();
     if ((distanciarxi <= distanciapxd) && (distanciarxd >= distanciapxi) && ((distanciapysup >= distanciaminf) && (distanciapyinf <= distanciamsup))) {

         return true;
     }


     return false;
 }
 bool Interaccion::ColisionBoton(Heroe* pers, Boton b) {
     Vector2D posicion = pers->GetPos();
     float altura = pers->GetAltura() / 2;
     Vector2D posicionm = b.GetPos();

     float distanciarxi = posicionm.x - b.GetRadio();
     float distanciarxd = posicionm.x + b.GetRadio();
     float distanciapxd = posicion.x + altura;
     float distanciapxi = posicion.x - altura;
     float distanciapysup = posicion.y + altura;
     float distanciapyinf = posicion.y - altura;
     float distanciamsup = posicionm.y + b.GetRadio();
     float distanciaminf = posicionm.y - b.GetRadio();
     if ((distanciarxi <= distanciapxd) && (distanciarxd >= distanciapxi) && ((distanciapysup >= distanciaminf) && (distanciapyinf <= distanciamsup))) {
         return true;
     }
     return false;
 }

     