#pragma once
#include "Heroe.h"
#include "Enemigo.h"
#include "Plataforma.h"
#include "Moneda.h"
#include "Arma.h"
#include "VidaExtra.h"
#include "Boton.h"
#include "Boss.h"

class Interaccion
{
private:

public:
	Interaccion();
	virtual ~Interaccion();
	static bool ColisionVida(Heroe* pers, VidaExtra v);
	static bool ColisionSup(Heroe* pers, Plataforma pl);
	static bool ColisionLat(Heroe* pers, Plataforma pl);
	static bool ColisionInf(Heroe* pers, Plataforma pl);
	static bool ColisionMoneda(Heroe* pers, Moneda m);
	static bool ColisionEnemigo(Heroe* pers, Enemigo e);
	static bool ColisionEnemigo(Arma a, Enemigo e);
	static bool ColisionBoton(Heroe* pers, Boton b);
};

