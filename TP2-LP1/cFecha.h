#pragma once
#include <iostream>
#include <string>
#include "Enums.h"
using namespace std;

class cFecha
{
public:
	int diaDespegue, diaLlegada, horaDespegue, horaLlegada;
	int mesDespegue, mesLlegada;
	int anioDespegue, anioLlegada;
	estadoHorario estado;//demora, e horario
	friend class cListaVuelos;
	cFecha(int _diaDespegue, int _diaLlegada, int _horaDespegue, int _horaLlegada, int _mesDespegue, int _mesLlegada, int _anioDespegue, int _anioLlegada, estadoHorario _horario);
	~cFecha();
	void setestadohorario(estadoHorario(estado))
	{
		this->estado = estado;
	}
	estadoHorario getEstadoFecha()
	{
		return estado;
	}

};