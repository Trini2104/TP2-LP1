#pragma once
#include "Enums.h"
#include <iostream>
#include <string>
using namespace std;
class cAvion
{
private:
	const string IDAvion; //del avion
	const int CantidadPasajerosPermitidos=120;
	int CantidadActualDePasajeros;
	const float PesoMaxTotal=2000;
	float PesoReal;
	static int cantidadAviones;
	estado EstadoVuelo; //despegue, aterriza, pedir permiso, recibir permiso
	friend class cListaAviones;
public:
	cAvion(string _IDAvion, int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, float _PesoMaxTotal, float _pesoreal, int _cantidadaviones, estado _EstadoVuelo);
	~cAvion();

	//float PesoDelAvion();
	bool ChequearCargaMaxima(); //verifica que no supere el peso
	bool AntesDeSalirDelAeropuerto(); //verifica que se cumplan la CantidadPasajerosPermitidos y PesoMaxTotal
	bool Despegar(); //Cambia el estado del avion
	void setEstadoVuelo(estado _estadovuelo); 
	const int getCantidadPasajerosPermitidos()
	{
		return CantidadPasajerosPermitidos;
	}
	const int getCantidadActualDePasajeros()
	{
		return CantidadActualDePasajeros;
	}
	void setPesoReal(float _peso);
	estado getEstadoVuelo()
	{
		return EstadoVuelo;
	}
	string to_string();
	void imprimir();
};