#ifndef HUESPED_H
#define HUESPED_H

#include "alojamiento.h"

class Huesped
{
private:
    char* ptrDocumento;
    char* ptrAntiguedad;
    float puntuacion;
    Alojamiento* ptrAlojamientos;

public:
    Huesped();
    Huesped(char* cedula, char* tiempoPlataforma, float puntos, Alojamiento* alojamiento);
    ~Huesped();

    void setDocumento(char* cedula);
    char* getDocumento() const;

    void setAntiguedad(char* tiempoPlataforma);
    char* getAntiguedad() const;

    void setPuntuacion(float puntos);
    float getPuntuacion() const;

    void setAlojamiento(Alojamiento* alojamiento);
    Alojamiento* getAlojamiento() const;

    void mostrarReservas(Alojamiento*);
    bool hacerReservas();
};

#endif // HUESPED_H
