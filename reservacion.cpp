#include "reservacion.h"

//  para copiar cadenas
void copiarCadena(char* destino, const char* origen) {
    int i = 0;
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0';
}

//  para obtener la longitud de una cadena
int longitudCadena(const char* cadena) {
    int i = 0;
    while (cadena[i] != '\0') {
        i++;
    }
    return i;
}

Reservacion::Reservacion(const char* cod, Fecha* ini, int dur, Alojamiento* aloj, Huesped* hues) {
    int tam = longitudCadena(cod);
    codigo = new char[tam + 1];
    copiarCadena(codigo, cod);

    inicio = new Fecha(*ini);
    duracion = dur;
    alojamiento = aloj;
    huesped = hues;
}

Reservacion::Reservacion(const Reservacion& otra) {
    int tam = longitudCadena(otra.codigo);
    codigo = new char[tam + 1];
    copiarCadena(codigo, otra.codigo);

    inicio = new Fecha(*otra.inicio);
    duracion = otra.duracion;
    alojamiento = otra.alojamiento;
    huesped = otra.huesped;
}

Reservacion::~Reservacion() {
    delete[] codigo;
    delete inicio;
}

float Reservacion::calcularCosto() const {
    return alojamiento->getPrecioPorNoche() * duracion;
}

char* Reservacion::generarComprobante() const {
    return codigo;
}
