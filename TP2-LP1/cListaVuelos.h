#pragma once
#include <iostream>
#include <string>
#include"cVuelo.h"
#define MAX 20
class cListaVuelos
{
private:
	cVuelo** ListaVuelos;
	int ocupados;
	int capacidad;
public:
	cListaVuelos(int longitud = MAX);
	~cListaVuelos();
	int getocupados()
	{
		return ocupados;
	}
	cVuelo* getListaVuelos(int i)
	{
		return ListaVuelos[i];
	}
	bool AgregarVuelo(cVuelo* _vuelo);

	


};