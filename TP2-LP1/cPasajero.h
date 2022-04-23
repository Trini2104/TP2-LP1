#pragma once
#include "cFecha.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"cListaEquipaje.h"
using namespace std;

class cPasajero
{

private:
	const string DNI;
	const string nombre;
	const string apellido;
	string NumVuelo;//del pasaje
	cFecha* FechaYHoraVuelo;//fecha supuesta del pasaje
	string NumAsiento;//del vuelo
	static int cantidadPasajeros;
	cEquipaje* equipaje;
	cListaEquipaje* ListaeValijasATransportar;
	friend class cListaEquipaje;
	friend class cListaPasajeros;
public:
	cPasajero(string _DNI, string _nombre, string _apellido, string _NumVuelo, string _NumAsiento)
	{
		cantidadPasajeros++; //contabiliza la cantidad de veces que se instancio
	};
	~cPasajero()
	{
		cantidadPasajeros--; //cada vez que libere memoria elimina un objeto del contador. 
	};

	//metodos:

	float getPesoTotalequipaje()
	{
		return ListaeValijasATransportar->PesoTotalEquipaje();
	}
	const string getDNI()
	{
		return DNI;
	}
	const string getnombre()
	{
		return nombre;
	}
	const string getapellido()
	{
		return apellido;
	}
	unsigned int getEquipaje();

	string getNumVuelo()
	{
		return NumVuelo;
	}
	cFecha* getFechaYHoraVuelo()
	{
		return FechaYHoraVuelo;
	}
	string getNumAsiento()
	{
		return NumAsiento;
	}

	bool AgregarEquipaje(cEquipaje* _equipaje);//chequea que el equipaje total no supere los 25kg p/persona y si puede agregar mas
	int getCantidadPasajero()
	{
		return cantidadPasajeros;
	}

	string to_string();
	void imprimir();
};