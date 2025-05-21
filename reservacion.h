#ifndef RESERVACION_H
#define RESERVACION_H

#include "fecha.h"
#include "alojamiento.h"
#include "huesped.h"

class Reservacion {
private:
    char* codigo;
    Fecha* inicio;
    int duracion;
    Alojamiento* alojamiento;
    //Huesped* huesped;

public:
    Reservacion(const char* cod, Fecha* ini, int dur, Alojamiento* aloj, Huesped* hues);
    Reservacion(const Reservacion& otra);
    ~Reservacion();

    float calcularCosto() const;
    char* generarComprobante() const;
};

#endif // RESERVACION_H
