#include <string>
#include <iostream>
#include "cEquipaje.h"

using namespace std;


cEquipaje::cEquipaje(float _peso, string _DNIduenio) : DNIduenio(_DNIduenio) {};
cEquipaje::~cEquipaje() {};

int cEquipaje::CantidadEquipajes = 0;
