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
	if (equipajePasajeros->getCantidadDeEquipaje() != 0)// get de la cantidad de eqipaje de la clase cequipaje 
	{
		if (equipajePasajeros->getPesoDelEquipaje() < 25)// hacerlos en la lista para poder entrar o entrarlo desde la clase
			return false;
		else
			return true;
	}
else
return true;
};
float cPasajero::getpesototaldelequipaje(string _DNI)
{//probarlo en vuelo con un for metiendonnos en cada sub i
	for( int i=0; i< cantidadPasajeros;i++)
	{
		this->equipajePasajeros->// meternos desde el dni que esta en el equipaje con el dni del pasajero
	}
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