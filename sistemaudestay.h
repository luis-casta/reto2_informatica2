#ifndef SISTEMAUDESTAY_H
#define SISTEMAUDESTAY_H

#include <string>
#include "huesped.h"
#include "alojamiento.h"
#include "anfitrion.h"
#include "historico.h"
#include "reservacion.h"
#include "fecha.h"

using namespace std;

class SistemaUdestay {
private:
    Anfitrion* anfitriones;
    Huesped* huespedes;
    Alojamiento* alojamientos;
    Reservacion* reservaciones;
    Historico* historico;

    int capacidad;
    int contadorAnfitriones;
    int contadorHuespedes;
    int contadorAlojamientos;
    int contadorReservaciones;


    // Métodos auxiliares privados
    bool documentoExiste(string& documento, bool esAnfitrion);
    bool alojamientoDisponible(int idAlojamiento, Fecha* inicio, int noches);
    string generarCodigoReserva();

public:
    // Constructores y destructor
    SistemaUdestay();
    SistemaUdestay(int nuevaCapacidad);
    ~SistemaUdestay();

    // Métodos de registro
    void registrarAnfitrion(string& documento);
    void registrarHuesped(string& documento);
    void agregarAlojamiento(Alojamiento* alojamiento);
    bool validarDocumento(const char* documento, int tipoUsuario, const char* rutaArchivo = "anfitriones.txt");//valida el usuario

    // Métodos de búsqueda y estadísticas
    void buscarAlojamientoPorUbicacion(string& ubicacion);
    void mostrarEstadisticaReservas();

    // Métodos de autenticación
    bool verificarAnfitrion(string& documento);
    bool validarContraseñaAnfitrion(string& documento, string& contraseña);
    bool verificarHuesped(string& documento);
    bool validarContraseñaHuesped(string& documento, string& contraseña);

    // Métodos de gestión de datos
    void actualizarHistorico(Fecha* corteDeFecha);
    void guardarDatos();
    void cargarDatos();
};

#endif // SISTEMAUDESTAY_H
