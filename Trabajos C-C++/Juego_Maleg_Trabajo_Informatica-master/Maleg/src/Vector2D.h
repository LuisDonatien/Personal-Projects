#pragma once

class Vector2D 
{
public:
	float x;
	float y;
	Vector2D(float xv=0, float yv=0);
	virtual~Vector2D();

	float modulo();						// (2) modulo del vector
	float argumento();					// (3) argumento del vector
	Vector2D unitario();				// (4) devuelve un vector unitario

	float operator * (Vector2D&);		// (5) producto escalar
	Vector2D operator * (float);		// (6) producto por un escalar
	Vector2D operator - (const Vector2D&);	// (7) resta de vectores
	Vector2D operator + (const Vector2D&);	// (8) suma de vectores
};