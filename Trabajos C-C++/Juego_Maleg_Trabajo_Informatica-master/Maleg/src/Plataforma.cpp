#include "Plataforma.h"
#include "ETSIDI.h"
#include "glut.h"

Plataforma::Plataforma() {

}

Plataforma::Plataforma(float x1, float y1, float x2, float y2, float gr, unsigned char r, unsigned char v, unsigned char a) {
    limite1.x = x1;
    limite1.y = y1;
    limite2.x = x2;
    limite2.y = y2;
    grosor = gr;
    rojo = r;
    verde = v;
    azul = a;
}

Plataforma::~Plataforma() {

}

void Plataforma::SetPos(float x1, float y1 ,float x2,float y2,float gr) {
	limite1.x = x1;
	limite1.y = y1; 
	limite2.x = x2;
	limite2.y = y2;
    grosor = gr;
}

void Plataforma::SetColor(unsigned char r, unsigned char v, unsigned char a) {
    rojo = r;
    verde = v;
    azul = a;
}

Vector2D Plataforma::Getlimite1() {
    return limite1;
}

Vector2D Plataforma::Getlimite2() {
    return limite2;
}

float Plataforma::GetGrosor() {
    return grosor;
}

void Plataforma::Dibuja() {

    //PLATAFORMAS FLOTANTES
        if (grosor == 0.6f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/10pixels_tie.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 0.5f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/3pixels_tie.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 1.9f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/block.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 2.0f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/10pixels_bot.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 2.1f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/20pixels_bot.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 2.2f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/boss_pixels_bot.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
        else if (grosor == 3.0f) {
            glEnable(GL_LIGHTING);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/block.png").id);
            glDisable(GL_LIGHTING);
            glBegin(GL_POLYGON);

            glColor3f(1, 1, 1);
            glTexCoord2d(0, 1);		glVertex3f(limite1.x, limite1.y - grosor, 0.5);
            glTexCoord2d(1, 1);		glVertex3f(limite2.x, limite2.y - grosor, 0.5);
            glTexCoord2d(1, 0);		glVertex3f(limite2.x, limite2.y, 0.5);
            glTexCoord2d(0, 0);		glVertex3f(limite1.x, limite1.y, 0.5);
            glEnd();

            glEnable(GL_LIGHTING);
            glDisable(GL_TEXTURE_2D);
        }
 
}

void Plataforma::Mueve(float t) {

}

void Plataforma::Reaccion(Heroe* pers) {
    pers->SetVel(pers->GetVel().x, 0.0f);
    pers->SetAce(pers->GetAce().x, 0.0f);
}
