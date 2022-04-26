#include <string>
#include <iostream>
#include "cEquipaje.h"

using namespace std;
int cEquipaje::CantidadEquipajes = 0;
cEquipaje::cEquipaje(float _peso, string _DNIduenio) : DNIduenio(_DNIduenio) 
{
	this->peso = _peso;
	CantidadEquipajes++; // sumo 1 a la cantidad de equipaje
};
cEquipaje::~cEquipaje() 
{
	CantidadEquipajes--; // resto 1 a la cantidad de equipaje
};

