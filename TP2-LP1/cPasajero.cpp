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
	cantidadPasajeros++; //suma 1 pasajero a la cant. pasajeros
};
cPasajero::~cPasajero() {
	cantidadPasajeros--;
};
int cPasajero::cantidadPasajeros = 0;
void cPasajero::asignarFechaYHoraVuelo(cFecha* _FechaYHoraVuelo)
{
	this->FechaYHoraVuelo = _FechaYHoraVuelo;
}
void cPasajero::desasociarasignarFechaYHoraVuelo()
{
	FechaYHoraVuelo = NULL;
}
void cPasajero::AsignarListaEquipajeDelPasajero(cListaEquipaje* _ListaEquipajeDelPasajero)
{
	this->ListaDeValijasATransportar = _ListaEquipajeDelPasajero; // le paso la lista del equipaje de cada pasajero
}
void cPasajero::desasociarAsignarListaEquipajeDelPasajero()
{
	ListaDeValijasATransportar = NULL;
}
void cPasajero::asignarequipaje(cEquipaje* _equipaje)
{
	this->equipaje = _equipaje;
}
void cPasajero::desasociarEquipaje()
{
	 equipaje = NULL;
};
bool cPasajero::AgregarEquipajePasajero(cEquipaje* _equipaje)
{	
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
bool cPasajero::EliminarEquipajePasajero(cEquipaje* _equipaje)
{
	if (ListaDeValijasATransportar->EliminarEquipaje(_equipaje->getPesoDelEquipaje(),_equipaje->getDNIduenio()) == true)
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
		"Numero de asiento: " + NumAsiento + "\n"+
	    "Cantidad de equipaje: " + std::to_string(equipaje->getCantidadDeEquipaje()) +"\n"+
		"Peso del equipaje: " + std::to_string(equipaje->getPesoDelEquipaje()) + "\n";

}
void cPasajero:: imprimir()
{
	cout << this->to_string() << endl;
}