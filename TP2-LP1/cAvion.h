#pragma once
#include "Enums.h"
#include <iostream>
#include <string>
using namespace std;

class cAvion 
{
private:
	const string ID;
	const int CantidadPasajerosPermitidos;
	int CantidadActualDePasajeros;
	const float PesoMaxTotal;
	estado EstadoVuelo;
	static int cantidad;

public:
	cAvion(const string _ID, const int _CantidadPasajerosPertmitidos, int _CantidadActualDePasajeros, const float _PesoMaxTotal, estado _EstadoVuelo);
	~cAvion();

	void ChecqueraCargaMaxima(); //verifica que no supere el peso
	void AntesDeSalirDelAeropuerto(); //verifica que se cumplan la CantidadPasajerosPermitidos y PesoMaxTotal
	
	string to_string();
	void imprimir();
};