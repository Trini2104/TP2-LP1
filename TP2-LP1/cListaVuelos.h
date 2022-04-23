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
	bool AgregarVuelo(cVuelo* _vuelo);
	float CantidadTotalEquipajeVuelo();
	~cListaVuelos();


};