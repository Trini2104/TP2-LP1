#include<iostream>
#include<string>
#include "cVuelo.h"
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;
cVuelo::cVuelo(string _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo)
{
	this->NumVuelo = _numVuelo;
	this->EstadoVuelo = _EstadoVuelo;
	this->TipoVuelo = _TipoVuelo;
	avion = NULL;
	fechayhoraReal = NULL;
	aeropuertoDestino = NULL;
	ListaPasajeros = NULL;
	ListaEquipajeVuelo = NULL;

}
cVuelo::~cVuelo() {};
int cVuelo::CantidadVuelos = 0;


string cVuelo::ObtenerDatosPasajero(const string _DNIPasajero)
{
	string  datospasajero;
	int cant;
	float peso;
	for (int i = 0; i < ListaPasajeros->getocupados(); i++)
	{
		if (this->ListaPasajeros->getListaPasajeros(i) != NULL && ListaPasajeros->getListaPasajeros(i)->getDNI() == _DNIPasajero)
		{
			cant = ListaPasajeros->getListaPasajeros(i)->getEquipaje();
			peso = +ListaPasajeros->getListaPasajeros(i)->getPesoTotalequipaje();
			string cantequipaje(std::to_string(cant));
			string pesoequipaje(std::to_string(peso));
			datospasajero += "PASAJERO: " + ListaPasajeros->getListaPasajeros(i)->getDNI() + ListaPasajeros->getListaPasajeros(i)->getapellido() + cantequipaje + pesoequipaje;
			//si encuentra al pasajero por su dni guarda todos sus datos en un string
		}
	}

}
string cVuelo::NumeroDeVueloRandom()
{
	int numero1, numeroletras;
	numeroletras = 'A' + (rand() % 26);
	numero1 = rand() % 9999;
	string numVuelo;
	numVuelo += numeroletras + numero1;
	this->setNumeroVuelo(numVuelo);

};
float cVuelo::pesototaldelvuelo()
{
	int pesopasajeros = 0;
	int cantidadPasajeros = ListaPasajeros->getocupados();
	float PesoValijas, PesoTotal;
	pesopasajeros = (cantidadPasajeros + 4) * 75;
	for (int i = 0; i < cantidadPasajeros; i++)
	{
		PesoValijas = PesoValijas + ListaPasajeros->getListaPasajeros(i)->getPesoTotalequipaje();
	}
	PesoTotal = PesoValijas + pesopasajeros;
	this->avion->setPesoReaal(PesoTotal);
}