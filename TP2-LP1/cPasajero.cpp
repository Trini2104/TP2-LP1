#include<iostream>
#include<string>
#include"cPasajero.h"
using namespace std;
cPasajero::cPasajero(string _DNI, string _nombre, string _apellido, string _NumVuelo, string _NumAsiento) : DNI(_DNI), nombre(_nombre), apellido(_apellido)
{

	this->NumAsiento = _NumAsiento;
	this->NumVuelo = _NumVuelo;
	equipaje = NULL;
	FechaYHoraVuelo = NULL;
	ListaeValijasATransportar = NULL;
};
cPasajero::~cPasajero() {};
int cPasajero::cantidadPasajeros = 0;

bool cPasajero::asociarListaEquipaje(cListaEquipaje* _ListaEquipaje)
{
	if (this->ListaeValijasATransportar == NULL)
	{
		this->ListaeValijasATransportar = _ListaEquipaje;
		return true;
	}
	else return false;
}
bool cPasajero::AgregarEquipaje(cEquipaje* _equipaje)
{
	if (ListaeValijasATransportar->PesoTotalEquipaje() + _equipaje->getPesoDelEquipaje() < 25) //si la suma de todo su equipaje mas el que desea agregar es menor a todo su equipaje puede agregarlo
	{
		ListaeValijasATransportar->AgregarEquipaje(_equipaje);
		return true;
	}
	else
	{
		return false;
	}
};

unsigned int cPasajero::getEquipaje()
{
	return ListaeValijasATransportar->getocupados();
}



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