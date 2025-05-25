#include "sistemaudestay.h"
#include <iostream>
#include <fstream>
#include <string>

// Constructor por defecto
SistemaUdestay::SistemaUdestay() {
    capacidad = 10;
    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    anfitriones = new Anfitrion[capacidad];
    huespedes = new Huesped[capacidad];
    alojamientos = new Alojamiento[capacidad];
    historico = new Historico();
}

// Constructor con parámetros
SistemaUdestay::SistemaUdestay(int nuevaCapacidad) {
    capacidad = nuevaCapacidad;
    contadorAnfitriones = 0;
    contadorHuespedes = 0;
    contadorAlojamientos = 0;
    anfitriones = new Anfitrion[capacidad];
    huespedes = new Huesped[capacidad];
    alojamientos = new Alojamiento[capacidad];
    historico = new Historico();
}

// Destructor
SistemaUdestay::~SistemaUdestay() {
    delete[] anfitriones;
    delete[] huespedes;
    delete[] alojamientos;
    delete historico;
}

// Setter  y getter para anfitriones
void SistemaUdestay::setAnfitriones(Anfitrion* nuevosAnfitriones) {
    delete[] anfitriones;
    anfitriones = nuevosAnfitriones;
}

Anfitrion* SistemaUdestay::getAnfitriones() {
    return anfitriones;
}


// Setter y getter para huespedes
void SistemaUdestay::setHuespedes(Huesped* nuevosHuespedes) {
    delete[] huespedes;
    huespedes = nuevosHuespedes;
}

Huesped* SistemaUdestay::getHuespedes() {
    return huespedes;
}


// Setter y getter para alojamientos
void SistemaUdestay::setAlojamientos(Alojamiento* nuevosAlojamientos) {
    delete[] alojamientos;
    alojamientos = nuevosAlojamientos;
}

Alojamiento* SistemaUdestay::getAlojamientos() {
    return alojamientos;
}


// Setter y getter para historico
void SistemaUdestay::setHistorico(Historico* nuevoHistorico) {
    delete historico;
    historico = nuevoHistorico;
}

Historico* SistemaUdestay::getHistorico() {
    return historico;
}


// Setter y getter  para contadorAnfitriones
void SistemaUdestay::setContadorAnfitriones(int nuevoContador) {
    contadorAnfitriones = nuevoContador;
}

int SistemaUdestay::getContadorAnfitriones() {
    return contadorAnfitriones;
}


// Setter y getter para contadorHuespedes
void SistemaUdestay::setContadorHuespedes(int nuevoContador) {
    contadorHuespedes = nuevoContador;
}

int SistemaUdestay::getContadorHuespedes() {
    return contadorHuespedes;
}


// Setter y getter  para contadorAlojamientos
void SistemaUdestay::setContadorAlojamientos(int nuevoContador) {
    contadorAlojamientos = nuevoContador;
}

int SistemaUdestay::getContadorAlojamientos() {
    return contadorAlojamientos;
}


// Setter y getter  para capacidad
void SistemaUdestay::setCapacidad(int nuevaCapacidad) {
    capacidad = nuevaCapacidad;
}

int SistemaUdestay::getCapacidad() {
    return capacidad;
}


// Método para registrar un anfitrión
void SistemaUdestay::registrarAnfitrion(string& documento) {
    // Verificar si ya existe
    for (int i = 0; i < contadorAnfitriones; i++) {
        if (anfitriones[i].getDocumento() == documento) {
            cout << "El anfitrión con documento " << documento << " ya está registrado." << endl;
            return;
        }
    }

    // Verificar capacidad
    if (contadorAnfitriones >= capacidad) {
        cout << "No hay capacidad para más anfitriones." << endl;
        return;
    }

    // Crear nuevo anfitrión
    anfitriones[contadorAnfitriones].setDocumento(documento);
    contadorAnfitriones++;

    cout << "Anfitrión con documento " << documento << " registrado exitosamente." << endl;
}

// Método para registrar un huésped
void SistemaUdestay::registrarHuesped(string& documento) {
    // Verificar si ya existe
    for (int i = 0; i < contadorHuespedes; i++) {
        if (huespedes[i].getDocumento() == documento) {
            cout << "El huésped con documento " << documento << " ya está registrado." << endl;
            return;
        }
    }

    // Verificar capacidad
    if (contadorHuespedes >= capacidad) {
        cout << "No hay capacidad para más huéspedes." << endl;
        return;
    }

    // Crear nuevo huésped
    huespedes[contadorHuespedes].setDocumento(documento);
    contadorHuespedes++;

    cout << "Huésped con documento " << documento << " registrado exitosamente." << endl;
}

// Método para agregar un alojamiento
void SistemaUdestay::agregarAlojamiento(Alojamiento* alojamiento) {
    // Verificar si ya existe
    for (int i = 0; i < contadorAlojamientos; i++) {
        if (alojamientos[i].getIdentificador() == alojamiento->getIdentificador()) {
            cout << "El alojamiento con identificador " << alojamiento->getIdentificador() << " ya está registrado." << endl;
            return;
        }
    }

    // Verificar capacidad
    if (contadorAlojamientos >= capacidad) {
        cout << "No hay capacidad para más alojamientos." << endl;
        return;
    }

    // Agregar nuevo alojamiento
    alojamientos[contadorAlojamientos] = *alojamiento;
    contadorAlojamientos++;

    cout << "Alojamiento con identificador " << alojamiento->getIdentificador() << " registrado exitosamente." << endl;
}

// Método para buscar alojamientos por ubicación
void SistemaUdestay::buscarAlojamientoPorUbicacion(string& ubicacion) {
    cout << "Alojamientos en " << ubicacion << ":" << endl;

    bool encontrado = false;
    for (int i = 0; i < contadorAlojamientos; i++) {
        // Buscar en municipio o departamento
        if (alojamientos[i].getMunicipio() == ubicacion || alojamientos[i].getDepartamento() == ubicacion) {
            cout << i + 1;
            cout << ". ";
            cout << alojamientos[i].getNombre();
            cout << " (ID: ";
            cout << alojamientos[i].getIdentificador();
            cout << ")";
            cout << " - $";
            cout << alojamientos[i].getPrecioNoche();
            cout << " por noche" << endl;

        }
    }

    if (!encontrado) {
        cout << "No se encontraron alojamientos en " << ubicacion << endl;
    }
}

// Método para mostrar estadísticas de reservas
void SistemaUdestay::mostrarEstadisticaReservas() {
    cout << "--------------- ESTADÍSTICAS DE RESERVAS --------------" << endl;
    cout << "Total de anfitriones: " << contadorAnfitriones << endl;
    cout << "Total de huéspedes: " << contadorHuespedes << endl;
    cout << "Total de alojamientos: " << contadorAlojamientos << endl;




}

// Método para actualizar el histórico
void SistemaUdestay::actualizarHistorico(Fecha* corteDeFecha) {
    cout << "Actualizando histórico con fecha de corte: " << corteDeFecha->getDia() << "/"
         << corteDeFecha->getMes() << "/" << corteDeFecha->getAño() << endl;


    cout << "Histórico actualizado exitosamente." << endl;
}

// Método para guardar datos
void SistemaUdestay::guardarDatos() {
    cout << "Guardando datos del sistema..." << endl;

    ofstream archivo("udestay_datos.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar datos." << endl;
        return;
    }

    // Guardar anfitriones
    archivo << "ANFITRIONES:" << endl;
    archivo << contadorAnfitriones << endl;
    for (int i = 0; i < contadorAnfitriones; i++) {
        archivo << anfitriones[i].getDocumento() << endl;

    }

    // Guardar huéspedes
    archivo << "HUESPEDES:" << endl;
    archivo << contadorHuespedes << endl;
    for (int i = 0; i < contadorHuespedes; i++) {
        archivo << huespedes[i].getDocumento() << endl;

    }

    // Guardar alojamientos
    archivo << "ALOJAMIENTOS:" << endl;
    archivo << contadorAlojamientos << endl;
    for (int i = 0; i < contadorAlojamientos; i++) {
        archivo << alojamientos[i].getIdentificador() << endl;
        archivo << alojamientos[i].getNombre() << endl;
        archivo << alojamientos[i].getPrecioNoche() << endl;

    }

    archivo.close();
    cout << "Datos guardados exitosamente." << endl;
}

// Método para cargar datos
void SistemaUdestay::cargarDatos() {
    cout << "Cargando datos del sistema..." << endl;

    ifstream archivo("udestay_datos.txt");
    if (!archivo.is_open()) {
        cout << "No se encontró archivo de datos para cargar." << endl;
        return;
    }

    string linea;

    // Cargar anfitriones
    getline(archivo, linea);
    getline(archivo, linea);
    int numAnfitriones = stoi(linea);

    for (int i = 0; i < numAnfitriones; i++) {
        getline(archivo, linea);
        string documento = linea;


        // Registrar anfitrión
        registrarAnfitrion(documento);
    }

    // Cargar huéspedes
    getline(archivo, linea);
    getline(archivo, linea);
    int numHuespedes = stoi(linea);

    for (int i = 0; i < numHuespedes; i++) {
        getline(archivo, linea);
        string documento = linea;


        // Registrar huésped
        registrarHuesped(documento);
    }

    // Cargar alojamientos
    getline(archivo, linea);
    getline(archivo, linea);
    int numAlojamientos = stoi(linea);

    for (int i = 0; i < numAlojamientos; i++) {
        getline(archivo, linea);
        int id = stoi(linea);

        getline(archivo, linea);
        string nombre = linea;

        getline(archivo, linea);
        float precio = stof(linea);



        // Crear y agregar alojamiento
        string amenidades = "";
        string departamento = "";
        string municipio = "";
        string direccion = "";
        string tipo = "";
        bool disponible = true;

        Alojamiento* nuevoAlojamiento = new Alojamiento(nombre, id, precio, amenidades, departamento, municipio, direccion, tipo, disponible);
        agregarAlojamiento(nuevoAlojamiento);
        delete nuevoAlojamiento;
    }

    archivo.close();
    cout << "Datos cargados exitosamente." << endl;
}
