#include "huesped.h"
#include <iostream>

using namespace std;

// función que me calcula la longitud de la cadena, por eficiencia uso punteros para recorrer la cadena.
int longitudCadena(char *ptrTexto)
{
    char *ptrActual = ptrTexto;
    while (*ptrActual != '\0')
    {
        ptrActual++;
    }
    return ptrActual - ptrTexto;
}

// función  para copiar la cadena, también uso punteros
void copiarCadena(char *ptrDestino, char *ptrOrigen)
{

    while (*ptrOrigen != '\0')
    {
        *ptrDestino = *ptrOrigen;
        ptrOrigen++;
        ptrDestino++;
    }
    *ptrDestino = '\0';
}

// Constructor por defecto
Huesped::Huesped()
{
    ptrDocumento = nullptr;
    ptrAntiguedad = nullptr;
    puntuacion = 0.0;
    ptrAlojamientos = nullptr;
}

// Constructor sobrecargado, con parametros
Huesped::Huesped(char *cedula, char *tiempoPlataforma, float puntos, Alojamiento *alojamiento)
{
    ptrDocumento = nullptr;
    ptrAntiguedad = nullptr;
    ptrAlojamientos = nullptr;

    setDocumento(cedula);
    setAntiguedad(tiempoPlataforma);
    puntuacion = puntos;
    setAlojamiento(alojamiento);
}

// Destructor
Huesped::~Huesped()
{
    if (ptrDocumento != nullptr)
    {
        delete[] ptrDocumento;
    }
    if (ptrAntiguedad != nullptr)
    {
        delete[] ptrAntiguedad;
    }
}

// Set y get para documento
void Huesped::setDocumento(char *cedula)
{
    if (ptrDocumento != nullptr)
    {
        delete[] ptrDocumento;
    }

    int longitud = longitudCadena(cedula);
    ptrDocumento = new char[longitud + 1];
    copiarCadena(ptrDocumento, cedula);
}

char *Huesped::getDocumento() const
{
    return ptrDocumento;
}

// Set y get para antigüedad
void Huesped::setAntiguedad(char *tiempoPlataforma)
{
    if (ptrAntiguedad != nullptr)
    {
        delete[] ptrAntiguedad;
    }

    int longitud = longitudCadena(tiempoPlataforma);
    ptrAntiguedad = new char[longitud + 1];
    copiarCadena(ptrAntiguedad, tiempoPlataforma);
}

char *Huesped::getAntiguedad() const
{
    return ptrAntiguedad;
}

// Set y get para puntuación
void Huesped::setPuntuacion(float puntos)
{
    puntuacion = puntos;
}

float Huesped::getPuntuacion() const
{
    return puntuacion;
}

// Set y get para alojamientos
void Huesped::setAlojamiento(Alojamiento *alojamiento)
{
    ptrAlojamientos = alojamiento;
}

Alojamiento *Huesped::getAlojamiento() const
{
    return ptrAlojamientos;
}

// Mostrar reservas
void Huesped::mostrarReservas(Alojamiento *alojamiento)
{
    // falta implementarla
}

// Hacer reservas
bool Huesped::hacerReservas()
{
    return false;
    // falta implementarla
}
