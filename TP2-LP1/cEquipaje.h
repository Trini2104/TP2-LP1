#pragma once
#include <iostream>
#include <string>
using namespace std;
class cEquipaje
{
private:
	static int CantidadEquipajes;
	float peso = 0;
	const string DNIduenio; // asociamos el equipaje por dni
	friend class cListaEquipaje;
public:
	cEquipaje(float _peso, string _DNIduenio)
	{
		CantidadEquipajes++; // sumo 1 a la cantidad de equipaje
	} // constructor
	~cEquipaje()
	{
		CantidadEquipajes--;
	}; // destructor
	 // getters y setters
	int getCantidadDeEquipaje()
	{
		return CantidadEquipajes;
	};
	float getPesoDelEquipaje()
	{
		return peso;
	};
	const string getDNIduenio()
	{
		return DNIduenio;
	}

};