#pragma once
#include "cFecha.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
using namespace std;

class cPasajero 
{

private:
	const string DNI;
	const string nombre;
	const string apellido;
	string NumVuelo;
	cFecha* FechaYHoraVuelo;//fecha supuesta
	 int NumAsiento;
	cEquipaje* equipaje;
	/*int CantidadDeEquipaje;
	float pesoDeEquipaje;*/

public:
	cPasajero(const string _DNI, const string _nombre, const string _apellido, string _NumVuelo, cFecha* _FechaVuelo, int _NumAsiento, cEquipaje* _equipaje) : DNI(_DNI), nombre(_nombre), apellido(_apellido) {};
	~cPasajero();

	//metodos:
	const string getDNI()
	{
		return DNI;
	}
	bool AgregarEquipaje();//chequea que el equipaje total no supere los 25kg p/persona

	string to_string();
	void imprimir();
};