#pragma once
#include "Enums.h"
#include "cAvion.h"
#include "cFecha.h"
#include "cAeropuerto.h"
#include "cPasajero.h"
#include"cListaPasajeros.h"
#include <iostream>
#include <string>
using namespace std;
unsigned int CantidadVuelos = 0;

class cVuelo
{
private:
	string  NumVuelo; //propio
	estado EstadoVuelo; //esta en enum
	cAvion* avion;//en el que se lleva ese vuelo
	tipovuelo TipoVuelo;//partida o arribo
	cFecha* fechayhoraReal; //fecha y hora con la que llego y salió realmente
	cAeropuerto* aeropuertoDestino;
	cListaPasajeros* ListaPasajeros;//pasajeros del vuelo
	static int CantidadVuelos;
	cListaEquipaje* ListaEquipajeVuelo;//equipaje del vuelo
	friend class cLIstaVuelos;
public:
	cVuelo(string _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo)
	{
		CantidadVuelos++;

	};//agregar todos los punteros
	~cVuelo()
	{
		CantidadVuelos--;
	}


	void setCantidadVuelos(int longitud)
	{
		this->CantidadVuelos = longitud;
	}
	string NumeroDeVueloRandom();
	void  setNumeroVuelo(string _numVuelo)
	{
		this->NumVuelo = _numVuelo;
	};
	cListaPasajeros* getlistapasajeros()
	{
		return ListaPasajeros;
	}
	string ObtenerDatosPasajero(const string _DNI);//Busca el pasajero a partir del DNI
	float setpesototal();//devuelve el peso total con un contador de las valijas del pasajero y cada pasajero
	float pesototaldelvuelo();
	string to_string();
	void imprimir();
};