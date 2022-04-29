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
	string tipovuelo= conviertoAstringTipoVuelo(aeropuertoDestino);
	string estadovuelo = conviertoAstringEstadoVuelo(EstadoVuelo);
	return
		"Numero de Vuelo:" + NumVuelo + "\n" +
		"Tipo De Vuelo: " + (TipoVuelo ? "arribo" : "partida") + "\n" +
		"Estado Del Vuelo:" + estadovuelo + "\n" +
		"Destino: " + tipovuelo + "\n" +
		"Avion: " + avion->to_string() + "\n";
}
string cVuelo::conviertoAstringTipoVuelo(destinos AeropuertoDeDestino)
{
	switch(AeropuertoDeDestino)
	{
	case destinos::Bariloche:
			return "Bariloche";
			break;
	case destinos::Cordoba:
		return "Cordoba";
		break;
	case destinos::Iguazu:
		return "Iguazu";
		break;
	case destinos::MarDelPlata:
		return "Mar del Plata";
		break;
	case destinos::Salta:
		return"Salta";
		break;
	case destinos::Ushuaia:
		return "Usuhaia";
		break;
			
	}
}
string cVuelo::conviertoAstringEstadoVuelo(estado EstadoDelVuelo)
{
	switch (EstadoDelVuelo)
	{
	case estado::Aterrizando:
		return"Aterrizando";
		break;
	case estado::Despegando:
		return"Despegando";
		break;
	case estado::Nodespega:
		return"No Despega";
		break;
	case estado::NoRecibiendoPermisoParaAterrizar:
		return"No recibiendo Permiso Para Aterrizar";
		break;
	case estado::NoRecibiendoPermisoParaDespegar:
		return"No recibiendo permiso para despegar";
		break;
	case estado::PidiendoPermisoParaAterrizar:
		return"Pidiendo permiso para aterrizar";
		break;
	case estado::PidiendoPermisoParaDespegar:
		return"Pidiendo permiso para despegar";
		break;
	case estado::RecibiendoPermisoParaAterrizar:
		return"Recibiendo permiso para aterrizar";
		break;
	case estado::RecibiendoPermisoParaDespegar:
		return"Recibiendo permiso para despegar";
		break;

	}
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