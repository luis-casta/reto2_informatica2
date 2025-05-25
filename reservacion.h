#ifndef RESERVACION_H
#define RESERVACION_H

#include <string>
using namespace std;

class Fecha;
class Alojamiento;
class Huesped;

class Reservacion {
private:
    string codigo;
    Fecha* inicio;
    int duracionNoches;
    Alojamiento* alojamiento;
    Huesped* huesped;

public:
    Reservacion();
    Reservacion(string& cod, Fecha* ini, int noches, Alojamiento* aloja, Huesped* huesp);
    ~Reservacion();

    // Setters y getters
    void setCodigo(string& cod);
    string getCodigo();

    void setInicio(Fecha* ini);
    Fecha* getInicio();

    void setDuracionNoches(int noches);
    int getDuracionNoches();

    void setAlojamiento(Alojamiento* aloja);
    Alojamiento* getAlojamiento();

    void setHuesped(Huesped* huesp);
    Huesped* getHuesped();

    // Métodos funcionales
    float calcularCosto();
    string generarComprobante();
    void cancelarReservacion();
    bool verificarDisponibilidad();
    bool interceptaCon(Fecha* fecha, int noches);
};

#endif
