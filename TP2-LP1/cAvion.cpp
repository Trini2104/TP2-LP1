#include<iostream>
#include<string>
#include"cAvion.h"
#include "cVuelo.h"
using namespace std;

cAvion::cAvion(string _IDAvion, int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, float _PesoMaxTotal, estado _EstadoVuelo) :IDAvion(_IDAvion), CantidadPasajerosPermitidos(_CantidadPasajerosPermitidos), PesoMaxTotal(_PesoMaxTotal)
{
	this->CantidadActualDePasajeros = _CantidadActualDePasajeros;
	this->EstadoVuelo = _EstadoVuelo;
};
cAvion::~cAvion() {};
int cAvion::cantidadAviones = 0;

float cAvion::PesoDelAvion()
{
	float PesosPasajeros = 0;
	float PesoEquipaje = 0;
	float contador = PesosPasajeros + PesoEquipaje;
	return contador;
}
void cAvion::setPesoReaal(float _peso)
{
	this->PesoReal = _peso;
};
void cAvion::setEstadoVuelo(estado _estadovuelo)
{
	this->EstadoVuelo = _estadovuelo;
}
bool cAvion::ChequearCargaMaxima()
{
	if (PesoReal < PesoMaxTotal)
	{
		setEstadoVuelo(RecibiendoPermisoParaDespegar);
		return true;
	}
	else
	{
		setEstadoVuelo(NoRecibiendoPermisoParaAterrizar);
		return false;
	}
}
bool cAvion::AntesDeSalirDelAeropuerto()
{
	if (ChequearCargaMaxima() == true && getCantidadActualDePasajeros()<=getCantidadPasajerosPermitidos())
	{
		setEstadoVuelo(RecibiendoPermisoParaDespegar);
		return true;
	}
	else
	{
		setEstadoVuelo(NoRecibiendoPermisoParaDespegar);
		return false;
	}
}
bool cAvion::Despegar()
{
	if (AntesDeSalirDelAeropuerto() == true)
	{
		setEstadoVuelo(Despegando);
		return true;
	}
	else
	{
		setEstadoVuelo(Nodespega);
	}
}
