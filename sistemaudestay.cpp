#include "sistemaudestay.h"
#include <iostream>
#include <fstream>
using namespace std;

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
}

SistemaUdestay::~SistemaUdestay() {
    delete[] anfitriones;
    delete[] huespedes;
    delete[] alojamientos;
    delete[] reservaciones;
    delete historico;
}

bool SistemaUdestay::documentoExiste(string& documento, bool esAnfitrion) {
    if (esAnfitrion) {
        for (int i = 0; i < contadorAnfitriones; i++) {
            if (anfitriones[i].getDocumento() == documento) {
                return true;
            }
        }
    } else {
        for (int i = 0; i < contadorHuespedes; i++) {
            if (huespedes[i].getDocumento() == documento) {
                return true;
            }
        }
    }
    return false;
}

bool SistemaUdestay::alojamientoDisponible(int idAlojamiento, Fecha* inicio, int noches) {
    for (int i = 0; i < contadorAlojamientos; i++) {
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

// validar documento
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



// buscar alojamiento por ubicacion
void SistemaUdestay::buscarAlojamientoPorUbicacion(string& ubicacion) {
    bool encontrado = false;

    cout << "Alojamientos en " << ubicacion << ":" << endl;
    cout << "----------------------------------------" << endl;

    for (int i = 0; i < contadorAlojamientos; i++) {
        // Verificar si coincide con municipio o departamento
        if (alojamientos[i].getMunicipio() == ubicacion ||
            alojamientos[i].getDepartamento() == ubicacion) {

            cout << "ID: " << alojamientos[i].getIdentificador() << endl;
            cout << "Nombre: " << alojamientos[i].getNombre() << endl;
            cout << "Precio por noche: $" << alojamientos[i].getPrecioNoche() << endl;
            cout << "Tipo: " << alojamientos[i].getTipo() << endl;
            cout << "Amenidades: " << alojamientos[i].getAmenidades() << endl;
            cout << "----------------------------------------" << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron alojamientos en la ubicacion especificada." << endl;
    }
}

// mostrar estadisticas de la reserva
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
        Alojamiento* alojamiento = reservaciones[i].getAlojamiento();
        string tipo = alojamiento->getTipo();

        // Incrementar contador por tipo
        if (tipo == "casa"){
            reservasPorTipo[0]++;
        }else {
            reservasPorTipo[1]++;
        }


        // Calcular ingresos
        ingresosTotales += reservaciones[i].calcularCosto();

        // Estadísticas por mes (simplificado)
        Fecha* fechaInicio = reservaciones[i].getInicio();
        string mes = fechaInicio->getMes();
        // Convertir mes a índice (simplificado)
        int mesIndice = 0;
        if (mes == "enero") mesIndice = 0;
        else if (mes == "febrero") mesIndice = 1;
        // ... y así sucesivamente para todos los meses

        reservasPorMes[mesIndice]++;
    }

    // Mostrar estadísticas
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

// Implementación de métodos de autenticación
#include <fstream>
#include <string>
using namespace std;

bool SistemaUdestay::verificarAnfitrion(string& documento) {
    ifstream archivo("anfitriones.txt"); // Archivo específico para anfitriones
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir anfitriones.txt." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t pos = linea.find(','); // Busca la primera coma
        if (pos == string::npos) continue; // Si no hay coma, ignora la línea

        string cedula = linea.substr(0, pos); // Extrae la cédula (primer campo)
        if (cedula == documento) {
            archivo.close();
            return true; // ¡Cédula encontrada!
        }
    }

    archivo.close();
    return false; // Cédula no registrada
}

// validar contraseña anfitrión
bool SistemaUdestay::validarContraseñaAnfitrion(string& documento, string& claveIngresada) {
    ifstream archivo("anfitriones.txt");
    if (!archivo.is_open()) {
        cout << "Error: No se pudo abrir anfitriones.txt." << endl;
        return false;
    }

    string linea;
    while (getline(archivo, linea)) {
        size_t posUltimaComa = linea.find_last_of(','); // Última coma (la clave está después)
        if (posUltimaComa == string::npos) continue;

        string cedula = linea.substr(0, linea.find(',')); // Extrae cédula
        string clave = linea.substr(posUltimaComa + 1);   // Extrae clave (después de la última coma)

        if (cedula == documento && clave == claveIngresada) {
            archivo.close();
            return true; // Cédula y clave coinciden
        }
    }

    archivo.close();
    return false; // Clave incorrecta o cédula no existe
}
bool SistemaUdestay::verificarHuesped(string& documento) {
    return documentoExiste(documento, false);
}

bool SistemaUdestay::validarContraseñaHuesped(string& documento, string& contraseña) {
    for (int i = 0; i < contadorHuespedes; i++) {
        if (huespedes[i].getDocumento() == documento) {
            return huespedes[i].verificarCredenciales(contraseña);
        }
    }
    return false;
}

// actualizar el historico
void SistemaUdestay::actualizarHistorico(Fecha* fechaCorte) {
    bool encontrado = false;

    cout << "Actualizando historico con fecha de corte..." << endl;

    for (int i = 0; i < contadorReservaciones; i++) {
        Fecha* fechaInicio = reservaciones[i].getInicio();

        // Verificar si la reservación ya pasó
        if (fechaInicio->interceptaCon(fechaCorte, 0)) {
            // La reservación ya pasó, moverla al histórico
            historico->agregarReserva(&reservaciones[i]);

            // Eliminar de reservaciones activas (
            for (int j = i; j < contadorReservaciones - 1; j++) {
                reservaciones[j] = reservaciones[j + 1];
            }

            contadorReservaciones--;
            i--; // Ajustar índice después de eliminar
            encontrado = true;
        }
    }

    if (encontrado) {
        cout << "Historico actualizado exitosamente." << endl;
    } else {
        cout << "No se encontraron reservaciones para el anfitrion en el rango de fechas especificado." << endl;
    }
}

// guardar datos
void SistemaUdestay::guardarDatos() {
    // 1. Guardar anfitriones
    ofstream archivoAnfitriones("anfitriones.txt");
    if (archivoAnfitriones.is_open()) {
        for (int i = 0; i < contadorAnfitriones; i++) {
            archivoAnfitriones << anfitriones[i].getDocumento() << ","
                               << anfitriones[i].getAntiguedad() << ","
                               << anfitriones[i].getPuntuacion() << ","
                               << anfitriones[i].getContraseña() << "\n";
        }
        archivoAnfitriones.close();
    } else {
        cout << "Error al guardar datos de anfitriones" << endl;
    }

    // 2. Guardar huéspedes
    ofstream archivoHuespedes("huespedes.txt");
    if (archivoHuespedes.is_open()) {
        for (int i = 0; i < contadorHuespedes; i++) {
            archivoHuespedes << huespedes[i].getDocumento() << ","
                             << huespedes[i].getAntiguedad() << ","
                             << huespedes[i].getPuntuacion() << ","
                             << huespedes[i].getContraseña() << "\n";
        }
        archivoHuespedes.close();
    } else {
        cout << "Error al guardar datos de huéspedes" << endl;
    }

    // 3. Guardar alojamientos
    ofstream archivoAlojamientos("alojamientos.txt");
    if (archivoAlojamientos.is_open()) {
        for (int i = 0; i < contadorAlojamientos; i++) {
            archivoAlojamientos << alojamientos[i].getIdentificador() << ","
                                << alojamientos[i].getNombre() << ","
                                << alojamientos[i].getPrecioNoche() << ","
                                << alojamientos[i].getTipo() << ","
                                << alojamientos[i].getMunicipio() << "\n";
                                //<< alojamientos[i].get() << "\n";
        }
        archivoAlojamientos.close();
    } else {
        cout << "Error al guardar datos de alojamientos" << endl;
    }

    // 4. Guardar reservaciones activas
    ofstream archivoReservaciones("reservaciones.txt");
    if (archivoReservaciones.is_open()) {
        for (int i = 0; i < contadorReservaciones; i++) {
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

    // 5. Guardar histórico
    ofstream archivoHistorico("historico.txt");
    if (archivoHistorico.is_open()) {

        archivoHistorico.close();
    } else {
        cout << "Error al guardar datos históricos" << endl;
    }

    cout << "Datos guardados exitosamente en archivos." << endl;
}

// cargar datos
void SistemaUdestay::cargarDatos() {
    using namespace std;

    //cout << "Cargando datos del sistema..." << endl;

    // Reiniciar contadores
    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    contadorReservaciones = 0;

    // -------- Cargar anfitriones --------
    ifstream archivoAnfitriones("anfitriones.txt");
    if (archivoAnfitriones.is_open()) {
        string linea;
        while (getline(archivoAnfitriones, linea)) {
            if (linea.empty() || contadorAnfitriones >= capacidad) break;


            string documento = "";
            string antiguedadStr = "";
            string puntuacionStr = "";
            string contrasena = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < linea.length(); i++) {
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
            contrasena = campoActual; // Último campo

            if (!documento.empty()) {
                anfitriones[contadorAnfitriones].setDocumento(documento);
                anfitriones[contadorAnfitriones].setAntiguedad(antiguedadStr);

                // Convertir string a float manualmente
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
        //cout << "Cargados " << contadorAnfitriones << " anfitriones." << endl;
    } else {
        cout << "No se pudo abrir 'anfitriones.txt'" << endl;
    }

    // -------- Cargar huéspedes --------
    ifstream archivoHuespedes("huespedes.txt");
    if (archivoHuespedes.is_open()) {
        string linea;
        while (getline(archivoHuespedes, linea)) {
            if (linea.empty() || contadorHuespedes >= capacidad) break;

            // Parsear manualmente
            string documento = "";
            string antiguedadStr = "";
            string puntuacionStr = "";
            string contrasena = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < linea.length(); i++) {
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
            contrasena = campoActual; // Último campo

            if (!documento.empty()) {
                huespedes[contadorHuespedes].setDocumento(documento);
                huespedes[contadorHuespedes].setAntiguedad(antiguedadStr);

                // Convertir string a float manualmente
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
        //cout << "Cargados " << contadorHuespedes << " huéspedes." << endl;
    } else {
        cout << "No se pudo abrir 'huespedes.txt'" << endl;
    }

    // -------- Cargar alojamientos --------
    ifstream archivoAlojamientos("alojamientos.txt");
    if (archivoAlojamientos.is_open()) {
        string linea;
        while (getline(archivoAlojamientos, linea)) {
            if (linea.empty() || contadorAlojamientos >= capacidad) break;

            // Parsear manualmente
            string id = "";
            string nombre = "";
            string precioStr = "";
            string tipo = "";
            string municipio = "";

            int campo = 0;
            string campoActual = "";

            for (int i = 0; i < linea.length(); i++) {
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
            municipio = campoActual; // Último campo

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
        //cout << "Cargados " << contadorAlojamientos << " alojamientos." << endl;
    } else {
        cout << "No se pudo abrir 'alojamientos.txt'" << endl;
    }

    // -------- Cargar  historico --------
    ifstream archivoHistorico("historico.txt");
    if (archivoReservaciones.is_open()) {
        string linea;
        while (getline(archivoHistorico, linea)) {
            if (linea.empty() || contadorHistorico >= capacidad) break;


            contadorHistorico++;
        }
        archivoHistorico.close();
        //cout << "Cargadas " << contadorReservaciones << " reservaciones." << endl;
    } else {
        cout << "No se pudo abrir 'historico.txt" << endl;
    }

}

