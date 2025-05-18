#ifndef ANFITRION_H
#define ANFITRION_H

#include "alojamiento.h"

class Anfitrion
{
private:
    char* ptrDocumento;
    char* ptrAntiguedad;
    float puntuacion;
    Alojamiento* ptrAlojamientos;

public:

    // decidí sobrecargar el constructor, teniedo el constructor por defecto y creando el constructor con los parametros por defecto del anfitrion
    Anfitrion();
    Anfitrion(char* cedula, char* tiempoPlataforma, float puntos, Alojamiento* alojamiento);
    ~Anfitrion();

    void setDocumento(char* cedula);
    char* getDocumento() const;

    void setAntiguedad(char* tiempoPlataforma);
    char* getAntiguedad() const;

    void setPuntuacion(float puntos);
    float getPuntuacion() const;

    void setAlojamiento(Alojamiento* alojamiento);
    Alojamiento* getAlojamiento() const;

    void InformacionAnfitrion() const;
};

#endif // ANFITRION_H
