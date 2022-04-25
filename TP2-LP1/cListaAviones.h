#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#define MAX 20
class cListaAviones
{
private:
	cAvion** ListaAviones;
	 int ocupados;
	int capacidad;
public:
	cListaAviones(unsigned int longitud = MAX);
	~cListaAviones();
	bool AgregarAvion(cAvion* _avion);
	bool EliminarAvion(cAvion* _avion);
	void Ordenar();
	cAvion* getListaAviones(int i) //me permite ingresar a la lista de aviones
	{
		return ListaAviones[i];
	}
	 int getOcupados()
	{
		return ocupados;
	}
};