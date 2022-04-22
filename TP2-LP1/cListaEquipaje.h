#pragma once
#include <iostream>
#include <string>
#include "cEquipaje.h"
#define MAX 20
class cListaEquipaje
{
private:
	cEquipaje** ListaEquipaje;
	unsigned int ocupados;
	unsigned int capacidad;
public:
	cListaEquipaje(unsigned int longitud = MAX);
	bool AgregarEquipaje(cEquipaje* _equipaje);
	bool EliminarEquipaje(const string _DNIduenio);
	void ordenar();
	~cListaEquipaje();

};