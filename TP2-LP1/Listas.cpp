#include<iostream>
#include<string>
#include "Listas.h"
using namespace std;

cListaVuelos::cListaVuelos(unsigned int longitud)
{
	capacidad = longitud;
	this->ListaVuelos = new cVuelo * [longitud];
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaVuelos[i] = NULL;
	ocupados = 0;
};
bool cListaVuelos::AgregarVuelo(cVuelo* _vuelo)
{
	if (ocupados >= capacidad)
	{
		return false;
	}//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos falsos
	this->ListaVuelos[ocupados] = _vuelo;
	ocupados++;
	return true;
}
cListaVuelos::~cListaVuelos()
{
	for (int i = 0; i < capacidad; i++)
	{
		if (this->ListaVuelos[i] != NULL)
			delete ListaVuelos[i];
	}
	delete[]this->ListaVuelos;
	capacidad = 0;
}
cListaPasajeros::cListaPasajeros(unsigned int longitud)
{
	capacidad = longitud;
	this->ListaPasajeros = new cPasajero * [longitud];
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaPasajeros[i] = NULL;

	ocupados = 0;
};
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
	 if (this->ListaPasajeros != NULL)
	 {
		 for (int i = 0; i < capacidad; i++)
		 {
			 if (this->ListaPasajeros[i] != NULL && this->ListaPasajeros[i]->getDNI() == _DNIPasajero)
			 {
				 delete this->ListaPasajeros[i];
				 ListaPasajeros[i] = NULL;

				 ordenar();
				 return true;
			 }
			 else return false;
		 }
	 }
	
 };
 cListaPasajeros::~cListaPasajeros()
 {
	 for (int i = 0; i < capacidad; i++)
	 {
		 if (this->ListaPasajeros[i] != NULL)
			 delete this->ListaPasajeros[i];
	 }
	 delete[]this->ListaPasajeros;
	 capacidad = 0;
 }
 cListaAviones::cListaAviones(unsigned int longitud)
 {
	 capacidad = longitud;
	 this->ListaAviones = new cAvion * [longitud];
	 for (unsigned int i = 0; i < longitud; i++)
		 this->ListaAviones[i] = NULL;
	 ocupados = 0;
 };
 bool cListaAviones::AgregarAvion(cAvion* _avion)
 {
	 if (ocupados >= capacidad)
	 {
		 return false;
	 }//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos falsos
	 this->ListaAviones[ocupados] = _avion;
	 ocupados++;
	 return true;
 }
 cListaAviones::~cListaAviones()
 {
	 for (int i = 0; i < capacidad; i++)
	 {
		 if (this->ListaAviones[i] != NULL)
			 delete ListaAviones[i];
	 }
	 delete[]this->ListaAviones;
	 capacidad = 0;
 }
 cListaEquipaje::cListaEquipaje(unsigned int longitud)
 {
	 capacidad = longitud;
	 this->ListaEquipaje = new cEquipaje * [longitud];
	 for (unsigned int i = 0; i < longitud; i++)
		 this->ListaEquipaje[i] = NULL;
	 ocupados = 0;
 }
 bool cListaEquipaje::AgregarEquipaje(cEquipaje* _equipaje)
 {
	 if (ocupados >= capacidad)
		 return false;
	 this->ListaEquipaje[ocupados] = _equipaje;
	 ocupados++;
	 return true;
	 
 }
 bool cListaEquipaje::EliminarEquipaje(const string _DNIduenio)
 {
	 if (this->ListaEquipaje != NULL)
	 {
		 for (int i = 0; i < capacidad; i++)
		 {
			 if (this->ListaEquipaje[i] != NULL && this->ListaEquipaje[i]->getDNIduenio() == _DNIduenio)
			 {
				 delete this->ListaEquipaje[i];
				 ListaEquipaje[i] = NULL;

				 ordenar();
				 return true;
			 }
			 else return false;
		 }
	 }
 }
 void cListaEquipaje::ordenar()
 {//quita espacios en blanco en la lista
	 for (int i = 0; i < capacidad; i++)
	 {
		 int cont = 0;
		 for (int j = 0; j < capacidad - 1; j++)
		 {
			 if (this->ListaEquipaje[j] == NULL)
			 {
				 cEquipaje* aux = this->ListaEquipaje[j];
				 this->ListaEquipaje[j] = this->ListaEquipaje[j + 1];
				 this->ListaEquipaje[j + 1] = aux;
				 cont++;
			 }
		 }if (cont == 0)
			 break;
	 }
 }
 cListaEquipaje::~cListaEquipaje()
 {
	 for (int i = 0; i < capacidad; i++)
	 {
		 if (this->ListaEquipaje[i] != NULL)
			 delete ListaEquipaje[i];
	 }
	 delete[]this->ListaEquipaje;
	 capacidad = 0;
 }
