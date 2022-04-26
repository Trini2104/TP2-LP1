#pragma once
class cAvion;
#include "cListaPasajeros.h"
#include <iostream>
#include <string>
using namespace std;

class cVuelo
{
private:
	string  NumVuelo; //propio
	estado EstadoVuelo; //esta en enum
	cAvion* avion;//en el que se lleva ese vuelo
	tipovuelo TipoVuelo;//partida o arribo
	cFecha* fechayhoraReal; //fecha y hora con la que llego y salió realmente
	destinos aeropuertoDestino; // enum destinos
	cListaPasajeros* ListaPasajeros;//pasajeros del vuelo
	static int CantidadVuelos;
	cListaEquipaje* ListaEquipajeVuelo;//equipaje del vuelo
	friend class cListaVuelos;
public:
	cVuelo(string _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, destinos _aeropuertoDestino);//agregar todos los punteros
	~cVuelo();
	void setEstadoFecha(estado _estado)
	{
		if (_estado == RecibiendoPermisoParaAterrizar || _estado == RecibiendoPermisoParaDespegar) //si pudo despegar 
		{
			fechayhoraReal->setestadohorario(EnHoario); //se encuentra en horario
		}
		if (_estado == NoRecibiendoPermisoParaAterrizar || _estado == NoRecibiendoPermisoParaDespegar) //si no pudo
		{
			fechayhoraReal->setestadohorario(ConDemora); //se encuentra con demora
		}
	}
	estadoHorario getEstadoFecha()
	{
		return fechayhoraReal->estado;
	}
	bool AgregarPasajeroAlVuelo(cPasajero*_pasajero);
	bool CambiarPasajeroAlVuelo(cPasajero*_pasajero, cPasajero* _pasajerocambio);
	bool EliminarPasajeroAlVuelo(cPasajero* _pasajero);
	void setCantidadVuelos(int longitud)
	{
		this->CantidadVuelos = longitud;
	}
	void NumeroDeVueloRandom(); //genero un numero de vuelo de letras y numeros
	void  setNumeroVuelo(string _numVuelo)
	{
		this->NumVuelo = _numVuelo;
	};
	cListaPasajeros* getlistapasajeros()
	{
		return ListaPasajeros;
	}
	string ObtenerDatosPasajero(const string _DNI);//busca a un pasajero por su dni y obtiene sus datos
	float setpesototal();//devuelve el peso total con un contador de las valijas del pasajero y cada pasajero
	void pesototaldelvuelo();
	float setEstadoVuelo()
	{
		EstadoVuelo = avion->getEstadoVuelo();
	}
	estado getEstadoVuelo()
	{
		return EstadoVuelo;
	}
	friend ostream &operator<<(ostream& out, cVuelo* vuelo);
	string to_string();
	void imprimir();
};