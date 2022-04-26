#pragma once
#include <iostream>
#include <string>
using namespace std;
class cEquipaje
{
private:
	static int CantidadEquipajes;
	float peso;
	const string DNIduenio; // asociamos el equipaje por dni
	friend class cListaEquipaje;
public:
	cEquipaje(float _peso, string _DNIduenio);
	~cEquipaje();
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