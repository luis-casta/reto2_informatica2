#include "reservacion.h"
#include "alojamiento.h"
#include "huesped.h"
#include "fecha.h"
#include <iostream>

using namespace std;

Reservacion::Reservacion() {
    codigo = "";
    inicio = nullptr;
    duracionNoches = 0;
    alojamiento = nullptr;
    huesped = nullptr;
}

Reservacion::Reservacion(string& cod, Fecha* ini, int noches, Alojamiento* aloja, Huesped* huesp) {
    codigo = cod;
    inicio = ini;
    duracionNoches = noches;
    alojamiento = aloja;
    huesped = huesp;
}

Reservacion::~Reservacion() {
    inicio = nullptr;
    alojamiento = nullptr;
    huesped = nullptr;
}

// Setters y getters
void Reservacion::setCodigo(string& cod) {
    codigo = cod;
}
string Reservacion::getCodigo() {
    return codigo;
}

void Reservacion::setInicio(Fecha* ini) {
    inicio = ini;
}
Fecha* Reservacion::getInicio() {
    return inicio;
}

void Reservacion::setDuracionNoches(int noches) {
    duracionNoches = noches;
}
int Reservacion::getDuracionNoches() {
    return duracionNoches;
}

void Reservacion::setAlojamiento(Alojamiento* aloja) {
    alojamiento = aloja;
}
Alojamiento* Reservacion::getAlojamiento() {
    return alojamiento;
}

void Reservacion::setHuesped(Huesped* huesp) {
    huesped = huesp;
}
Huesped* Reservacion::getHuesped() {
    return huesped;
}

// Métodos funcionales
float Reservacion::calcularCosto() {
    if (alojamiento != nullptr) {
        return alojamiento->getPrecioNoche() * duracionNoches;
    }
    return 0;
}

string Reservacion::generarComprobante() {
    string comprobante = "COMPROBANTE DE RESERVACIÓN\n";
    comprobante += "Código: " + codigo + "\n";
    if (huesped != nullptr) {
        comprobante += "Huésped: " + huesped->getDocumento() + "\n";
    }
    if (alojamiento != nullptr) {
        comprobante += "Alojamiento: " + alojamiento->getNombre() + "\n";
    }
    if (inicio != nullptr) {
        comprobante += "Fecha inicio: " + inicio->actualizarFecha() + "\n";
    }
    comprobante += "Duración: " + to_string(duracionNoches) + " noches\n";
    comprobante += "Costo total: $" + to_string(calcularCosto()) + "\n";
    return comprobante;
}

void Reservacion::cancelarReservacion() {
    codigo = "CANCELADA_" + codigo;
}

bool Reservacion::verificarDisponibilidad() {
    if (alojamiento != nullptr && inicio != nullptr) {
        return alojamiento->estaDisponible(inicio, duracionNoches);
    }
    return false;
}

bool Reservacion::interceptaCon(Fecha* fecha, int noches) {
    if (inicio != nullptr && fecha != nullptr) {
        return inicio->interceptaCon(fecha, noches);
    }
    return false;
}
