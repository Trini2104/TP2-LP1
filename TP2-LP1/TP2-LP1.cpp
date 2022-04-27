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
	//CREO PASAJEROS PARA PROBAR QUE TODO FUNCIONE
	cPasajero* Pasajero1 = new cPasajero("123456", "Juan", "Perez", "0", "1");
	cEquipaje* EquipajePasajero1 = new cEquipaje(10, "123456");
	cEquipaje* EquipajePasajero1plus = new cEquipaje(5.6, "123456");
	cFecha* FechayHoraDelPasajero1 = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHorario);
	Pasajero1->asignarFechaYHoraVuelo(FechayHoraDelPasajero1);
	Pasajero1->asignarequipaje(EquipajePasajero1);
	cListaEquipaje* ListaEquipajePasajero1 = new cListaEquipaje(MAX);
	ListaEquipajePasajero1->AgregarEquipaje(EquipajePasajero1);
	Pasajero1->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero1);
	//PRUEBA DE PASAJEROS
	/*Pasajero1->AgregarEquipajePasajero(EquipajePasajero1plus);
	Pasajero1->EliminarEquipajePasajero(EquipajePasajero1plus);*/

	cPasajero* Pasajero2 = new cPasajero("22154365", "Ana", "Pedrites", "270", "67");
	cEquipaje* EquipajePasajero2 = new cEquipaje(15,"22154365");
	cListaEquipaje* ListaEquipajePasajero2 = new cListaEquipaje(MAX);
	ListaEquipajePasajero2->AgregarEquipaje(EquipajePasajero2);
	cFecha* FechayHoraDelPasajero2 = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHorario);
	Pasajero2->asignarFechaYHoraVuelo(FechayHoraDelPasajero2);
	Pasajero2->asignarequipaje(EquipajePasajero2);
	Pasajero2->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero2);

	cPasajero* Pasajero3 = new cPasajero("43221872", "Pedro", "Martinez", "345", "23");
	cEquipaje* EquipajePasajero3 = new cEquipaje(10, "43221872");
	Pasajero3->asignarequipaje(EquipajePasajero3);
	cListaEquipaje* ListaEquipajePasajero3 = new cListaEquipaje(MAX);
	ListaEquipajePasajero3->AgregarEquipaje(EquipajePasajero3);
	cFecha* FechayHoraDelPasajero3 = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHorario);
	Pasajero3->asignarFechaYHoraVuelo(FechayHoraDelPasajero3);
	Pasajero3->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero3);

	cPasajero* Pasajero4 = new cPasajero("1872", "Matias", "Lopez", "785", "12");
	cEquipaje* EquipajePasajero4 = new cEquipaje(20, "1872");
	Pasajero4->asignarequipaje(EquipajePasajero4);
	cListaEquipaje* ListaEquipajePasajero4 = new cListaEquipaje(MAX);
	ListaEquipajePasajero4->AgregarEquipaje(EquipajePasajero4);
	cFecha* fechayhoraDelPasajero4 = new cFecha(21, 22, 2315, 1025, 5, 5, 2023, 2023, EnHorario);
	Pasajero4->asignarFechaYHoraVuelo(fechayhoraDelPasajero4);
	Pasajero4->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero4);

	cPasajero* Pasajero5 = new cPasajero("9962", "Paula", "Gomez", "512", "2");
	cEquipaje* EquipajePasajero5 = new cEquipaje(21.5, "9962");
	Pasajero5->asignarequipaje(EquipajePasajero5);
	cListaEquipaje* ListaEquipajePasajero5 = new cListaEquipaje(MAX);
	ListaEquipajePasajero5->AgregarEquipaje(EquipajePasajero5);
	cFecha* fechayhoraDelPasajero5 = new cFecha(21, 22, 2315, 1025, 5, 5, 2023, 2023, EnHorario);
	Pasajero5->asignarFechaYHoraVuelo(fechayhoraDelPasajero5);
	Pasajero5->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero5);

	cPasajero* Pasajero6 = new cPasajero("42888", "Maria", "Gimenez", "455", "3");
	cEquipaje* EquipajePasajero6 = new cEquipaje(8.9, "42888");
	Pasajero6->asignarequipaje(EquipajePasajero6);
	cListaEquipaje* ListaEquipajePasajero6 = new cListaEquipaje(MAX);
	ListaEquipajePasajero6->AgregarEquipaje(EquipajePasajero6);
	cFecha* fechayhoraDelPasajero6 = new cFecha(21, 22, 2315, 1025, 5, 5, 2023, 2023, EnHorario);
	Pasajero6->asignarFechaYHoraVuelo(fechayhoraDelPasajero6);
	Pasajero6->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero6);

	cPasajero* Pasajero7 = new cPasajero("5524858", "Camila", "Liaudat", "378", "27");
	cEquipaje* EquipajePasajero7 = new cEquipaje(5.6, "5524858");
	Pasajero7->asignarequipaje(EquipajePasajero7);
	cListaEquipaje* ListaEquipajePasajero7 = new cListaEquipaje(MAX);
	ListaEquipajePasajero7->AgregarEquipaje(EquipajePasajero7);
	cFecha* fechayhoraDelPasajero7 = new cFecha(30, 30, 800, 1545, 4, 4, 2022, 2022, ConDemora);
	Pasajero7->asignarFechaYHoraVuelo(fechayhoraDelPasajero7);
	Pasajero7->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero7);

	cPasajero* Pasajero8= new cPasajero("488348", "Jose", "Moreno", "510", "58");
	cEquipaje* EquipajePasajero8 = new cEquipaje(5.6, "488348");
	Pasajero8->asignarequipaje(EquipajePasajero8);
	cListaEquipaje* ListaEquipajePasajero8 = new cListaEquipaje(MAX);
	ListaEquipajePasajero8->AgregarEquipaje(EquipajePasajero8);
	cFecha* fechayhoraDelPasajero8 = new cFecha(30, 30, 800, 1545, 4, 4, 2022, 2022, ConDemora);
	Pasajero8->asignarFechaYHoraVuelo(fechayhoraDelPasajero8);
	Pasajero8->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero8);

	cPasajero* Pasajero9 = new cPasajero("43272", "Lola", "Suarez", "78", "66");
	cEquipaje* EquipajePasajero9 = new cEquipaje(12.2, "43272");
	Pasajero9->asignarequipaje(EquipajePasajero9);
	cListaEquipaje* ListaEquipajePasajero9 = new cListaEquipaje(MAX);
	ListaEquipajePasajero9->AgregarEquipaje(EquipajePasajero9);
	cFecha* fechayhoraDelPasajero9 = new cFecha(30, 30, 800, 1545, 4, 4, 2022, 2022, ConDemora);
	Pasajero9->asignarFechaYHoraVuelo(fechayhoraDelPasajero9);
	Pasajero9->AsignarListaEquipajeDelPasajero(ListaEquipajePasajero9);

	//CREO VUELOS Y AVIONES 
	cAvion* avion1 = new cAvion("AV55", 70, 68, 1750.6, 2500,2, Despegando);
	cAvion* avion2 = new cAvion("AV299", 75, 60, 2500, 1540.6, 2, Aterrizando);
	cAvion* avion3 = new cAvion("AV3665", 55, 55, 2500, 1950.6, 2, PidiendoPermisoParaAterrizar);
	cAvion* avion4 = new cAvion("AV4885", 80, 48, 2500, 1110.6, 2, PidiendoPermisoParaDespegar);
	cVuelo* vuelo1 = new cVuelo("VU1", Despegando, Arribo, Iguazu);
	cVuelo* vuelo2 = new cVuelo("VU2", Aterrizando, Arribo, MarDelPlata);
	cVuelo* vuelo3 = new cVuelo("VU3", PidiendoPermisoParaAterrizar, Partida, Salta);

	 // CREO LISTAS Y EL AEROPUERTO
	cListaAviones* ListaDeAviones = new cListaAviones(MAX);
	cListaVuelos* ListaDeVuelos = new cListaVuelos(MAX);
	cListaEquipaje* ListaEquipajeDelVuelo1 = new cListaEquipaje(MAX);
	cListaEquipaje* ListaEquipajeDelVuelo2 = new cListaEquipaje(MAX);
	cListaEquipaje* ListaEquipajeDelVuelo3 = new cListaEquipaje(MAX);
	cListaPasajeros* ListaDePasajeros = new cListaPasajeros(MAX);
	cListaPasajeros* ListaDePasajeros2 = new cListaPasajeros(MAX);
	cListaPasajeros* ListaDePasajeros3 = new cListaPasajeros(MAX);
	cAeropuerto* aeroparque = new cAeropuerto("AE58961565", 0);

	//ASIGNACIONES PARA EL AEROPUERTO
	ListaDeAviones->AgregarAvion(avion1);
	ListaDeAviones->AgregarAvion(avion2);
	ListaDeAviones->AgregarAvion(avion3);
	ListaDeAviones->AgregarAvion(avion4);
	aeroparque->AsignarListaAviones(ListaDeAviones);
	
	ListaDeVuelos->AgregarVuelo(vuelo1);
	ListaDeVuelos->AgregarVuelo(vuelo2);
	ListaDeVuelos->AgregarVuelo(vuelo3);
	aeroparque->AsignarListaVuelos(ListaDeVuelos);

	// ASIGNACIONES PARA LOS VUELOS
	ListaDePasajeros->AgregarPasajero(Pasajero1);
	ListaDePasajeros->AgregarPasajero(Pasajero2);
	ListaDePasajeros->AgregarPasajero(Pasajero3);

	ListaDePasajeros2->AgregarPasajero(Pasajero4);
	ListaDePasajeros2->AgregarPasajero(Pasajero5);
	ListaDePasajeros2->AgregarPasajero(Pasajero6);
		
	ListaDePasajeros3->AgregarPasajero(Pasajero7);
	ListaDePasajeros3->AgregarPasajero(Pasajero8);
	ListaDePasajeros3->AgregarPasajero(Pasajero9);

	ListaEquipajeDelVuelo1->AgregarEquipaje(EquipajePasajero1);
	ListaEquipajeDelVuelo1->AgregarEquipaje(EquipajePasajero2);
	ListaEquipajeDelVuelo1->AgregarEquipaje(EquipajePasajero3);
	cFecha* fechayhoravuelo1 = new cFecha(24, 24, 7, 1, 4, 4, 2022, 2022, EnHorario);
	vuelo1->AsignarListaEquipajeDelVuelo(ListaEquipajeDelVuelo1);
	vuelo1->AsignarListaPasajeros(ListaDePasajeros);
	vuelo1->asociarAvionConVuelo(avion1);
	vuelo1->AsignarFechaYhora(fechayhoravuelo1);

	ListaEquipajeDelVuelo2->AgregarEquipaje(EquipajePasajero4);
	ListaEquipajeDelVuelo2->AgregarEquipaje(EquipajePasajero5);
	ListaEquipajeDelVuelo2->AgregarEquipaje(EquipajePasajero6);
	cFecha* fechayhoravuelo2 = new cFecha(21, 22, 2315, 1025, 5, 5, 2023, 2023, EnHorario);
	vuelo2->AsignarListaEquipajeDelVuelo(ListaEquipajeDelVuelo2);
    vuelo2->AsignarListaPasajeros(ListaDePasajeros2);
	vuelo2->asociarAvionConVuelo(avion2);
	vuelo2->AsignarFechaYhora(fechayhoravuelo2);

	ListaEquipajeDelVuelo3->AgregarEquipaje(EquipajePasajero7);
	ListaEquipajeDelVuelo3->AgregarEquipaje(EquipajePasajero8);
	ListaEquipajeDelVuelo3->AgregarEquipaje(EquipajePasajero9);
	cFecha* fechayhoravuelo3 = new cFecha(30, 30, 800, 1545, 4, 4, 2022, 2022, ConDemora);
	vuelo3->AsignarListaEquipajeDelVuelo(ListaEquipajeDelVuelo3);
    vuelo3->AsignarListaPasajeros(ListaDePasajeros3);
	vuelo3->asociarAvionConVuelo(avion3);
	vuelo3->AsignarFechaYhora(fechayhoravuelo3);

	//PRUEBA DE AEROPUERTO TODO OK
	//aeroparque->DarPermiso(avion1); 
	//aeroparque->Aterrizaje(avion3); funciona :)
	//aeroparque->Despegue(avion1);
	//aeroparque->CantidadDeVuelosAterrizadosXDia();
	//cout << " cantidad de vuelos aterrizados por dia: " << aeroparque->CantidadDeVuelosAterrizadosXDia() << endl;
	//cout << " vuelos despegados en el dia:" << aeroparque->CantidadDeVuelosDespegadosXDia() << endl;
	//cout << " porcentaje de vuelos a horario:" << aeroparque->PorcentajeDeVuelosEnHorario() << endl;
	//aeroparque->CantidadTotalDePasajerosXDia(); funciona:)
	
	//PROBAMOS VUELO
	//cout << " " << vuelo1->ObtenerDatosPasajero(Pasajero1->getDNI()) << endl; FUNCIONA :)
	//vuelo1->AgregarPasajeroAlVuelo(Pasajero8); FUNCIONA :)
	//vuelo1->CambiarPasajeroAlVuelo(Pasajero1, Pasajero6); FUNCIONA :)
	//vuelo1->EliminarPasajeroAlVuelo(Pasajero2);FUNCIONA :)
	//vuelo1->pesototaldelvuelo(); // FUNCIONA :)

	//PROBAMOS AVION
	//avion1->ChequearCargaMaxima();
	//avion1->AntesDeSalirDelAeropuerto(); FUNCIONA
	//avion2->Despegar(); FUNCIONA
	//avion1->imprimir();

}