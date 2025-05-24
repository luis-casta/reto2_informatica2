#include "alojamiento.h"
#include <iostream>
#include <string>

using namespace std;

Alojamiento::Alojamiento() {
    nombre = departamento = amenidades = municipio = direccion = tipo = "";
    precioNoche = 0.0;
    identificador = 0;
    reservaciones = nullptr;
    contadorReservaciones = 0;
    disponible = true;
}

// Constructor sobrecargado (con parámetros)
Alojamiento::Alojamiento(string& nuevoNombre, int id, float nuevoPrecio, string& nuevaAmenidad,
                         string& depto, string& nuevoMunicipio, string& dir, string& nuevoTipo, bool estadoDisponible) {
    nombre = nuevoNombre;
    identificador = id;
    precioNoche = nuevoPrecio;
    amenidades = nuevaAmenidad;
    departamento = depto;
    municipio = nuevoMunicipio;
    direccion = dir;
    tipo = nuevoTipo;
    disponible = estadoDisponible;
    reservaciones = nullptr;
    contadorReservaciones = 0;
}

// Destructor
Alojamiento::~Alojamiento() {
    if (reservaciones != nullptr) {
        delete[] reservaciones;
    }
}

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
    tipo = nuevoTipo;
}
string Alojamiento::getTipo(){
   return tipo;
}

// setters y guetter para disponible
void Alojamiento::setDisponible(bool estado){
    disponible = estado;
}
bool Alojamiento::getDisponible(){
    return disponible;
}

// verificar disponibilidad
bool Alojamiento::estaDisponible(Fecha *ptrInicio, int noches) {
    if(ptrInicio == nullptr || noches <= 0 || !disponible) {
        return false;
    }
    // Falta implementar la lógica de las fechas
    return true;
}



// agrgar reservacion
bool Alojamiento::agrgarReservacion(Reservacion *ptrReserva) {
    // Verificar si el puntero es válido
    if (ptrReserva == nullptr || !estaDisponible(nullptr, 1)) {
        return false;
    }

    // Creamos un nuevo arreglo con espacio para una reservación adicional
    Reservacion *ptrNuevasReservaciones = new Reservacion[contadorReservaciones + 1];

    // Copiamos las reservaciones existentes al nuevo arreglo
    for (int i = 0; i < contadorReservaciones; i++) {
        ptrNuevasReservaciones[i] = reservaciones[i];
    }

    // Agregamos la nueva reservación al final
    ptrNuevasReservaciones[contadorReservaciones] = *ptrReserva;
    contadorReservaciones++;

    // Liberamos el arreglo antiguo si existía
    if (reservaciones != nullptr) {
        delete[] reservaciones;
    }

    // Actualizamos el puntero para que apunte al nuevo arreglo
    reservaciones = ptrNuevasReservaciones;
    return true;
}



// modificar precio
void Alojamiento::modificarPrecio(float nuevoPrecio){
    if(nuevoPrecio > 0){
        precioNoche = nuevoPrecio;
    }
}


// actualizar disponibilidad
void Alojamiento::actualizarDisponibilidad(bool nuevoEstado) {
    disponible = nuevoEstado;
}
