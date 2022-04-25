#include <string>
#include <iostream>
#include "cPasajero.h"

#define MAX 20
using namespace std;

int main()
{
	//PROBAMOS EL TRABAJO 
	// sistema para el control y cálculo de cargas en cada vuelo.
	cEquipaje* EquipajeAgregar = new cEquipaje(5, "123456");
	cListaEquipaje* ListaEquipajePrimerPasajero = new cListaEquipaje(MAX);
	cFecha* FechayHoraDelPrimerPasajero = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHoario);
	cPasajero* PrimerPasajero = new cPasajero("123456", "Juan", "Perez", "0", "1");

	//Probamos agragar equipaje
	//probamos asociar equipaje
	PrimerPasajero->asociarListaEquipaje(ListaEquipajePrimerPasajero);
	//bool cPasajero::AgregarEquipaje(EquipajeAgregar);




}