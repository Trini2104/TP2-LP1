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

bool cAeropuerto::DarPermiso() //dependiendo de la capacidad del aeropuerto da o no permiso
{
	if (ListaAviones->getOcupados() > getCapacidadAeropuerto())
	{
		Avion->setEstadoVuelo(NoRecibiendoPermisoParaAterrizar); //no da el permiso
		return false;
	}
	else
	{
		Avion->setEstadoVuelo(RecibiendoPermisoParaAterrizar); //da el permiso
		//ListaAviones->AgregarAvion(Avion);
		return true;
	}
}
bool cAeropuerto::Aterrizaje()
{
	if (Avion->getEstadoVuelo() == RecibiendoPermisoParaAterrizar) //si tiene el permiso
	{
		ListaAviones->AgregarAvion(Avion); //le permite aterizar al aeropuerto y agrega un avion a la lista
		Avion->setEstadoVuelo(Aterrizando);
		return true;
	}
	else
		return false;
}
bool cAeropuerto::Despegue()
{
	if (Avion->getEstadoVuelo() == Despegando) //si el vuelo esta despegando se quita un avion de la lista 
	{
		ListaAviones->EliminarAvion(Avion);
		return true;
	}
	else
	{
		return false;
	}
}
int cAeropuerto::CantidadTotalDePasajerosXDia()
{
	int cantidadvuelos = ListaVuelos->getocupados();
	int contadorPasajerosTotales=0;
	for (int i =0; i < cantidadvuelos; i++)//recorre todos los vuelos 
	{
		contadorPasajerosTotales= contadorPasajerosTotales+ListaVuelos->getListaVuelos(i)->getlistapasajeros()->getocupados();
	}//de cada lista vuelos buca cuantos pasajeros viajaron en cada una
	return contadorPasajerosTotales;
}
int cAeropuerto::CantidadDeVuelosAterrizadosXDias()
{
	int cantDespegues=0, canAterrizados=0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoVuelo() == Aterrizando) //ingresa a todos los vuelos de la lista, contabiliza los vuelos que estan aterrizando
		{
			canAterrizados++;
		}
		
	}
	return canAterrizados;
}
int cAeropuerto::CantidadDeVuelosDespegadosXDias()
{
	int cantDespegues=0, canAterrizados=0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoVuelo() == Despegando) //ingresa a todos los vuelos contabiliza los vuelo que despegan
		{
			cantDespegues++;
		}
	}
	return cantDespegues;
}
float cAeropuerto::PorcentajeDeVuelosEnHorario()
{
	int contadorenhorario = 0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoFehca() == EnHoario) //ingresa a cada vuelo, si su estado es en horario lo contabiliza
		{
			contadorenhorario++;
		}
		
	}
	float  porcEnHorario=0;
	porcEnHorario = (contadorenhorario * 100) / (float)cantidadvuelos; //calcula su porcentaje con respecto a los de los demas
	return porcEnHorario;
}