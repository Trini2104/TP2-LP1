#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"cVuelo.h"
#include "cPasajero.h"
#define MAX 20
class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaPasajeros(unsigned int longitud = MAX);
	~cListaPasajeros();
	bool AgregarPasajero(cPasajero* _pasajero); //agrega un pasajero a la lista de vuelos
	void CambiarPasajero(string _DNIPasajero, cPasajero* PasajeroNuevo);//modifica el pasajero
	bool EliminarPasajero(string _DNIPasajero); //elimina el pasajero a la lista de vuelo
	unsigned int getocupados()
	{
		return ocupados;
	}
	unsigned int getcapacidad()
	{
		return capacidad;
	}
	cPasajero* getListaPasajeros(int i)
	{
		return ListaPasajeros[i];
	}
	void ordenar();

};