#pragma once
#include <iostream>
#include <string>
using namespace std;

enum estado { Despegando, Aterrizando, PidiendoPermisoParaAterrizar, PidiendoPermisoParaDespegar, RecibiendoPermisoParaAterrizar, RecibiendoPermisoParaDespegar,NoRecibiendoPermisoParaAterrizar, NoRecibiendoPermisoParaDespegar,Nodespega};
enum tipovuelo {Partida, Arribo};
enum destinos { Iguazu, Cordoba, MarDelPlata, Bariloche, Ushuaia, Salta };
enum estadoHorario { EnHoario, ConDemora};