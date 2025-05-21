#include "fecha.h"
//#include <iostream>

Fecha::Fecha(int d, int m, int a) {
    dia = new int(d);
    mes = new int(m);
    anio = new int(a);
}

Fecha::Fecha(const Fecha& otra) {
    dia = new int(*otra.dia);
    mes = new int(*otra.mes);
    anio = new int(*otra.anio);
}

Fecha::~Fecha() {
    delete dia;
    delete mes;
    delete anio;
}

// Getters
int Fecha::getDia() const { return *dia; }
int Fecha::getMes() const { return *mes; }
int Fecha::getAnio() const { return *anio; }

// Setters
void Fecha::setDia(int d) { *dia = d; }
void Fecha::setMes(int m) { *mes = m; }
void Fecha::setAnio(int a) { *anio = a; }

// Validar de fecha
bool Fecha::esValida() const {
    if (*mes < 1 || *mes > 12 || *dia < 1 || *dia > 31) return false;
    return true;
}

// Actualiza fecha sumando días
void Fecha::actualizarFecha(int n) {
    *dia += n;
    while (*dia > 31) {
        *dia -= 31;
        *mes += 1;
        if (*mes > 12) {
            *mes = 1;
            *anio += 1;
        }
    }
}
