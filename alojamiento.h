#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H

#include <string>
#include "fecha.h"

using namespace std;

class Alojamiento {
private:
    string nombre;
    int identificador;
    float precioNoche;
    string amenidades;
    string departamento;
    string municipio;
    string direccion;
    string tipo;
    Reservacion* reservaciones;
    int contadorReservaciones;
    bool disponible;

public:
    Alojamiento();
    Alojamiento(string& nuevoNombre, int id, float nuevoPrecio, string& nuevaAmenidad, string& depto, string& nuevoMunicipio, string& dir, string& nuevoTipo, bool estadoDisponible);
    ~Alojamiento();

    // métodos getter y setter para nombre
    void setNombre(string& nombre);
    string getNombre();

    // métodos getter y setter para identificador
    void setIdentificador(int id);
    int getIdentificador();

    // métodos getter y setter para precio por noche
    void setPrecioNoche(float precio);
    float getPrecioNoche();

    // métodos getter y setter para amenidades
    void setAmenidades(string& amenidad);
    string getAmenidades();

    // métodos getter y setter para municipio
    void setMunicipio(string& municipio);
    string getMunicipio();

    // métodos getter y setter para departamento
    void setDepartamento(string& departamento);
    string getDepartamento();

    // métodos getter y setter para dirección
    void setDireccion(string& direccion);
    string getDireccion();

    // métodos getter y setter para tipo
    void setTipo(string& tipo);
    string getTipo();

    // métodos getter y setter para disponibilidad
    void setDisponible(bool estado);
    bool getDisponible();

    // métodos
    bool estaDisponible(Fecha* inicio, int noches);
    bool agrgarReservacion(Reservacion* reserva);
    void modificarPrecio(float nuevoPrecio);
    void actualizarDisponibilidad(bool disponible);
};

#endif
