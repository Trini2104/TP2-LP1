#include<iostream>
#include<string>
#include"cAeropuerto.h"

using namespace std;
cAeropuerto::cAeropuerto( string _IDAeropuerto, int _CapacidadDeAeropuerto) :IDAeropuerto(_IDAeropuerto), CapacidadDeAeropuerto(_CapacidadDeAeropuerto)
{
	Avion = NULL;
	ListaVuelos = NULL;
	ListaAviones = NULL;
};

cAeropuerto::~cAeropuerto() {};
void cAeropuerto::AsignarListaVuelos(cListaVuelos* _ListaVuelos)
{
	this->ListaVuelos = _ListaVuelos;

}
void cAeropuerto::AsignarListaAviones(cListaAviones* _ListaAviones)
{
	this->ListaAviones = _ListaAviones;
}
void cAeropuerto::DesasociarListaVuelos()
{
	ListaVuelos = NULL;
};
void cAeropuerto::DesasociarListaAviones()
{
	ListaAviones = NULL;
};
bool cAeropuerto::DarPermiso(cAvion* _avion) //dependiendo de la capacidad del aeropuerto da o no permiso
{
	try
	{
		if (ListaAviones->getOcupados() < getCapacidadAeropuerto()) //  si la cantidad de aviones en el hangar es menor a la capacidad del mismo
		{
			_avion->setEstadoVuelo(RecibiendoPermisoParaAterrizar); //da el permiso
			ListaAviones->AgregarAvion(_avion);// agrego el avion a la lista
			_avion->imprimir();
			return true;

		}
		if (ListaAviones->getOcupados() > getCapacidadAeropuerto()) throw " HANGAR LLENO"; // si el hangar se encuentra al tope de su capacidad
		
	}
	catch (const char * msj)
	{
		cout << msj << endl;
		_avion->setEstadoVuelo(NoRecibiendoPermisoParaAterrizar); //no da el permiso
		return false;
	}
}
bool cAeropuerto::Aterrizaje(cAvion* _avion)
{
	if (_avion->getEstadoVuelo() == PidiendoPermisoParaAterrizar) //si su estado es pidiendo permiso para aterrizar
	{
		if (ListaAviones->getOcupados() < getCapacidadAeropuerto())// y el hangar no esta lleno
		{
			ListaAviones->AgregarAvion(_avion); //le permite aterrizar en el aeropuerto y agrega un avion a la lista
			_avion->setEstadoVuelo(Aterrizando); // modifico el estado del vuelo a aterrizado
			return true;
		}
		else return false; // retorno falso si el hangar esta lleno
	}
	else
		return false; // retorno falso si no tiene permiso para aterrizar
}
bool cAeropuerto::Despegue(cAvion* _avion)
{
	if (_avion->getEstadoVuelo() == Despegando) //si el vuelo esta despegando se quita un avion de la lista 
	{
		ListaAviones->EliminarAvion(_avion);
		return true;
	}
	else
	{
		return false;
	}
}
int cAeropuerto::CantidadTotalDePasajerosXDia()
{
	int cantidadvuelos = ListaVuelos->getocupados();
	int contadorPasajerosTotales=0;
	for (int i =0; i < cantidadvuelos; i++)//recorre todos los vuelos 
	{
		contadorPasajerosTotales= contadorPasajerosTotales+ListaVuelos->getListaVuelos(i)->getlistapasajeros()->getocupados(); // suma la cantidad de pasajeros que hay por cada vuelo
	}
	return contadorPasajerosTotales; // retorno la cantidad total
}
int cAeropuerto::CantidadDeVuelosAterrizadosXDia()
{
	int cantAterrizados=0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoVuelo() == Aterrizando) //ingresa a todos los vuelos de la lista, contabiliza los vuelos que estan aterrizando
		{
			cantAterrizados++;
		}
		
	}
	return cantAterrizados;
}
int cAeropuerto::CantidadDeVuelosDespegadosXDia()
{
	int cantDespegues=0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoVuelo() == Despegando) //ingresa a todos los vuelos contabiliza los vuelo que despegan
		{
			cantDespegues++;
		}
	}
	return cantDespegues;
}
float cAeropuerto::PorcentajeDeVuelosEnHorario()
{
	int contadorenhorario = 0;
	int cantidadvuelos = ListaVuelos->getocupados();
	for (int i = 0; i < cantidadvuelos; i++)
	{
		if (ListaVuelos->getListaVuelos(i)->getEstadoFecha() == EnHorario) //ingresa a cada vuelo, si su estado es en horario sumo 1
		{
			contadorenhorario++;
		}
		
	}
	float  porcentajeEnHorario=0;
	porcentajeEnHorario = (contadorenhorario * 100) / (float)cantidadvuelos; //divido la cantidad de vuelos que salieron a horario respecto a la cantidad de vuelos totales que hubo
	return porcentajeEnHorario; // retorno el porcentaje
}
string cAeropuerto::to_string()
{
	return
	"ID del aeropuerto" + IDAeropuerto + "\n"+
	"Capacidad del aeropuerto:" + std::to_string(CapacidadDeAeropuerto) + "\n";
}
void cAeropuerto::imprimir()
{
	cout << this->to_string() << endl;
}
