#pragma once
#include "cAvion.h"
#include <iostream>
#include <string>
#include "cEquipaje.h"
#include"cVuelo.h"
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
	cVuelo** ListaVuelos;
public:
	cListaVuelos(int n = MAX) 
	{
		ListaVuelos = new cVuelo * [n];
		for (int i = 0; i < n; i++)
		{
			ListaVuelos[i] = NULL; //a chequear no se si esta bien esto es lo q entendi d la clase y lo q copie
		}							//osea supuestamente aca ya inicialicÚ mi lista
	};
	~cListaVuelos();
	
};
class cListaPasajeros
{
private:
	cPasajero** ListaPasajeros;
public:
	bool AgregarPasajero(); //agrega un pasajero a la lista de vuelos
	void CambiarPasajero();//modifica el pasajero
	bool EliminarPasajero(); //elimina el pasajero a la lista de vuelo
};