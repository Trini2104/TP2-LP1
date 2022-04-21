#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"cVuelo.h"
#include "cPasajero.h"
#define MAX 20
class cListaAviones 
{
private:
	cAvion** ListaAviones;
	unsigned int ocupados;
	unsigned int capacidad;
public: 
	cListaAviones(unsigned int longitud = MAX);
	bool AgregarAvion(cAvion* _avion);
	~cListaAviones();
};
class cListaEquipaje
{
private:
	cEquipaje** ListaEquipaje;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaEquipaje(unsigned int longitud = MAX);
	bool AgregarEquipaje(cEquipaje* _equipaje);
	bool EliminarEquipaje(const string _DNIduenio);
	void ordenar();
	~cListaEquipaje();

};

class cListaVuelos
{
private:
	cVuelo** ListaVuelos;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaVuelos(unsigned int longitud = MAX);
	bool AgregarVuelo(cVuelo* _vuelo);
	~cListaVuelos();

	
};
class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaPasajeros(unsigned int longitud=MAX);
	~cListaPasajeros();
	bool AgregarPasajero(cPasajero* _pasajero); //agrega un pasajero a la lista de vuelos
	void CambiarPasajero( string _DNIPasajero, cPasajero* PasajeroNuevo);//modifica el pasajero
	bool EliminarPasajero (string _DNIPasajero); //elimina el pasajero a la lista de vuelo
	void ordenar();

};