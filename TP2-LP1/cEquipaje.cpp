#include <string>
#include <iostream>
#include "cEquipaje.h"

using namespace std;


cEquipaje::cEquipaje(float _peso, string _DNIduenio) : DNIduenio(_DNIduenio) 
{
	this->peso = _peso;
};
cEquipaje::~cEquipaje() {};

int cEquipaje::CantidadEquipajes = 0;
