#pragma once
#include "cVuelo.h"
#include "cAvion.h"
#include "cListaAviones.h"
#include"cListaVuelos.h"
#include <iostream>
#include <string>
using namespace std;

class cAeropuerto
{
private:
	const string IDAeropuerto;//del aeropuerto
	const int CapacidadDeAeropuerto; //cantidad de aviones
	cAvion* Avion;
	//lista de vuelos
	cListaVuelos* ListaVuelos;
	//lista de aviones
	cListaAviones* ListaAviones;

public:
	cAeropuerto(string _IDAeropuerto, int _CapacidadDeAeropuerto);
	~cAeropuerto();
	bool DarPermiso(); //tiene una exepcion, da o no da el permiso segun la disponibilidad del hangar; 
	void CantidadTotalDePasajerosXDia(); //tiene que recibir la cantidad actual de paajeros de cada avion de la lista ade aviones
	void CantidadDeVuelosAterrizadosYDespegadosXDia(); //hace un contador de aviones a partir de la lista de aviones
	void PorcentajeDeVuelosEnHorario(); // usa la  CantidadDeVuelosAterrizadosYDespegadosXDia( y calcula un contador de los vuelos en horario y fecha correspondiente y saca el porcentaje
	bool Aterrizaje();
	bool Despegue();
	const int getCapacidadAeropuerto()
	{
		return CapacidadDeAeropuerto;
	}
	string to_string();
	void imprimir();
};
