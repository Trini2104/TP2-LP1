#include<iostream>
#include<string>
#include "cVuelo.h"
using namespace std;
using std::cout; using std::cin;
using std::endl; using std::string;
cVuelo::cVuelo(string _numVuelo, estado _EstadoVuelo, tipovuelo _TipoVuelo, destinos _aeropuertoDestino)
{
	this->NumVuelo = _numVuelo;
	this->EstadoVuelo = _EstadoVuelo;
	this->TipoVuelo = _TipoVuelo;
	this->aeropuertoDestino = _aeropuertoDestino;
	avion = NULL;
	fechayhoraReal = NULL;
	ListaPasajeros = NULL;
	ListaEquipajeVuelo = NULL;
	CantidadVuelos++;
}
cVuelo::~cVuelo() {
	CantidadVuelos--;
};
int cVuelo::CantidadVuelos = 0;
string cVuelo::ObtenerDatosPasajero(const string _DNIPasajero) 
{
	string  datospasajero;
	int cant;
	float peso;
	for (int i = 0; i < ListaPasajeros->getocupados(); i++)
	{
		if ((*ListaPasajeros)[i]!= NULL && (*ListaPasajeros)[i]->getDNI() == _DNIPasajero) //ingresa a cada pasajero de la lista y busca al pasajero por su dni
		{
			cant = (*ListaPasajeros)[i]->getEquipaje(); // le asigno a cant la cantidad de equipaje que tiene ese pasajero sub i
			peso = +(*ListaPasajeros)[i]->getPesoTotalequipaje();
			datospasajero += " PASAJERO: "+ (*ListaPasajeros)[i]->getnombre() + " " + (*ListaPasajeros)[i]->getapellido() + " DNI: " + (*ListaPasajeros)[i]->getDNI() + " CANTIDAD DE EQUIPAJE: " + std::to_string(cant) + " PESO DEL EQUIPAJE: " + std::to_string(peso);
			return datospasajero;//si encuentra al pasajero por su dni guarda todos sus datos en un string
		}
		else
		{
			throw  new runtime_error(" no se encuentra el pasajero solicitado");
		}
		
	}
	
}
void cVuelo::NumeroDeVueloRandom()
{
	int numero1, numeroletras;
	numeroletras = 'A' + (rand() % 26);  //genero letras random
	numero1 = rand() % 9999; //genero numeros random
	string numVuelo;
	numVuelo += numeroletras + numero1; //concateno todo para generar un numero de vuelo de numero s y letras
	this->setNumeroVuelo(numVuelo); //ingreso el numero random a mi variable

};
bool cVuelo::AgregarPasajeroAlVuelo(cPasajero* _pasajero)  //agrega un pasajero al vuelo, osea a la lista de pasajeros de ese vuelo
{
	try 
	{
		if (avion->getCantidadActualDePasajeros() < avion->getCantidadPasajerosPermitidos()) // si en el avion asociado al vuelo, hay lugar
		{
			if (ListaPasajeros->AgregarPasajero(_pasajero) == true) // agrego el pasajero al vuelo
			{
				return true; // retorno verdadero, sino retorno falso
			}
		}
		if (avion->getCantidadActualDePasajeros() > avion->getCantidadPasajerosPermitidos()) throw " AVION LLENO";
		// si no hay lugar, lanzo una excepcion
	}
	catch (const char* msj)
	{
		cout << msj << endl;
		return false; // no lo agregue
	}
}
bool cVuelo::CambiarPasajeroAlVuelo(cPasajero*_pasajero,cPasajero*_pasajerocambio)
{
	string DNIdelPasajero = _pasajero->getDNI();
	if (ListaPasajeros->CambiarPasajero(DNIdelPasajero, _pasajerocambio)== true) // cambia el pasajero actual por el nuevo, uso el dni para localizar al viejo y poder asignarle ese lugar al nuevo
	{
		return true;
	}
	else
		return false;
}
bool cVuelo::EliminarPasajeroAlVuelo(cPasajero* _pasajero) //elimina a un pasajero de su lista mediante su dni
{
	if (ListaPasajeros->EliminarPasajero(_pasajero->getDNI()) == true) // si el pasajero se encuentra asociado al vuelo, lo elimino
	{
		return true;// si lo logre eliminar
	}
	else
		return false;
}
void cVuelo::pesototaldelvuelo() 
{
	int pesopasajeros = 0;
	int cantidadPasajeros = ListaPasajeros->getocupados();
	float PesoValijas=0, PesoTotal=0;
	pesopasajeros = (cantidadPasajeros + 4) * 75; //calcula el peso de todos los pasajeros que viajan en el vuelo 
	for (int i = 0; i < cantidadPasajeros; i++)//ingresa a la lista pasajero de su vuelo
	{
		PesoValijas = PesoValijas + (*ListaPasajeros)[i]->getPesoTotalequipaje();//recorre la lista y encuentra su peso total por pasajero
        //suma el peso total de todas las valijas 
	}
	PesoTotal = PesoValijas + pesopasajeros; //suma el peso de los pasajeros y de las valijas
	this->avion->setPesoReal(PesoTotal); //ingresa el peso total del vuelo a su avion correspondiente
}
string cVuelo::to_string()
{
	string tipovuelo= conviertoAstringTipoVuelo();
	string estadovuelo = conviertoAstringEstadoVuelo();
	return
		"Numero de Vuelo:" + NumVuelo + "\n" +
		"Tipo De Vuelo: " + (TipoVuelo ? "arribo" : "partida") + "\n" +
		"Estado Del Vuelo:" + estadovuelo + "\n" +
		"Destino: " + tipovuelo + "\n" +
		"Avion: " + avion->to_string() + "\n";
}
string cVuelo::conviertoAstringTipoVuelo()
{
	string tipovuelo;
	if (aeropuertoDestino == 0)
	{
		tipovuelo = "iguazu";
	}
	if (aeropuertoDestino == 1)
	{
		tipovuelo = "cordoba";
	}
	if (aeropuertoDestino == 2)
	{
		tipovuelo = "MarDelPlata";
	}
	if (aeropuertoDestino == 3)
	{
		tipovuelo = "bariloche";
	}
	if (aeropuertoDestino == 4)
	{
		tipovuelo = "usuhaia";
	}
	if (aeropuertoDestino == 5)
	{
		tipovuelo = "salta";
	}
	return tipovuelo;
}
string cVuelo::conviertoAstringEstadoVuelo()
{
	string estadovuelo;
	if (EstadoVuelo == 0)
	{
		estadovuelo = " Despegando";
	}
	if (EstadoVuelo == 1)
	{
		estadovuelo = " Aterrizando";
	}
	if (EstadoVuelo == 2)
	{
		estadovuelo = "PidiendoPermisoParaAterrizar";
	}
	if (EstadoVuelo == 3)
	{
		estadovuelo = " PidiendoPermisoParaDespegar";
	}
	if (EstadoVuelo == 4)
	{
		estadovuelo = "  RecibiendoPermisoParaAterrizar";
	}
	if (EstadoVuelo == 5)
	{
		estadovuelo = " RecibiendoPermisoParaDespegar ";
	}
	if (EstadoVuelo == 6)
	{
		estadovuelo = "NoRecibiendoPermisoParaAterrizar  ";
	}
	if (EstadoVuelo == 7)
	{
		estadovuelo = "NoRecibiendoPermisoParaDespegar  ";
	}
	return estadovuelo;
}
ostream& operator<<(ostream& out, cVuelo* vuelo)
{
	out << vuelo->to_string() << endl;
	return out;
}
void cVuelo::asociarAvionConVuelo(cAvion* _avion)
{
	this->avion = _avion;
}
void cVuelo::DesasociarAvionConVuelo()
{
	avion = NULL;
}
void cVuelo::AsignarListaPasajeros(cListaPasajeros* _ListaPasajeros)
{
	this->ListaPasajeros = _ListaPasajeros;
}
void cVuelo::DesasociarListaPasajeros()
{
	ListaPasajeros = NULL;
};
void cVuelo:: AsignarListaEquipajeDelVuelo(cListaEquipaje* _ListaEquipajeDelVuelo)
{
	this->ListaEquipajeVuelo = _ListaEquipajeDelVuelo;
}
void cVuelo::DesasociarListaEquipajeDelVuelo()
{
	ListaEquipajeVuelo = NULL;
}
void cVuelo::AsignarFechaYhora(cFecha* _fechayhora)
{
	this->fechayhoraReal = _fechayhora;
}
void cVuelo::desasignarFechaYhora()
{
	fechayhoraReal = NULL;
}