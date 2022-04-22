#pragma once
#include "Enums.h"
#include "cAvion.h"
#include "cFecha.h"
#include "cAeropuerto.h"
#include "cPasajero.h"
#include"Listas.h"
#include <iostream>
#include <string>
using namespace std;
unsigned int CantidadVuelos = 0;

class cVuelo
{
private:
	static int NumVuelo; 
	estado EstadoVuelo;
	//cAvion* avion;
	tipovuelo TipoVuelo; 
	cFecha* fechayhoraReal; //fecha y hora con la que llego y sali� realmente
	cAeropuerto* aeropuertoDestino;
	cListaPasajeros*  pasajeros;
	float PesoTotal;
	unsigned int CantidadVuelos = 0;
	cListaEquipaje* EquipajeVuelo;
public:
	cVuelo(int _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, cFecha* _fechayhora, int _CantidadVuelos){};//agregar todos los punteros
	~cVuelo();
	
	
	void setCantidadVuelos(int longitud)
	{
		this->CantidadVuelos = longitud;
	}
	int setNumeroVuelo(int _NumVuelo)
	{
		_NumVuelo = rand() % 1001;
		this->NumVuelo = _NumVuelo;
	}
	cListaPasajeros* getlistapasajeros()
	{
		return pasajeros;
	}
	void ObtenerDatosPasajero(const string _DNI);//Busca el pasajero a partir del DNI
	float setpesototal();//devuelve el peso total con un contador de las valijas del pasajero y cada pasajero
	float getpesototaldelequipaje(string _DNI);
	string to_string();
	void imprimir();
};