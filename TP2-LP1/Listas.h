#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"cVuelo.h"
#include "cPasajero.h"
#define MAX 20
class ListaAviones 
{
private:
	cAvion** ListaAviones;
	
public: 
};
class ListaEquipaje
{
private:
	cEquipaje** ListaEquipaje;
public:
};

class cListaVuelos
{
private:
	bool eliminarNodos;

	cVuelo** ListaVuelos;
public:
	cListaVuelos(unsigned int longitud, bool eliminar){};
	~cListaVuelos();
	
};
class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
public:
	cListaPasajeros(int longitud, bool eliminar);
	~cListaPasajeros();
	bool AgregarPasajero(); //agrega un pasajero a la lista de vuelos
	void CambiarPasajero();//modifica el pasajero
	bool EliminarPasajero(); //elimina el pasajero a la lista de vuelo
};