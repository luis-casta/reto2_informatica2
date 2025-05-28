#include "sistemaudestay.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Inicialización del contador estático
long  SistemaUdestay::contadorIteracionesGlobal = 0;

SistemaUdestay::SistemaUdestay() {
    capacidad = 100;
    anfitriones = new Anfitrion[capacidad];
    huespedes = new Huesped[capacidad];
    alojamientos = new Alojamiento[capacidad];
    reservaciones = new Reservacion[capacidad];
    historico = new Historico();

    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    contadorReservaciones = 0;
    contadorIteracionesLocal = 0;
}

SistemaUdestay::SistemaUdestay(int nuevaCapacidad) {
    capacidad = nuevaCapacidad;
    anfitriones = new Anfitrion[capacidad];
    huespedes = new Huesped[capacidad];
    alojamientos = new Alojamiento[capacidad];
    reservaciones = new Reservacion[capacidad];
    historico = new Historico();

    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    contadorReservaciones = 0;
    contadorIteracionesLocal = 0;
}

SistemaUdestay::~SistemaUdestay() {
    delete[] anfitriones;
    delete[] huespedes;
    delete[] alojamientos;
    delete[] reservaciones;
    delete historico;
}

// Métodos privados para medición de recursos
void SistemaUdestay::incrementarIteraciones(long long cantidad) {
    contadorIteracionesLocal += cantidad;
    contadorIteracionesGlobal += cantidad;
}

void SistemaUdestay::resetearContadorLocal() {
    contadorIteracionesLocal = 0;
}

long long SistemaUdestay::calcularMemoriaObjetos() {
    long long memoria = 0;
    memoria += sizeof(SistemaUdestay);
    memoria += sizeof(Historico);
    return memoria;
}

long long SistemaUdestay::calcularMemoriaArray(int elementos, int tamanoElemento) {
    return elementos * tamanoElemento;
}

bool SistemaUdestay::documentoExiste(string& documento, bool esAnfitrion) {
    if (esAnfitrion) {
        for (int i = 0; i < contadorAnfitriones; i++) {
            incrementarIteraciones();
            if (anfitriones[i].getDocumento() == documento) {
                return true;
            }
        }
    } else {
        for (int i = 0; i < contadorHuespedes; i++) {
            incrementarIteraciones();
            if (huespedes[i].getDocumento() == documento) {
                return true;
            }
        }
    }
    return false;
}

bool SistemaUdestay::alojamientoDisponible(int idAlojamiento, Fecha* inicio, int noches) {
    for (int i = 0; i < contadorAlojamientos; i++) {
        incrementarIteraciones();
        if (alojamientos[i].getIdentificador() == idAlojamiento) {
            return alojamientos[i].estaDisponible(inicio, noches);
        }
    }
    return false;
}

string SistemaUdestay::generarCodigoReserva() {
    return "RES-" + to_string(contadorReservaciones + 1);
}

void SistemaUdestay::registrarAnfitrion(string& documento) {
    if (contadorAnfitriones < capacidad && !documentoExiste(documento, true)) {
        anfitriones[contadorAnfitriones].setDocumento(documento);
        contadorAnfitriones++;
        cout << "Anfitrion registrado exitosamente." << endl;
    } else {
        cout << "No se pudo registrar el anfitrion. Capacidad alcanzada o documento ya existe." << endl;
    }
}

void SistemaUdestay::registrarHuesped(string& documento) {
    if (contadorHuespedes < capacidad && !documentoExiste(documento, false)) {
        huespedes[contadorHuespedes].setDocumento(documento);
        contadorHuespedes++;
        cout << "Huesped registrado exitosamente." << endl;
    } else {
        cout << "No se pudo registrar el huesped. Capacidad alcanzada o documento ya existe." << endl;
    }
}

void SistemaUdestay::agregarAlojamiento(Alojamiento* alojamiento) {
    if (contadorAlojamientos < capacidad) {
        alojamientos[contadorAlojamientos] = *alojamiento;
        contadorAlojamientos++;
        cout << "Alojamiento agregado exitosamente." << endl;
    } else {
        cout << "No se pudo agregar el alojamiento. Capacidad alcanzada." << endl;
    }
}

bool SistemaUdestay::validarDocumento(const char* documento, int tipoUsuario, const char* rutaArchivo) {
    string docStr = documento;

    if (tipoUsuario == 1) {  // Validar anfitrión
        ifstream archivo("anfitriones.txt");
        if (!archivo.is_open()) {
            cout << "Error: No se pudo abrir anfitriones.txt." << endl;
            return false;
        }

        string linea;
        while (getline(archivo, linea)) {
            incrementarIteraciones();
            size_t pos = linea.find(',');
            if (pos == string::npos) continue;

            string cedula = linea.substr(0, pos);
            if (cedula == docStr) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;

    } else if (tipoUsuario == 2) {  // Validar huésped
        ifstream archivo("huespedes.txt");
        if (!archivo.is_open()) {
            cout << "Error: No se pudo abrir huespedes.txt." << endl;
            return false;
        }

        string linea;
        while (getline(archivo, linea)) {
            incrementarIteraciones();
            size_t pos = linea.find(',');
            if (pos == string::npos) continue;

            string cedula = linea.substr(0, pos);
            if (cedula == docStr) {
                archivo.close();
                return true;
            }
        }
        archivo.close();
        return false;
    }

    return false;
}

void SistemaUdestay::buscarAlojamientoPorCodigo(int codigo) {
    bool encontrado = false;

    cout << "Buscando alojamiento con código " << codigo << ":" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < contadorAlojamientos; i++) {
        incrementarIteraciones();
        if (alojamientos[i].getIdentificador() == codigo) {
            cout << "ID: " << alojamientos[i].getIdentificador() << endl;
            cout << "Nombre: " << alojamientos[i].getNombre() << endl;
            cout << "Precio por noche: $" << alojamientos[i].getPrecioNoche() << endl;
            cout << "Tipo: " << alojamientos[i].getTipo() << endl;
            cout << "Amenidades: " << alojamientos[i].getAmenidades() << endl;
            cout << "----------------------------------------" << endl;
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontró ningún alojamiento con el código especificado." << endl;
    }
}

void SistemaUdestay::mostrarEstadisticaReservas() {
    if (contadorReservaciones == 0) {
        cout << "No hay reservaciones registradas en el sistema." << endl;
        return;
    }

    int reservasPorTipo[2] = {0};
    float ingresosTotales = 0.0;
    int reservasPorMes[12] = {0};

    cout << "Estadisticas de Reservas:" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < contadorReservaciones; i++) {
        incrementarIteraciones();
        Alojamiento* alojamiento = reservaciones[i].getAlojamiento();
        string tipo = alojamiento->getTipo();

        if (tipo == "casa"){
            reservasPorTipo[0]++;
        }else {
            reservasPorTipo[1]++;
        }

        ingresosTotales += reservaciones[i].calcularCosto();

        Fecha* fechaInicio = reservaciones[i].getInicio();
        string mes = fechaInicio->getMes();
        int mesIndice = 0;
        if (mes == "enero") mesIndice = 0;
        else if (mes == "febrero") mesIndice = 1;
        else if (mes == "marzo") mesIndice = 2;
        else if (mes == "abril") mesIndice = 3;
        else if (mes == "mayo") mesIndice = 4;
        else if (mes == "junio") mesIndice = 5;
        else if (mes == "julio") mesIndice = 6;
        else if (mes == "agosto") mesIndice = 7;
        else if (mes == "septiembre") mesIndice = 8;
        else if (mes == "octubre") mesIndice = 9;
        else if (mes == "noviembre") mesIndice = 10;
        else if (mes == "diciembre") mesIndice = 11;

        reservasPorMes[mesIndice]++;
    }

    cout << "Total de reservaciones: " << contadorReservaciones << endl;
    cout << "Ingresos totales: $" << ingresosTotales << endl;

    cout << "\nReservaciones por tipo de alojamiento:" << endl;
    cout << "Casa: " << reservasPorTipo[0] << endl;
    cout << "Apartamento: " << reservasPorTipo[1] << endl;

    cout << "\nReservaciones por mes:" << endl;
    string meses[12] = {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                        "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    for (int i = 0; i < 12; i++) {
        if (reservasPorMes[i] > 0) {
            cout << meses[i] << ": " << reservasPorMes[i] << endl;
        }
    }

    cout << "----------------------------------------" << endl;
}

bool SistemaUdestay::verificarAnfitrion(string& documento) {
    ifstream archivo("anfitriones.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir anfitriones.txt." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        incrementarIteraciones();
        size_t pos = linea.find(',');
        if (pos == string::npos) continue;

        string cedula = linea.substr(0, pos);
        if (cedula == documento) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

bool SistemaUdestay::validarContraseñaAnfitrion(string& documento, string& claveIngresada) {
    ifstream archivo("anfitriones.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir anfitriones.txt." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        incrementarIteraciones();
        size_t posUltimaComa = linea.find_last_of(',');
        if (posUltimaComa == string::npos) continue;

        string cedula = linea.substr(0, linea.find(','));
        string clave = linea.substr(posUltimaComa + 1);

        if (cedula == documento && clave == claveIngresada) {
            archivo.close();
            return true;
        }
    }

    archivo.close();
    return false;
}

bool SistemaUdestay::verificarHuesped(string& documento) {
    return documentoExiste(documento, false);
}

bool SistemaUdestay::validarContraseñaHuesped(string& documento, string& contraseña) {
    for (int i = 0; i < contadorHuespedes; i++) {
        incrementarIteraciones();
        if (huespedes[i].getDocumento() == documento) {
            return huespedes[i].verificarCredenciales(contraseña);
        }
    }
    return false;
}

void SistemaUdestay::actualizarHistorico(Fecha* fechaCorte) {
    bool encontrado = false;

    cout << "Actualizando historico con fecha de corte..." << endl;

    for (int i = 0; i < contadorReservaciones; i++) {
        incrementarIteraciones();
        Fecha* fechaInicio = reservaciones[i].getInicio();

        if (fechaInicio->interceptaCon(fechaCorte, 0)) {
            historico->agregarReserva(&reservaciones[i]);

            for (int j = i; j < contadorReservaciones - 1; j++) {
                incrementarIteraciones();
                reservaciones[j] = reservaciones[j + 1];
            }

            contadorReservaciones--;
            i--;
            encontrado = true;
        }
    }

    if (encontrado) {
        cout << "Historico actualizado exitosamente." << endl;
    } else {
        cout << "No se encontraron reservaciones para el anfitrion en el rango de fechas especificado." << endl;
    }
}

void SistemaUdestay::guardarDatos() {
    ofstream archivoAnfitriones("anfitriones.txt");
    if (archivoAnfitriones.is_open()) {
        for (int i = 0; i < contadorAnfitriones; i++) {
            incrementarIteraciones();
            archivoAnfitriones << anfitriones[i].getDocumento() << ","
                               << anfitriones[i].getAntiguedad() << ","
                               << anfitriones[i].getPuntuacion() << ","
                               << anfitriones[i].getContraseña() << "\n";
        }
        archivoAnfitriones.close();
    } else {
        cout << "Error al guardar datos de anfitriones" << endl;
    }

    ofstream archivoHuespedes("huespedes.txt");
    if (archivoHuespedes.is_open()) {
        for (int i = 0; i < contadorHuespedes; i++) {
            incrementarIteraciones();
            archivoHuespedes << huespedes[i].getDocumento() << ","
                             << huespedes[i].getAntiguedad() << ","
                             << huespedes[i].getPuntuacion() << ","
                             << huespedes[i].getContraseña() << "\n";
        }
        archivoHuespedes.close();
    } else {
        cout << "Error al guardar datos de huéspedes" << endl;
    }

    ofstream archivoAlojamientos("alojamientos.txt");
    if (archivoAlojamientos.is_open()) {
        for (int i = 0; i < contadorAlojamientos; i++) {
            incrementarIteraciones();
            archivoAlojamientos << alojamientos[i].getIdentificador() << ","
                                << alojamientos[i].getNombre() << ","
                                << alojamientos[i].getPrecioNoche() << ","
                                << alojamientos[i].getTipo() << ","
                                << alojamientos[i].getMunicipio() << "\n";
        }
        archivoAlojamientos.close();
    } else {
        cout << "Error al guardar datos de alojamientos" << endl;
    }

    ofstream archivoReservaciones("reservaciones.txt");
    if (archivoReservaciones.is_open()) {
        for (int i = 0; i < contadorReservaciones; i++) {
            incrementarIteraciones();
            archivoReservaciones << reservaciones[i].getCodigo() << ","
                                 << reservaciones[i].getCodigo() << ","
                                 << reservaciones[i].getHuesped() << ","
                                 << reservaciones[i].getInicio()<< ","
                                 << reservaciones[i].getDuracionNoches() << ","
                                 << reservaciones[i].getMetodoPago() << ","
                                 << reservaciones[i].getAnotaciones() << "\n";
        }
        archivoReservaciones.close();
    } else {
        cout << "Error al guardar datos de reservaciones" << endl;
    }

    ofstream archivoHistorico("historico.txt");
    if (archivoHistorico.is_open()) {
        archivoHistorico.close();
    } else {
        cout << "Error al guardar datos históricos" << endl;
    }

    cout << "Datos guardados exitosamente en archivos." << endl;
}

void SistemaUdestay::cargarDatos() {
    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    contadorReservaciones = 0;

    ifstream archivoAnfitriones("anfitriones.txt");
    if (archivoAnfitriones.is_open()) {
        string linea;
        while (getline(archivoAnfitriones, linea)) {
            incrementarIteraciones();
            if (linea.empty() || contadorAnfitriones >= capacidad) break;

            string documento = "";
            string antiguedadStr = "";
            string puntuacionStr = "";
            string contrasena = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < (int)linea.length(); i++) {
                incrementarIteraciones();
                if (linea[i] == ',') {
                    if (campo == 0) documento = campoActual;
                    else if (campo == 1) antiguedadStr = campoActual;
                    else if (campo == 2) puntuacionStr = campoActual;

                    campoActual = "";
                    campo++;
                } else {
                    campoActual += linea[i];
                }
            }
            contrasena = campoActual;

            if (!documento.empty()) {
                anfitriones[contadorAnfitriones].setDocumento(documento);
                anfitriones[contadorAnfitriones].setAntiguedad(antiguedadStr);

                float puntuacion = 0.0;
                if (!puntuacionStr.empty()) {
                    puntuacion = stof(puntuacionStr);
                }
                anfitriones[contadorAnfitriones].setPuntuacion(puntuacion);
                anfitriones[contadorAnfitriones].setContraseña(contrasena);

                contadorAnfitriones++;
            }
        }
        archivoAnfitriones.close();
    } else {
        cout << "No se pudo abrir 'anfitriones.txt'" << endl;
    }

    ifstream archivoHuespedes("huespedes.txt");
    if (archivoHuespedes.is_open()) {
        string linea;
        while (getline(archivoHuespedes, linea)) {
            incrementarIteraciones();
            if (linea.empty() || contadorHuespedes >= capacidad) break;

            string documento = "";
            string antiguedadStr = "";
            string puntuacionStr = "";
            string contrasena = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < (int)linea.length(); i++) {
                incrementarIteraciones();
                if (linea[i] == ',') {
                    if (campo == 0) documento = campoActual;
                    else if (campo == 1) antiguedadStr = campoActual;
                    else if (campo == 2) puntuacionStr = campoActual;

                    campoActual = "";
                    campo++;
                } else {
                    campoActual += linea[i];
                }
            }
            contrasena = campoActual;

            if (!documento.empty()) {
                huespedes[contadorHuespedes].setDocumento(documento);
                huespedes[contadorHuespedes].setAntiguedad(antiguedadStr);

                float puntuacion = 0.0;
                if (!puntuacionStr.empty()) {
                    puntuacion = stof(puntuacionStr);
                }
                huespedes[contadorHuespedes].setPuntuacion(puntuacion);
                huespedes[contadorHuespedes].setContraseña(contrasena);

                contadorHuespedes++;
            }
        }
        archivoHuespedes.close();
    } else {
        cout << "No se pudo abrir 'huespedes.txt'" << endl;
    }

    ifstream archivoAlojamientos("alojamientos.txt");
    if (archivoAlojamientos.is_open()) {
        string linea;
        while (getline(archivoAlojamientos, linea)) {
            incrementarIteraciones();
            if (linea.empty() || contadorAlojamientos >= capacidad) break;

            string id = "";
            string nombre = "";
            string precioStr = "";
            string tipo = "";
            string municipio = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < (int)linea.length(); i++) {
                incrementarIteraciones();
                if (linea[i] == ',') {
                    if (campo == 0) id = campoActual;
                    else if (campo == 1) nombre = campoActual;
                    else if (campo == 2) precioStr = campoActual;
                    else if (campo == 3) tipo = campoActual;

                    campoActual = "";
                    campo++;
                } else {
                    campoActual += linea[i];
                }
            }
            municipio = campoActual;

            if (!id.empty()) {
                int identificador = stoi(id);
                float precio = 0.0;
                if (!precioStr.empty()) {
                    precio = stof(precioStr);
                }

                alojamientos[contadorAlojamientos].setIdentificador(identificador);
                alojamientos[contadorAlojamientos].setNombre(nombre);
                alojamientos[contadorAlojamientos].setPrecioNoche(precio);
                alojamientos[contadorAlojamientos].setTipo(tipo);
                alojamientos[contadorAlojamientos].setMunicipio(municipio);

                contadorAlojamientos++;
            }
        }
        archivoAlojamientos.close();
    } else {
        cout << "No se pudo abrir 'alojamientos.txt'" << endl;
    }

    ifstream archivoReservaciones("historico.txt");
    if (archivoReservaciones.is_open()) {
        string linea;
        while (getline(archivoReservaciones, linea)) {
            incrementarIteraciones();
            if (linea.empty() || contadorReservaciones >= capacidad) break;
            contadorReservaciones++;
        }
        archivoReservaciones.close();
    } else {
        cout << "No se pudo abrir 'historico.txt'" << endl;
    }
}

// Métodos públicos para medición de recursos
void SistemaUdestay::mostrarConsumoRecursos(const string& nombreFuncionalidad) {
    cout << "---------- CONSUMO DE RECURSOS --------------" << nombreFuncionalidad << " " << endl;
    cout << "Iteraciones locales: " << contadorIteracionesLocal << endl;
    cout << "Iteraciones globales: " << contadorIteracionesGlobal << endl;
    cout << "Memoria total estimada: " << obtenerMemoriaTotal() << " bytes" << endl;
    cout << "-----------------------------------------------------------------" << endl;
}

void SistemaUdestay::iniciarMedicion() {
    resetearContadorLocal();
    cout << "Iniciando medición de recursos..." << endl;
}

void SistemaUdestay::finalizarMedicion(const string& nombreFuncionalidad) {
    cout << "Finalizando medición de recursos..." << endl;
    mostrarConsumoRecursos(nombreFuncionalidad);
}

long long SistemaUdestay::obtenerIteracionesTotales() {
    return contadorIteracionesGlobal;
}

long long SistemaUdestay::obtenerMemoriaTotal() {
    long long memoriaTotal = 0;

    memoriaTotal += calcularMemoriaArray(capacidad, sizeof(Anfitrion));
    memoriaTotal += calcularMemoriaArray(capacidad, sizeof(Huesped));
    memoriaTotal += calcularMemoriaArray(capacidad, sizeof(Alojamiento));
    memoriaTotal += calcularMemoriaArray(capacidad, sizeof(Reservacion));
    memoriaTotal += calcularMemoriaObjetos();

    return memoriaTotal;
}

void SistemaUdestay::mostrarEstadisticasCompletas() {
    cout << "----------- ESTADÍSTICAS COMPLETAS DEL SISTEMA ---------" << endl;
    cout << "Capacidad máxima: " << capacidad << endl;
    cout << "Anfitriones registrados: " << contadorAnfitriones << endl;
    cout << "Huéspedes registrados: " << contadorHuespedes << endl;
    cout << "Alojamientos registrados: " << contadorAlojamientos << endl;
    cout << "Reservaciones activas: " << contadorReservaciones << endl;
    cout << "----------------------------------------" << endl;
    cout << "Memoria total utilizada: " << obtenerMemoriaTotal() << " bytes" << endl;
    cout << "Iteraciones totales realizadas: " << contadorIteracionesGlobal << endl;
    cout << "------------------------------------------------------------------" << endl;
}
