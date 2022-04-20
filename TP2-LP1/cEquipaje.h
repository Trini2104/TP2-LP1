#pragma once
#include <iostream>
#include <string>
using namespace std;
class cEquipaje
{
private:
	int cant;
	float peso;
	const string DNIdue�o; // asociamos el equipaje por dni
public:
	cEquipaje(int _cant, int _peso, const string _DNIdue�o)
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
};