#include<iostream>
#include<string>
#include"cPasajero.h"
using namespace std;
cPasajero::cPasajero(const string _DNI, const string _nombre, const string _apellido, string _NumVuelo, cFecha* _FechaVuelo, int _NumAsiento, cEquipaje* _equipaje)
{
	this->NumAsiento = _NumAsiento;
	this->NumVuelo = _NumVuelo;
}
cPasajero::~cPasajero() {};
bool cPasajero::AgregarEquipaje()
{
	if (equipaje->getCantidadDeEquipaje() != 0)// get de la cantidad de eqipaje de la clase cequipaje 
	{
		if (equipaje->getPesoDelEquipaje() < 25)
			return false;
		else
			return true;
	}
	else
		return true;
};
