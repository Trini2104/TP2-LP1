#pragma once
#include "cListaVuelos.h"
#include "cListaAviones.h"
#include <iostream>
#include <string>
using namespace std;

class cAeropuerto
{
private:
	const string IDAeropuerto;//del aeropuerto
	const int CapacidadDeAeropuerto ; //cantidad de aviones
	cAvion* Avion;
	//lista de vuelos
	cListaVuelos* ListaVuelos;
	//lista de aviones
	cListaAviones* ListaAviones;

public:
	cAeropuerto(string _IDAeropuerto, int _CapacidadDeAeropuerto);
	~cAeropuerto();
	bool DarPermiso(cAvion *_avion); //tiene una exepcion, da o no da el permiso segun la disponibilidad del hangar; 
	int CantidadTotalDePasajerosXDia(); //tiene que recibir la cantidad actual de paajeros de cada avion de la lista ade aviones
	int CantidadDeVuelosAterrizadosXDia();//calcula la cantidad de vuelos aterrizados en un dia
	int CantidadDeVuelosDespegadosXDia();//hace un contador de aviones a partir de la lista de aviones
	float PorcentajeDeVuelosEnHorario(); // usa la  CantidadDeVuelosAterrizadosYDespegadosXDia( y calcula un contador de los vuelos en horario y fecha correspondiente y saca el porcentaje
	bool Aterrizaje(cAvion* _avion); //agrega un avion al aeropuerto
	bool Despegue(cAvion* _avion);//elimina un avion del aeropuerto
	void AsignarListaVuelos(cListaVuelos* _ListaVuelos);
	void AsignarListaAviones(cListaAviones* _ListaAviones);
	void DesasociarListaVuelos();
	void DesasociarListaAviones();
	const int getCapacidadAeropuerto()
	{
		return CapacidadDeAeropuerto;
	}
	string to_string();
	void imprimir();
};
