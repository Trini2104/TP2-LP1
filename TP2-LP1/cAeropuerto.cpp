#include<iostream>
#include<string>
#include"cAeropuerto.h"

using namespace std;
cAeropuerto::cAeropuerto(string _IDAeropuerto, int _CapacidadDeAeropuerto) :IDAeropuerto(_IDAeropuerto), CapacidadDeAeropuerto(_CapacidadDeAeropuerto)
{
	Avion = NULL;
	ListaVuelos = NULL;
	ListaAviones = NULL;
};

cAeropuerto::~cAeropuerto() {};

bool cAeropuerto::DarPermiso()
{
	if (ListaAviones->getOcupados() > getCapacidadAeropuerto())
	{
		Avion->setEstadoVuelo(NoRecibiendoPermisoParaAterrizar);
		return false;
	}
	else
	{
		Avion->setEstadoVuelo(RecibiendoPermisoParaAterrizar);
		//ListaAviones->AgregarAvion(Avion);
		return true;
	}
}
bool cAeropuerto::Aterrizaje()
{
	if (Avion->getEstadoVuelo() == RecibiendoPermisoParaAterrizar)
	{
		ListaAviones->AgregarAvion(Avion);
		Avion->setEstadoVuelo(Aterrizando);
		return true;
	}
	else
		return false;
}
bool cAeropuerto::Despegue()
{
	if (Avion->getEstadoVuelo() == Despegando)
	{
		ListaAviones->EliminarAvion(Avion);
		return true;
	}
	else
	{
		return false;
	}
}