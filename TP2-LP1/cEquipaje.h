#pragma once
#include <iostream>
#include <string>
using namespace std;
class cEquipaje
{
private:
	int cant = 0;
	float peso = 0;
	const string DNIduenio; // asociamos el equipaje por dni
public:
	cEquipaje(int _cant, int _peso, const string _DNIdueño)
	{
		cant++; // sumo 1 a la cantidad de equipaje
	} // constructor
	~cEquipaje() 
	{
		cant--;
	}; // destructor
	 // getters y setters
	int getCantidadDeEquipaje()
	{
		return cant;
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