#include<iostream>
#include<string>
#include"cAvion.h"
using namespace std;

cAvion::cAvion(string _IDAvion, int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, float _PesoMaxTotal, float _pesoreal, int _cantidadaviones, estado _EstadoVuelo) :IDAvion(_IDAvion), CantidadPasajerosPermitidos(_CantidadPasajerosPermitidos), PesoMaxTotal(_PesoMaxTotal)
{
	this->CantidadActualDePasajeros = _CantidadActualDePasajeros;
	this->PesoReal = _pesoreal;
	this->cantidadAviones = _cantidadaviones;
	this->EstadoVuelo = _EstadoVuelo;
	cantidadAviones++;
};
cAvion::~cAvion() {
	cantidadAviones--;
};
int cAvion::cantidadAviones = 0;

/*float cAvion::PesoDelAvion()
{
	float PesosPasajeros = 0;
	float PesoEquipaje = 0;
	float contador = PesosPasajeros + PesoEquipaje;
	return contador;
}*/
void cAvion::setPesoReal(float _peso)
{
	this->PesoReal = _peso;
};
void cAvion::setEstadoVuelo(estado _estadovuelo)
{
	this->EstadoVuelo = _estadovuelo;
}
bool cAvion::ChequearCargaMaxima() 
{
	if (PesoReal < PesoMaxTotal)//si el peso total es menor al maximo puede despegar
	{
		return true;
	}
	else
	{
		//throw new runtime_error(" EL AVION ESTA EXCEDIDO DE PESO"); BUSCAR COMO SE LANZA UNA EXCEPCION
		return false;
	}
}
bool cAvion::AntesDeSalirDelAeropuerto() 
{
	if (ChequearCargaMaxima() == true && getCantidadActualDePasajeros()<=getCantidadPasajerosPermitidos()) //si recibio permiso y si la cantidad actual de pasajeros es menor a la de permitidos
	{
		setEstadoVuelo(RecibiendoPermisoParaDespegar); //puede despegar
		return true;
	}
	else
	{
		setEstadoVuelo(NoRecibiendoPermisoParaDespegar);
		return false;
	}
}
bool cAvion::Despegar() //si tiene permiso despega
{
	if (AntesDeSalirDelAeropuerto() == true)
	{
		setEstadoVuelo(Despegando);
		return true;
	}
	else
	{
		setEstadoVuelo(Nodespega);
	}
}
string cAvion::to_string()
{
	string cantpp = "";
	cantpp= (std::to_string(CantidadPasajerosPermitidos));
	string cantap(std::to_string(CantidadActualDePasajeros));
	string pmtp = (std::to_string(PesoMaxTotal));
	string pada = (std::to_string(PesoReal));
	return
	"ID del avion: " + IDAvion + "\n";
	"Cantidad de pasajeros permitidos:" + cantpp + "\n";
	"Cantidad actual de pasajeros:" +  cantap+ "\n";
	"peso maximo total permitido:" +pmtp + "\n";
	"peso actual del avion:" + pada + "\n";

}
void cAvion::imprimir()
{
	cout << this->to_string() << endl;
}