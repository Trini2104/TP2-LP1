#include<iostream>
#include<string>
#include "cListaAviones.h"
using namespace std;
cListaAviones::cListaAviones(unsigned int longitud)
{
	capacidad = longitud;
	this->ListaAviones = new cAvion * [longitud];
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaAviones[i] = NULL;
	ocupados = 0;
};
bool cListaAviones::AgregarAvion(cAvion* _avion)
{
	if (ocupados >= capacidad)
	{
		return false;
	}//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos falsos
	this->ListaAviones[ocupados] = _avion;
	ocupados++;
	return true;
}
cListaAviones::~cListaAviones()
{
	for (int i = 0; i < capacidad; i++)
	{
		if (this->ListaAviones[i] != NULL)
			delete ListaAviones[i];
	}
	delete[]this->ListaAviones;
	capacidad = 0;
}