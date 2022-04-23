#include<iostream>
#include<string>
#include "cListaEquipaje.h"
using namespace std;
cListaEquipaje::cListaEquipaje(unsigned int longitud)
{
	capacidad = longitud;
	this->ListaEquipaje = new cEquipaje * [longitud];
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaEquipaje[i] = NULL;
	ocupados = 0;
}
bool cListaEquipaje::AgregarEquipaje(cEquipaje* _equipaje)
{
	if (ocupados >= capacidad)
		return false;
	this->ListaEquipaje[ocupados] = _equipaje;
	ocupados++;
	return true;

}
bool cListaEquipaje::EliminarEquipaje(const string _DNIduenio)
{
	if (this->ListaEquipaje != NULL)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (this->ListaEquipaje[i] != NULL && this->ListaEquipaje[i]->getDNIduenio() == _DNIduenio)
			{
				delete this->ListaEquipaje[i];
				ListaEquipaje[i] = NULL;

				ordenar();
				return true;
			}
			else return false;
		}
	}
}
void cListaEquipaje::ordenar()
{//quita espacios en blanco en la lista
	for (int i = 0; i < capacidad; i++)
	{
		int cont = 0;
		for (int j = 0; j < capacidad - 1; j++)
		{
			if (this->ListaEquipaje[j] == NULL)
			{
				cEquipaje* aux = this->ListaEquipaje[j];
				this->ListaEquipaje[j] = this->ListaEquipaje[j + 1];
				this->ListaEquipaje[j + 1] = aux;
				cont++;
			}
		}if (cont == 0)
			break;
	}
}
cListaEquipaje::~cListaEquipaje()
{
	for (int i = 0; i < capacidad; i++)
	{
		if (this->ListaEquipaje[i] != NULL)
			delete ListaEquipaje[i];
	}
	delete[]this->ListaEquipaje;
	capacidad = 0;
}