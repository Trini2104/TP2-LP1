#include<iostream>
#include<string>
#include"cAvion.h"
using namespace std;

cAvion::cAvion(const string _ID, const int _CantidadPasajerosPermitidos, int _CantidadActualDePasajeros, const float _PesoMaxTotal, int _cantidad, estado _EstadoVuelo) :ID(_ID), CantidadPasajerosPermitidos(_CantidadPasajerosPermitidos), PesoMaxTotal(_PesoMaxTotal) //preguntar a julieta sobre el constructor
{
	
};
float cAvion::PesoDelAvion()
{
	float PesosPasajeros=0;
	float PesoEquipaje = 0;



	float contador = PesosPasajeros + PesoEquipaje;
	return contador;
}
