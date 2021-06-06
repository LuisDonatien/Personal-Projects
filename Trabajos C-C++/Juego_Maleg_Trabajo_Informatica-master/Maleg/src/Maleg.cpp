#include "Mundo.h"
#include "glut.h"
#include "Coordinador.h"

Coordinador juego;

void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y);
void OnKeyboardUp(unsigned char key, int x, int y);


int main(int argc, char* argv[]) {
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-20, 20,-20,20, 3, -10);						// Esto es lo que le da la perspectiva2D glOrtho(x_min, x_max, y_min, y_max, z_min, z_max);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutKeyboardUpFunc(OnKeyboardUp);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void) {
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	juego.Dibuja();
	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) {
	
	juego.Tecla(key);
	glutPostRedisplay();
}

void OnKeyboardUp(unsigned char key, int x, int y) {
	juego.TeclaUp(key);
}

void OnTimer(int value) {
	//poner aqui el código de animacion
	juego.Mueve();
	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void onSpecialKeyboardDown(int key, int x, int y)
{
	juego.TeclaEspecial(key);
}
