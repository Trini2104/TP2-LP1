#include<iostream>
#include<string>
#include "cVuelo.h"
using namespace std;
cVuelo::cVuelo(int _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, cFecha* _fechayhora)
{
	this->NumVuelo = _numVuelo;
	this->EstadoVuelo = _EstadoVuelo;
	this->TipoVuelo = _TipoVuelo;
}
cVuelo::~cVuelo() {};

//ac� no se si agregar la funci�n que genera el nro d vuelo autom�tico o eso ponerlo en un Lista.cpp
//se me hab�a ocurrido hacer un contador d vuelos entoces cada vez q agregas 1 en la lista se suma 1 al contador y ahi tenes los nros automaticos 
void ObtenerDatosPasajero(const string _DNI)
{
	if (cPasajero->getDNI() == _DNI)
	{
		// si el dni coincide, imprimo sus datos
	}
	
}