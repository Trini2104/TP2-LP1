#include<iostream>
#include<string>
#include "Listas.h"
using namespace std;
/*cListaVuelos::cListaVuelos(unsigned int longitud, bool eliminar)
{
	this->eliminarNodos = eliminar;
	this->ListaVuelos = new cVuelo * [longitud];
	cVuelo::setCantidadVuelos(longitud);
	for (unsigned int i = 0; i < cVuelo::get_ct(); i++)
		this->ListaVuelos[i] = NULL;
};
cListaVuelos::~cListaVuelos()
{

}*/
cListaPasajeros::cListaPasajeros(unsigned int longitud)
{
	capacidad = longitud;
	this->ListaPasajeros = new cPasajero * [longitud];
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaPasajeros[i] = NULL;

	ocupados = 0;
};


void cListaPasajeros::ordenar()
{
	for (int i = 0; i < capacidad; i++)
	{
		for (int j = 0; j < capacidad - 1; j++)
		{
			if (this->ListaPasajeros[j] == NULL)
			{
				cPasajero* aux = this->ListaPasajeros[j];
				this->ListaPasajeros[j] = this->ListaPasajeros[j + 1];
				this->ListaPasajeros[j + 1] = aux;
			}
		}
	}
}

 bool cListaPasajeros::AgregarPasajero(cPasajero* _pasajero)
{
	 if (ocupados >= capacidad)
	 {
		return false;
	 }//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos falsos
	 this->ListaPasajeros[ocupados] = _pasajero;
	 ocupados++;
	 return true;
}
 void cListaPasajeros::CambiarPasajero( string _DNIPasajero, cPasajero* PasajeroNuevo)
 {
	 for (int i = 0; i < capacidad; i++)
	 {
		 if (this->ListaPasajeros == NULL && this->ListaPasajeros[i]->getDNI() == _DNIPasajero)
		 {
			 cPasajero* aux = ListaPasajeros[i];
			 ListaPasajeros[i] = PasajeroNuevo;
			 delete aux;
		 }
	 }
	
 }
 bool cListaPasajeros::EliminarPasajero(string _DNIPasajero)
 {
	 for (int i = 0; i < capacidad; i++)
	 {
		 if (this->ListaPasajeros == NULL && this->ListaPasajeros[i]->getDNI() == _DNIPasajero)
		 {
			 delete this->ListaPasajeros[i];
			 ListaPasajeros[i] = NULL;

			 ordenar();
			 return true;
		 }
		 else return false;
	 }
	
 };

