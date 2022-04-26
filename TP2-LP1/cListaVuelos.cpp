#include<iostream>
#include<string>
#include "cListaVuelos.h"
using namespace std;

cListaVuelos::cListaVuelos( int longitud)
{
	capacidad = longitud;
	this->ListaVuelos = new cVuelo * [longitud];
	for ( int i = 0; i < longitud; i++)
		this->ListaVuelos[i] = NULL;
	ocupados = 0;
};
bool cListaVuelos::AgregarVuelo(cVuelo* _vuelo)
{
	if (ocupados >= capacidad)
	{
		return false;
	}
	this->ListaVuelos[ocupados] = _vuelo;
	ocupados++;
	return true;
}
cListaVuelos::~cListaVuelos()
{
	for (int i = 0; i < capacidad; i++)
	{
		if (this->ListaVuelos[i] != NULL)
			delete ListaVuelos[i];
	}
	delete[]this->ListaVuelos;
	capacidad = 0;
}