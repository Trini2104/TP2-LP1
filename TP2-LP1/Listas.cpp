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
/*cListaPasajeros::cListaPasajeros(int longitud, bool eliminar)
{
	longitud = getCantidadPasajero();
	this->ListaPasajeros = new cPasajero * [longitud];
	
	for (unsigned int i = 0; i < longitud; i++)
		this->ListaPasajeros[i] = NULL;
};
*/

 bool cListaPasajeros::AgregarPasajero()
{
	 if (cAvion::getCantidadActualDePasajeros() >= cAvion::getCantidadPasajerosPermitidos())
	 {

	 }//si la cantidad de pasajeros es mayor a la cantidad de pasajeros permitidos falsos

}