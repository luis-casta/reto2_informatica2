#ifndef SISTEMAUDESTAY_H
#define SISTEMAUDESTAY_H

#include <string>
#include "huesped.h"
#include "alojamiento.h"
#include "anfitrion.h"
#include "historico.h"

using namespace std;

class SistemaUdestay
{
private:
    Anfitrion* anfitriones;
    Huesped* huespedes;
    Alojamiento* alojamientos;
    Historico* historico;
    int contadorAnfitriones;
    int contadorHuespedes;
    int contadorAlojamientos;
    int capacidad;

public:
    SistemaUdestay();
    SistemaUdestay(int nuevaCapacidad);
    ~SistemaUdestay();

    // métodos getter y setter para anfitriones
    void setAnfitriones(Anfitrion* nuevosAnfitriones);
    Anfitrion* getAnfitriones();

    // métodos getter y setter para huespedes
    void setHuespedes(Huesped* nuevosHuespedes);
    Huesped* getHuespedes();

    // métodos getter y setter para alojamientos
    void setAlojamientos(Alojamiento* nuevosAlojamientos);
    Alojamiento* getAlojamientos();

    // métodos getter y setter para historico
    void setHistorico(Historico* nuevoHistorico);
    Historico* getHistorico();

    // métodos getter y setter para contadorAnfitriones
    void setContadorAnfitriones(int nuevoContador);
    int getContadorAnfitriones();

    // métodos getter y setter para contadorHuespedes
    void setContadorHuespedes(int nuevoContador);
    int getContadorHuespedes();

    // métodos getter y setter para contadorAlojamientos
    void setContadorAlojamientos(int nuevoContador);
    int getContadorAlojamientos();

    // métodos getter y setter para capacidad
    void setCapacidad(int nuevaCapacidad);
    int getCapacidad();

    // métodos del sistema
    void resgistrarAnfitrio(string& documento);
    void resgistrarHuesped(string& documento);
    void agrgarAlojamiento(Alojamiento* alojamiento);
    void buscarAlojamientoPorUbicacion(string& ubicacion);
    void mostrarEstadisticaReservas();
    void actualizarHistorico(Fecha* corteDeFecha);
    void guardarDatos();
    void cargarDatos();
};

#endif // SISTEMAUDESTAY_H
