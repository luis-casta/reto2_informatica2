#ifndef ALOJAMIENTO_H
#define ALOJAMIENTO_H
#include <string>

#include "fecha.h"

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

public:
    Alojamiento();
    Alojamiento(string& nuevoNombre, int  id, float nuevoPrecio, string& nuevaAmenidad, string& depto, string& nuevoMunicipio, string& dir, string& nuevoTipo);
    ~Alojamiento();

    //metodo gueter y setter para nombre
    void setNombre(string& nombre);
    string getNombre();

    // metodo guetter y setter para identificador 
    void setIdentificador(int id);
    int  getIdentificador();

    // metodo setter y guetter para precio por noche 
    void setPrecioNoche(float precio);
   float  getPrecioNoche();

    // metodos setter y guetter para amenidades 
    void setAmenidades(string& amenidad);
    string getAmenidades();

    // metodos setter y guetter para municipio
    void setMunicipio(string& municipio);
    string getMunicipio();

    // metodos setter y guetter para deparatamento 
    void setDeparatamento(string& departamento);
    string getDeparatameto();

    // metodos setter y guetter para dirección 
    void setDireccion(string& direccion);
    string getDireccion();

	// metodos setter y guetter para tipo 
    void setTipo(string& tipo);
    string getTipo();

    bool estaDisponible(Fecha& fecha);
    bool agrgarReservacion(string& codigo);
    void modificarPrecio(float nuevoPrecio);
    string obtenerDetalles();
    void actualizarDisponibilidad(bool disponible);
};

#endif
