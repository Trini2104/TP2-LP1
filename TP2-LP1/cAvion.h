#pragma once
#include "Enums.h"
#include "cPasajero.h"
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
	cPasajero* pasajero;

public:
	cAvion(const string _ID, const int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, const float _PesoMaxTotal, int _cantidad, estado _EstadoVuelo);
	~cAvion();

	float PesoDelAvion();

	void ChequearCargaMaxima(cAvion* avion); //verifica que no supere el peso
	void AntesDeSalirDelAeropuerto(); //verifica que se cumplan la CantidadPasajerosPermitidos y PesoMaxTotal
	
	const int getCantidadPasajerosPermitidos()
	{
		return CantidadPasajerosPermitidos;
	}
	const int getCantidadActualDePasajeros()
	{
		return CantidadActualDePasajeros;
	}
	string to_string();
	void imprimir();
};