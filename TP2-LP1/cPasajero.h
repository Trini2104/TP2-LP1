#pragma once
#include "cFecha.h"
#include <iostream>
#include <string>
#include"cListaEquipaje.h"
using namespace std;

class cPasajero
{

private:
	const string DNI;
	const string nombre;
	const string apellido;
	string NumVuelo;//del pasaje
	cFecha* FechaYHoraVuelo;//fecha supuesta del pasaje
	string NumAsiento;//del vuelo
	static int cantidadPasajeros;
	cEquipaje* equipaje;
	cListaEquipaje* ListaDeValijasATransportar;
	friend class cListaEquipaje;
	friend class cListaPasajeros;
public:
	cPasajero(string _DNI, string _nombre, string _apellido, string _NumVuelo, string _NumAsiento);
	~cPasajero();

	//metodos:
	void asignarFechaYHoraVuelo(cFecha* _FechaYHoraVuelo);
	void desasociarasignarFechaYHoraVuelo();
	void AsignarListaEquipajeDelPasajero(cListaEquipaje* _ListaEquipajeDelPasajero);
	void desasociarAsignarListaEquipajeDelPasajero();
	void asignarequipaje(cEquipaje* _equipaje);
	void desasociarEquipaje();
	float getPesoTotalequipaje()
	{
		return ListaDeValijasATransportar->PesoTotalEquipaje();
	}
	const string getDNI()
	{
		return DNI;
	}
	const string getnombre()
	{
		return nombre;
	}
	const string getapellido()
	{
		return apellido;
	}
	unsigned int getEquipaje();

	string getNumVuelo()
	{
		return NumVuelo;
	}
	cFecha* getFechaYHoraVuelo()
	{
		return FechaYHoraVuelo;
	}
	string getNumAsiento()
	{
		return NumAsiento;
	}
	cListaEquipaje* getlistaequipaje()
	{
		return ListaDeValijasATransportar;
	}
	
	bool AgregarEquipajePasajero(cEquipaje* _equipaje);//chequea que el equipaje total no supere los 25kg p/persona y si puede agregar mas
	bool operator+(cEquipaje* _equipaje)
	{
		if (AgregarEquipajePasajero(_equipaje) == true)
			return true;
		else return false;

	}
	bool EliminarEquipajePasajero(cEquipaje* _equipaje);
	bool operator-(cEquipaje* _equipaje)
	{
		if (EliminarEquipajePasajero(_equipaje) == true)
			return true;
		else return false;
	}
	int getCantidadPasajero()
	{
		return cantidadPasajeros;
	}
	string to_string();
	void imprimir();
};