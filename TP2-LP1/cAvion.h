#pragma once
#include "Enums.h"
#include "cPasajero.h"
#include <iostream>
#include <string>
using namespace std;
class cAvion
{
private:
	const string IDAvion; //del avion
	const int CantidadPasajerosPermitidos;
	int CantidadActualDePasajeros;
	const float PesoMaxTotal;
	float PesoReal;
	static int cantidadAviones;
	estado EstadoVuelo; //despegue, aterriza, pedir permiso, recibir permiso
	friend class cListaAviones;
public:
	cAvion(string _IDAvion, int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, float _PesoMaxTotal, estado _EstadoVuelo)
	{
		cantidadAviones++;
	};
	~cAvion()
	{
		cantidadAviones--;
	};

	float PesoDelAvion();

	void ChequearCargaMaxima(cAvion* avion); //verifica que no supere el peso
	void AntesDeSalirDelAeropuerto(); //verifica que se cumplan la CantidadPasajerosPermitidos y PesoMaxTotal

	void setEstadoVuelo(estado _estadovuelo);

	const int getCantidadPasajerosPermitidos()
	{
		return CantidadPasajerosPermitidos;
	}
	const int getCantidadActualDePasajeros()
	{
		return CantidadActualDePasajeros;
	}
	void setPesoReaal(float _peso);

	estado getEstadoVuelo()
	{
		return EstadoVuelo;
	}
	string to_string();
	void imprimir();
};