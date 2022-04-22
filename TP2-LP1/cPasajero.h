#pragma once
#include "cFecha.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"Listas.h"
using namespace std;

class cPasajero 
{

private:
	 string DNI;
	const string nombre;
	const string apellido;
	string NumVuelo;
	cFecha* FechaYHoraVuelo;//fecha supuesta
	string NumAsiento;
	static int cantidadPasajeros;
	cListaEquipaje* equipajePasajeros;
public:
	cPasajero(const string _DNI, const string _nombre, const string _apellido, string _NumVuelo, cFecha* _FechaVuelo, string _NumAsiento, cEquipaje* _equipaje) 
	{ 
		cantidadPasajeros++; 
	};
	~cPasajero() 
	{
		cantidadPasajeros--;
	};

	//metodos:
	const string getDNI()
	{
		return DNI;
	}
	bool AgregarEquipaje();//chequea que el equipaje total no supere los 25kg p/persona
	int getCantidadPasajero()
	{
		return cantidadPasajeros;
	}
	
	string to_string();
	void imprimir();
};