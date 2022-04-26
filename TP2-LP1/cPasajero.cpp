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
	ListaDeValijasATransportar = NULL;
};
cPasajero::~cPasajero() {};
int cPasajero::cantidadPasajeros = 0;

bool cPasajero::asociarListaEquipaje(cListaEquipaje* _ListaEquipaje)
{
	

	if (this->ListaDeValijasATransportar == NULL)
	{
		this->ListaDeValijasATransportar = _ListaEquipaje;
		return true;
	}
	else return false;
}
bool cPasajero::AgregarEquipaje(cEquipaje* _equipaje)
{
	//(*ListaeValijasATransportar)[0]->getPesoDelEquipaje();
	
	if (ListaDeValijasATransportar->PesoTotalEquipaje() + _equipaje->getPesoDelEquipaje() < 25) //si la suma de todo su equipaje mas el que desea agregar es menor a todo su equipaje puede agregarlo
	{
		ListaDeValijasATransportar->AgregarEquipaje(_equipaje);
		return true;
	}
	else
	{
		return false;
	}
};
bool cPasajero::EliminarEquipaje(cEquipaje* _equipaje)
{
	if (ListaDeValijasATransportar->EliminarEquipaje(_equipaje->getDNIduenio()) == true)
		return true;
	else return false;

}

unsigned int cPasajero::getEquipaje()
{
	return ListaDeValijasATransportar->getocupados();
}

string cPasajero::to_string()
{
	return
		"Nombre del Pasajero: " + nombre + "\n" +
		"Apellido: " + apellido + "\n" +
		"DNI: " + DNI + "\n" +
		"Numero de vuelo: " + NumVuelo + "\n" +
		"Numero de asiento: " + NumAsiento + "\n";
	    "Cantidad de equipaje: " + std::to_string(equipaje->getCantidadDeEquipaje()) +"\n";
		"Peso del equipaje: " + std::to_string(equipaje->getPesoDelEquipaje()) + "\n";

}
void cPasajero:: imprimir()
{
	cout << this->to_string() << endl;
}