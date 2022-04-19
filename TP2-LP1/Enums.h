#pragma once
#include <iostream>
#include <string>
using namespace std;

enum estado { Despegando, Aterrizando, PidiendoPermisoParaAterrizar, PidiendoPermisoParaDespegar, RecibiendoPermisoParaAterrizar, RecibiendoPermisoParaDespegar };
enum tipovuelo {Partida, Arribo};