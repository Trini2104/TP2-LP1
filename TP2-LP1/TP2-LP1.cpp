#include <string>
#include <iostream>
#include "cPasajero.h"
#include "cAeropuerto.h"
#include "cAvion.h"
#include "cEquipaje.h"
#include "cFecha.h"
#include "cVuelo.h"
#define MAX 20
using namespace std;

int main()
{
	//PROBAMOS EL TRABAJO 
	// sistema para el control y cálculo de cargas en cada vuelo.
	//declaramos variables a utilizar
	cEquipaje* EquipajeAgregar = new cEquipaje(5, "123456");
	cListaEquipaje* ListaEquipajePasajero1 = new cListaEquipaje(MAX);
	cListaEquipaje* ListaEquipajePasajero2 = new cListaEquipaje(MAX);
	cListaEquipaje* ListaEquipajePasajero3 = new cListaEquipaje(MAX);
	cFecha* FechayHoraDelPasajero1 = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHoario);
	cPasajero* Pasajero1 = new cPasajero("123456", "Juan", "Perez", "0", "1");
	cPasajero* Pasajero2 = new cPasajero("22154365", "Ana", "Pedrites", "270", "67");
	cPasajero* Pasajero3 = new cPasajero("43221872", "Pedro", "Martinez", "345", "23");
	cAvion* avion1 = new cAvion("AV55", 70, 68, 2500,1750.6,2, Despegando);
	cAvion* avion2 = new cAvion("AV299", 75, 60, 2500, 1540.6, 2, Aterrizando);
	cAvion* avion3 = new cAvion("AV3665", 55, 55, 2500, 1950.6, 2, PidiendoPermisoParaAterrizar);
	cAvion* avion4 = new cAvion("AV4885", 80, 48, 2500, 1110.6, 2, PidiendoPermisoParaDespegar);
	cVuelo* vuelo1 = new cVuelo("VU1", Despegando, Arribo, Iguazu);
	cVuelo* vuelo2 = new cVuelo("VU2", Aterrizando, Arribo, MarDelPlata);
	cVuelo* vuelo3 = new cVuelo("VU3", PidiendoPermisoParaAterrizar, Partida, Salta);
	cVuelo* vuelo4 = new cVuelo("VU4", PidiendoPermisoParaDespegar, Partida, Bariloche);
	cListaAviones* ListaDeAviones = new cListaAviones(MAX);
	cListaVuelos* ListaDeVuelos = new cListaVuelos(MAX);
	cListaPasajeros* ListaDePasajeros = new cListaPasajeros(MAX);
	cAeropuerto* aeroparque = new cAeropuerto("AE58961565", 96);
	//creo que deberiamos hacer funciones que asignen el avion al aeroparque, y el vuelo al avion

	//probamos dar permiso
	ListaDeAviones->AgregarAvion(avion1);
	ListaDeAviones->AgregarAvion(avion2);
	ListaDeAviones->AgregarAvion(avion3);
	ListaDeAviones->AgregarAvion(avion4);
	aeroparque->AsignarListaAviones(ListaDeAviones);
	//aeroparque->DarPermiso(avion1); funciona :)
	//aeroparque->Aterrizaje(avion3); funciona :)
	//aeroparque->Despegue(avion1);
	ListaDeVuelos->AgregarVuelo(vuelo1);
	ListaDeVuelos->AgregarVuelo(vuelo2);
	ListaDeVuelos->AgregarVuelo(vuelo3);
	ListaDeVuelos->AgregarVuelo(vuelo4);
	aeroparque->AsignarListaVuelos(ListaDeVuelos);
	//aeroparque->CantidadDeVuelosAterrizadosXDia();
	//cout << " cantidad de vuelos aterrizados por dia: " << aeroparque->CantidadDeVuelosAterrizadosXDia() << endl;
	//cout << " vuelos despegados en el dia:" << aeroparque->CantidadDeVuelosDespegadosXDia() << endl;
	cout << " porcentaje de vuelos a horario:" << aeroparque->PorcentajeDeVuelosEnHorario() << endl;

	ListaDePasajeros->AgregarPasajero(Pasajero1);
	ListaDePasajeros->AgregarPasajero(Pasajero2);
	ListaDePasajeros->AgregarPasajero(Pasajero3);
}