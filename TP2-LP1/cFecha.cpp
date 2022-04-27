#include <string>
#include <iostream>
#include "cFecha.h"

using namespace std;


cFecha::cFecha(int _diaDespegue, int _diaLlegada, int _horaDespegue, int _horaLlegada, int _mesDespegue, int _mesLlegada, int _anioDespegue, int _anioLlegada, estadoHorario _horario) 
{
	this->anioDespegue = _anioDespegue;
	this->anioLlegada = _anioLlegada;
	this->diaDespegue = _diaDespegue;
	this->diaLlegada = _diaLlegada;
	this->estado = _horario;
	this->horaDespegue = _horaDespegue;
	this->horaLlegada = _horaLlegada;
	this->mesDespegue = _mesDespegue;
	this->mesLlegada = _mesLlegada;

};
cFecha::~cFecha() {};

