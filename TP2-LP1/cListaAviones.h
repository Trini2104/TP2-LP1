#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#define MAX 20
class cListaAviones
{
private:
	cAvion** ListaAviones;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaAviones(unsigned int longitud = MAX);
	~cListaAviones();
	bool AgregarAvion(cAvion* _avion);
	cAvion* getListaAviones(int i)
	{
		return ListaAviones[i];
	}
	unsigned int getOcupados()
	{
		return ocupados;
	}
};