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

}
cVuelo::~cVuelo() {};
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
			cant = (*ListaPasajeros)[i]->getEquipaje(); // le asigno a cant la cantidad de equipja que tiene ese pasajero sub i
			peso = +(*ListaPasajeros)[i]->getPesoTotalequipaje();
			string cantequipaje(std::to_string(cant)); //convierte a string las cantidad de equipaje del pasajero
			string pesoequipaje(std::to_string(peso)); //convierte a string el peso de todo el equipaje
			datospasajero += "PASAJERO: " + (*ListaPasajeros)[i]->getDNI() + (*ListaPasajeros)[i]->getapellido() + cantequipaje + pesoequipaje;
			//si encuentra al pasajero por su dni guarda todos sus datos en un string
		}
	}
	return datospasajero;
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
bool cVuelo::AgregarPasajeroAlVuelo(cPasajero* _pasajero)  //agrega un pasajero desde el vuelo a su lista de pasajeros
{
	if (_pasajero->getNumVuelo() == NumVuelo) // si el numero de vuelo que tiene el pasajero coincide con el del vuelo al cual yo lo quiero agregar
	{
		if (ListaPasajeros->AgregarPasajero(_pasajero) == true) // si lo pude agregar ya que tenia capacidad
		{
			return true; // retorno verdadero, sino retorno falso
		}
		else
			return false;
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
	this->avion->setPesoReaal(PesoTotal); //ingresa el peso total del vuelo a su avion correspondiente
}
ostream& operator<<(ostream &out, cVuelo* vuelo)
{
	out << vuelo->NumVuelo << endl;
	out << vuelo->TipoVuelo << endl;
	out << vuelo->aeropuertoDestino << endl;
	out << vuelo->avion << endl;
	out << vuelo->EstadoVuelo<< endl;
	
	return out;
}
