#include<iostream>
#include<string>
#include "cVuelo.h"
using namespace std;
cVuelo::cVuelo(int _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, cFecha* _fechayhora, int _CantidadVuelos)
{
	this->NumVuelo = _numVuelo;
	this->EstadoVuelo = _EstadoVuelo;
	this->TipoVuelo = _TipoVuelo;
}
cVuelo::~cVuelo() {};


void cVuelo::ObtenerDatosPasajero(const string _DNI)
{
	if (pasajero->getDNI() == _DNI)
	{
		// si el dni coincide, imprimo sus datos
	}
	
}