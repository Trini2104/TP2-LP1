#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#include "cPasajero.h"
#define MAX 20
class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
	unsigned int ocupados;//cuantos pasajeros ocupan la lista
	unsigned int capacidad; //cuantos pasajeeros entran en la lista
public:
	cListaPasajeros(unsigned int longitud = MAX);
	~cListaPasajeros();
	bool AgregarPasajero(cPasajero* _pasajero); //agrega un pasajero a la lista de vuelos
	bool CambiarPasajero(string _DNIPasajero, cPasajero* PasajeroNuevo);//modifica el pasajero
	bool EliminarPasajero(string _DNIPasajero); //elimina el pasajero a la lista de vuelo
	unsigned int getocupados()
	{
		return ocupados;
	}
	unsigned int getcapacidad()
	{
		return capacidad;
	}
	cPasajero* getListaPasajeros(int i) //me permite ingresar a cada pasajero de la lista
	{
		if (i < capacidad && i >= 0)
		{
			return ListaPasajeros[i];

		}
		throw invalid_argument("Posición inválida");
	}
	cPasajero* operator[](int i)
	{
		return getListaPasajeros(i);
	}
	void ordenar();

};