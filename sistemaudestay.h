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

    // NUEVOS ATRIBUTOS PARA MEDICIÓN DE RECURSOS
    static long  contadorIteracionesGlobal;

    long long contadorIteracionesLocal;

    // Métodos auxiliares privados
    bool documentoExiste(string& documento, bool esAnfitrion);
    bool alojamientoDisponible(int idAlojamiento, Fecha* inicio, int noches);
    string generarCodigoReserva();

    // NUEVOS MÉTODOS PRIVADOS PARA MEDICIÓN
    void incrementarIteraciones(long long cantidad = 1);
    void resetearContadorLocal();
    long long calcularMemoriaObjetos();
    long long calcularMemoriaArray(int elementos, int tamanoElemento);

public:
    // Constructores y destructor
    SistemaUdestay();
    SistemaUdestay(int nuevaCapacidad);
    ~SistemaUdestay();

    // Métodos de registro
    void registrarAnfitrion(string& documento);
    void registrarHuesped(string& documento);
    void agregarAlojamiento(Alojamiento* alojamiento);
    bool validarDocumento(const char* documento, int tipoUsuario, const char* rutaArchivo = "");

    // Métodos de búsqueda y estadísticas
    void buscarAlojamientoPorCodigo(int codigo);
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

    // NUEVOS MÉTODOS PÚBLICOS PARA MEDICIÓN DE RECURSOS
    void mostrarConsumoRecursos(const string& nombreFuncionalidad);
    void iniciarMedicion();
    void finalizarMedicion(const string& nombreFuncionalidad);
    long long obtenerIteracionesTotales();
    long long obtenerMemoriaTotal();
    void mostrarEstadisticasCompletas();
};



#endif // SISTEMAUDESTAY_H
