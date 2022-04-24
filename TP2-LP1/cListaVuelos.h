#pragma once
#include <iostream>
#include <string>
#include"cVuelo.h"
#define MAX 20
class cListaVuelos
{
private:
	cVuelo** ListaVuelos;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaVuelos(unsigned int longitud = MAX);
	~cListaVuelos();
	unsigned int getocupados()
	{
		return ocupados;
	}
	cVuelo* getListaVuelos(int i)
	{
		return ListaVuelos[i];
	}
	bool AgregarVuelo(cVuelo* _vuelo);

	


};