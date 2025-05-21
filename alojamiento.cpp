#include "alojamiento.h"
#include <iostream>
#include <string>

using namespace std;

Alojamiento::Alojamiento(){
    nombre = departamento = amenidades = municipio = direccion = tipo = "";
    identificador = 0;
    precioNoche = 0.0;
}

// constructor sobrecargado (con parametros)
Alojamiento::Alojamiento(string& nuevoNombre, int id, float nuevoPrecio, string& nuevaAmenidad, string& depto, string& nuevoMunicipio, string& dir, string& nuevoTipo) {
    nombre = nuevoNombre;
    identificador = id;
    precioNoche = nuevoPrecio;
    amenidades = nuevaAmenidad;
    departamento = depto;
    municipio = nuevoMunicipio;
    direccion = dir;
    tipo = nuevoTipo;
}

// destructor 
Alojamiento::~Alojamiento(){}

// setter y guetters para nombre
void Alojamiento::setNombre(string& nuevoNombre){
     nombre = nuevoNombre;
}
string Alojamiento::getNombre(){
	return nombre;
}

// setter y gueter para idntificador 
void Alojamiento::setIdentificador(int id){
    identificador = id;
}
int Alojamiento::getIdentificador(){
	return identificador;
}

// setter y gueter para precio por noche 
void Alojamiento::setPrecioNoche(float nuevoPrecio){
    precioNoche = nuevoPrecio;
}
float Alojamiento::getPrecioNoche(){
	return precioNoche;
}

// setter y guetters para amenidades 
void Alojamiento::setAmenidades(string& nuevaAmenidad){
	amenidades = nuevaAmenidad;
}
string Alojamiento::getAmenidades(){
   return amenidades;
}

// setter y guetters para departamento
void Alojamiento::setDeparatamento(string& depto){
	departamento = depto;
}
string Alojamiento::getDeparatameto(){
   return departamento;
}

// setter y guetters para municipio 
void Alojamiento::setMunicipio(string& nuevoMunicipio){
	municipio = nuevoMunicipio;
}
string Alojamiento::getMunicipio(){
   return municipio;
}

// setter y guetters para dirección
void Alojamiento::setDireccion(string& dir){
direccion = dir;
}
string Alojamiento::getDireccion(){
   return direccion;
}

// setter y guetters para municipio 
void Alojamiento::setTipo(string& nuevoTipo){
	tipo = tipo;
}
string Alojamiento::getTipo(){
   return tipo;
}

// metodos adicionales 
bool Alojamiento::estaDisponible(Fecha& fecha){
	return true;
    // falta implementar
}

bool Alojamiento::agrgarReservacion(string& codigo){
   return true;
   // falta implementar
}

void Alojamiento::modificarPrecio(float nuevoPrecio){
    if (nuevoPrecio > 0){
      precioNoche = nuevoPrecio;
    }
}

string Alojamiento::obtenerDetalles(){
    return "Alñojamiento" + nombre + "\nPrecio: " + to_string(precioNoche) + "\nTipo: " + tipo;
}

void Alojamiento::actualizarDisponibilidad(bool disponible){
   // falta implementarla
}