#pragma once
#include "cFecha.h"
#include <iostream>
#include <string>
using namespace std;

class cPasajero 
{

private:
	const string DNI;
	const string nombre;
	const string apellido;
	const string NumVuelo;
	cFecha* FechaYHoraVuelo;//fecha supuesta
	const int NumAsiento;
	int CantidadDeEquiaje;
	float pesoDeEquipaje;

public:
	cPasajero(const string _DNI, const string _nombre, const string _apellido, const string _NumVuelo, cFecha* _FechaVuelo, const int _NumAsiento);//agregar lista 
	~cPasajero();
	bool AgregarEquipaje(); //Devuelve si supera o no supera el peso 

	string to_string();
	void imprimir();
};