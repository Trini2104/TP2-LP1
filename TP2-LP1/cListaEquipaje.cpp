#include<iostream>
#include<string>
#include "cListaEquipaje.h"
using namespace std;
cListaEquipaje::cListaEquipaje(int longitud)
{
	this->capacidad = longitud;
	this->ListaEquipaje = new cEquipaje * [longitud];
	for ( int i = 0; i < longitud; i++)
		this->ListaEquipaje[i] = NULL;
	ocupados = 0;
}

bool cListaEquipaje::AgregarEquipaje(cEquipaje* _equipaje)
{
	if (ocupados >= capacidad)
	{
		return false; // si la cantidad de equipaje es mayor a la capacidad  
	}
	else
	{
		this->ListaEquipaje[ocupados] = _equipaje; // agrego equipaje
		ocupados++;
		ordenar();
		return true;
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
bool cListaEquipaje::EliminarEquipaje(float _peso, const string _DNIduenio)
{
	if (this->ListaEquipaje != NULL)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (this->ListaEquipaje[i] != NULL && this->ListaEquipaje[i]->getDNIduenio() == _DNIduenio && this->ListaEquipaje[i]->getPesoDelEquipaje() == _peso)
			{
				delete this->ListaEquipaje[i];
				ListaEquipaje[i] = NULL;
				ocupados--;
				ordenar();
				return true;
			}
		}
	}
	else return false;
}

float cListaEquipaje::PesoTotalEquipaje()
{
	float contador = 0;
	for (int i = 0; i < ocupados; i++)
	{
		contador = contador + ListaEquipaje[i]->getPesoDelEquipaje();//ingreso a cada equipaje de mi lista y sumo su peso
	}
	return  contador;
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