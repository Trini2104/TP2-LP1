#pragma once
#include <iostream>
#include <string>
using namespace std;

class cFecha
{
public:
	int diaDespegue, diaLlegada, horaDespegue, horaLlegada;
	int mesDespegue, diaLlegada;
	int anioDespegue, anioLlegada;

	
	cFecha(int _diaDespegue, int _diaLlegada, int _horaDespegue, int _horaLlegada, int _mesDespegue, int _mesLlegada, int _anioDespegue, int _anioLlegada);
	~cFecha();

};