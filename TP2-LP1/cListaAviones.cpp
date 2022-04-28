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
	}//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos, no puedo agregar, por lo tanto retorno falso
	this->ListaAviones[ocupados] = _avion;
	ocupados++;
	return true;
}
void cListaAviones::Ordenar()
{
	for (int i = 0; i < capacidad; i++)
	{
		for (int j = 0; j < capacidad - 1; j++)
		{
			if (this->ListaAviones[j] == NULL)
			{
				cAvion* aux = this->ListaAviones[j];
				this->ListaAviones[j] = this->ListaAviones[j + 1];
				this->ListaAviones[j + 1] = aux;
			}
		}
	}
}
bool cListaAviones::EliminarAvion(cAvion* _avion)
{
	if (this->ListaAviones!= NULL)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (this->ListaAviones[i] != NULL && this->ListaAviones[i] == _avion) // busco el avion del listado y lo elimmino si pertenece al listado
			{
				delete this->ListaAviones[i];
				ListaAviones[i] = NULL;

				Ordenar();
				return true;
			}
			else return false; // si no pertenece al listado  o el listado de aviones esta vacio, retorno falso
		}
	}
}
cListaAviones::~cListaAviones()
{
	for (int i = 0; i < capacidad; i++)
	{
		this->ListaAviones[i] = NULL;
			//delete ListaAviones[i];
	}
	delete[]this->ListaAviones;
	capacidad = 0;
}