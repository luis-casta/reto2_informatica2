#include "anfitrion.h"
#include <iostream>

using namespace std;

// función para calcular la longitud de la cadea, por eficiencia decidí recorrer la cadena con punteros y no usando indices
int longitudCadena(char *ptrTexto) {
     char* ptrInicio = ptrTexto;
    while (*ptrTexto != '\0') {
        ptrTexto++;
    }
    return ptrTexto - ptrInicio;
}

// funcion para copiar la cadena, también usé punteros
void copiarCadena(char *ptrDestino, char *ptrOrigen) {
    while (*ptrOrigen != '\0') {
        *ptrDestino = *ptrOrigen;
        ptrDestino++;
        ptrOrigen++;
    }
    *ptrDestino = '\0';
}

// Constructor por defecto
Anfitrion::Anfitrion() {
    ptrDocumento = nullptr;
    ptrAntiguedad = nullptr;
    puntuacion = 0.0;
    ptrAlojamientos = nullptr;
}

// Constructor sobrecargado con parametros por defecto
Anfitrion::Anfitrion(char* cedula, char* tiempoPlataforma, float puntos, Alojamiento* alojamiento) {
    ptrDocumento = nullptr;
    ptrAntiguedad = nullptr;
    ptrAlojamientos = nullptr;

    setDocumento(cedula);
    setAntiguedad(tiempoPlataforma);
    puntuacion = puntos;
    setAlojamiento(alojamiento);
}


// Destructor
Anfitrion::~Anfitrion() {
    if (ptrDocumento != nullptr) {
        delete[] ptrDocumento;
    }
    if (ptrAntiguedad != nullptr) {
        delete[] ptrAntiguedad;
    }
}

// Set y get para documento
void Anfitrion::setDocumento(char* ptrCedula) {
    if (ptrDocumento != nullptr) {
        delete[] ptrDocumento;
    }
    int longitud = longitudCadena(ptrCedula);
    ptrDocumento = new char[longitud + 1];
    copiarCadena(ptrDocumento, ptrCedula);
}

char* Anfitrion::getDocumento() const {
    return ptrDocumento;
}

// Set y get para antigüedad
void Anfitrion::setAntiguedad(char* ptrTiempoPlataforma) {
    if (ptrAntiguedad != nullptr) {
        delete[] ptrAntiguedad;
    }
    int longitud = longitudCadena(ptrTiempoPlataforma);
    ptrAntiguedad = new char[longitud + 1];
    copiarCadena(ptrAntiguedad, ptrTiempoPlataforma);
}

char* Anfitrion::getAntiguedad() const {
    return ptrAntiguedad;
}

// Set y get para puntuación
void Anfitrion::setPuntuacion(float puntos) {
    puntuacion = puntos;
}

float Anfitrion::getPuntuacion() const {
    return puntuacion;
}

// Set y get para alojamiento
void Anfitrion::setAlojamiento(Alojamiento* alojamiento) {
    ptrAlojamientos = alojamiento;
}

Alojamiento* Anfitrion::getAlojamiento() const {
    return ptrAlojamientos;
}

// Mostrar información completa del anfitrión
void Anfitrion::InformacionAnfitrion() const {
    cout << "--------- Información del Anfitrión----------" << endl;
    cout << "Documento: " << (ptrDocumento ? ptrDocumento : "No definido") << endl;
    cout << "Antigüedad: " << (ptrAntiguedad ? ptrAntiguedad : "No definida") << endl;
    cout << "Puntuación: " << puntuacion << endl;

    if (ptrAlojamientos != nullptr) {
        cout << "------Alojamiento Asociado --------" << endl;
        ptrAlojamientos->mostrarInformacion();
    } else {
        cout << "No tiene alojamiento asociado." << endl;
    }
}
