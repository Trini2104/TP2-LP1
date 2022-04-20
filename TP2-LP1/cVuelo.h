#pragma once
#include "Enums.h"
#include "cAvion.h"
#include "cFecha.h"
#include "cAeropuerto.h"
#include "cPasajero.h"
#include <iostream>
#include <string>
using namespace std;

class cVuelo
{
private:
	static int NumVuelo; 
	estado EstadoVuelo;
	//cAvion* avion;
	tipovuelo TipoVuelo; 
	cFecha* fechayhoraReal; //fecha y hora con la que llego y salió realmente
	cAeropuerto* aeropuertoDestino;
	cPasajero* Pasajero;
	float PesoTotal;
	//agregar lista equipaje
public:
	cVuelo(int _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, cFecha* _fechayhora);//agregar todos los punteros
	~cVuelo();
	
	int setNumeroVuelo(int _NumVuelo)
	{
		_NumVuelo = rand() % 1001;
		this->NumVuelo = _NumVuelo;
	}
	void ObtenerDatosPasajero(const string _DNI);//Busca el pasajero a partir del DNI
	float setpesototal();//devuelve el peso total con un contador de las valijas del pasajero y cada pasajero

	string to_string();
	void imprimir();
};