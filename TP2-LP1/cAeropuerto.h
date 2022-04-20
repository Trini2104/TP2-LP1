#pragma once
#include "cVuelo.h"
#include "cAvion.h"
#include <iostream>
#include <string>
using namespace std;

class cAeropuerto
{
private:
	const string ID;
	const int CapacidadDeAeropuerto; //cantidad de aviones
	//lista de vuelos
	//lista de aviones

public:
	cAeropuerto(const string _ID, const int _CapacidadDeAeropuerto): ID(_ID), CapacidadDeAeropuerto(_CapacidadDeAeropuerto) {};
	~cAeropuerto();

	bool DarPermiso(); // da o no da el permiso segun la disponibilidad del hangar; 
	void CantidadTotalDePasajerosXDia(); //tiene que recibir la cantidad actual de paajeros de cada avion de la lista ade aviones
	void CantidadDeVuelosAterrizadosYDespegadosXDia(); //hace un contador de aviones a partir de la lista de aviones
	void PorcentajeDeVuelosEnHorario(); // usa la  CantidadDeVuelosAterrizadosYDespegadosXDia( y calcula un contador de los vuelos en horario y fecha correspondiente y saca el porcentaje

	string to_string();
	void imprimir();
};