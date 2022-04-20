#include<iostream>
#include<string>
#include"cPasajero.h"
using namespace std;
cPasajero::cPasajero( string _DNI, const string _nombre, const string _apellido, string _NumVuelo, cFecha* _FechaVuelo, string _NumAsiento, cEquipaje* _equipaje) : nombre(_nombre), apellido(_apellido)
{
	this->DNI = _DNI;
	this->NumAsiento = _NumAsiento;
	this->NumVuelo = _NumVuelo;
}
cPasajero::~cPasajero() {};
bool cPasajero:: AgregarEquipaje()
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
string cPasajero::to_string()
{
	return
		"Nombre del Pasajero: " + nombre + "\n" +
		"Apellido: " + apellido + "\n" +
		"DNI: " + DNI + "\n" +
		"Numero de vuelo: " + NumVuelo + "\n" +
		"Numero de asiento: " + NumAsiento + "\n";
		//"Cantidad y peso del equipaje: " + equipaje + "\n";

}
void imprimir();