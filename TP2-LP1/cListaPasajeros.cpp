#include<iostream>
#include<string>
#include "cListaPasajeros.h"
using namespace std;
cListaPasajeros::cListaPasajeros( int longitud)
{
	capacidad = longitud;
	this->ListaPasajeros = new cPasajero * [longitud];
	for (int i = 0; i < longitud; i++)
		this->ListaPasajeros[i] = NULL;

	ocupados = 0;
};
bool cListaPasajeros::AgregarPasajero(cPasajero* _pasajero)
{
	if (ocupados >= capacidad)
	{
		return false;
	}//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos, retorno falso
	ordenar();
	this->ListaPasajeros[ocupados] = _pasajero; // sino, agrego al pasajero al final de la lista
	ocupados++;
	return true;
}
void cListaPasajeros::ordenar() // ordena la lista para que al agregar, directamente lo agrego al final del listado
{
	for (int i = 0; i < capacidad; i++)
	{
		for (int j = 0; j < capacidad - 1; j++)
		{
			if (this->ListaPasajeros[j] == NULL)
			{
				cPasajero* aux = this->ListaPasajeros[j];
				this->ListaPasajeros[j] = this->ListaPasajeros[j + 1];
				this->ListaPasajeros[j + 1] = aux;
			}
		}
	}
}

bool cListaPasajeros::CambiarPasajero(string _DNIPasajero, cPasajero* PasajeroNuevo)
{
	for (int i = 0; i < capacidad; i++)
	{
		if (this->ListaPasajeros != NULL && this->ListaPasajeros[i]->getDNI() == _DNIPasajero)
		{
			cPasajero* aux = ListaPasajeros[i];
			ListaPasajeros[i] = PasajeroNuevo;
			delete aux;
			return true;
		}
		else
			return false;
	}

}
bool cListaPasajeros::EliminarPasajero(string _DNIPasajero)
{
	if (this->ListaPasajeros != NULL)
	{
		for (int i = 0; i < capacidad; i++)
		{
			if (this->ListaPasajeros[i] != NULL && this->ListaPasajeros[i]->getDNI() == _DNIPasajero)
			{
				delete this->ListaPasajeros[i];
				ListaPasajeros[i] = NULL;
				ocupados--;
				ordenar();
				return true;
			}
			
		}
	}
	else return false;

};
cListaPasajeros::~cListaPasajeros()
{
	for (int i = 0; i < capacidad; i++)
	{
		this->ListaPasajeros[i] = NULL;
			//delete this->ListaPasajeros[i];
	}
	delete[]this->ListaPasajeros;
	capacidad = 0;
}