#include "fecha.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor por defecto
Fecha::Fecha(){
    dia = 1;
    mes = "enero";
    año = 2024;
}

// Constructor sobrecargado (con parametros)
Fecha::Fecha(int nuevoDia, string &nuevoMes, int nuevoAño){
    dia = nuevoDia;
    mes = nuevoMes;
    año = nuevoAño;
}

// Destructor
Fecha::~Fecha(){}

// Setter y getter para dia
void Fecha::setDia(int nuevoDia){
    dia = nuevoDia;
}
int Fecha::getDia(){
    return dia;
}

// Setter y getter para mes
void Fecha::setMes(string& nuevoMes){
    mes = nuevoMes;
}
string Fecha::getMes(){
    return mes;
}

// Setter y getter para año
void Fecha::setAño(string &nuevoAño){
    año = stoi(nuevoAño);
}
int Fecha::getAño(){
    return año;
}

// Método para validar si la fecha es válida
bool Fecha::esValida(){
    // Verificar año válido
    if(año < 1){
        return false;
    }

    // Verificar día válido
    if(dia < 1 || dia > 31){
        return false;
    }

    // Verificar mes válido y días correspondientes
    if(mes == "enero" || mes == "marzo" || mes == "mayo" || mes == "julio" ||
        mes == "agosto" || mes == "octubre" || mes == "diciembre"){
        return dia <= 31;
    }
    else if(mes == "abril" || mes == "junio" || mes == "septiembre" || mes == "noviembre"){
        return dia <= 30;
    }
    else if(mes == "febrero"){
        // Verificar año bisiesto
        bool esBisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
        if(esBisiesto){
            return dia <= 29;
        }
        else{
            return dia <= 28;
        }
    }
    else{
        return false;
    }
}

// Método para actualizar fecha (convertir a string)
string Fecha::actualizarFecha(){
    return to_string(dia) + " de " + mes + " de " + to_string(año);
}

// Método para verificar si esta fecha intercepta con otra fecha por un número de noches
bool Fecha::interceptaCon(Fecha *ptrFecha, int noches){
    if(ptrFecha == nullptr || noches <= 0){
        return false;
    }

    // Convertir fechas a días del año para comparar más fácilmente
    int diasEstaFecha = convertirADias();
    int diasOtraFecha = ptrFecha->convertirADias();

    // Si las fechas están en años diferentes, comparación más compleja
    if(año != ptrFecha->getAño()){
        return false; // Implementación simple: no intercepta si son años diferentes
    }

    // Verificar si hay solapamiento
    int finEstaReserva = diasEstaFecha + noches - 1;
    int finOtraReserva = diasOtraFecha + noches - 1;

    // Hay intercepto si:
    // - Esta fecha empieza antes de que termine la otra
    // - Y la otra fecha empieza antes de que termine esta
    return (diasEstaFecha <= finOtraReserva) && (diasOtraFecha <= finEstaReserva);
}

// Método auxiliar privado para convertir fecha a días del año
int Fecha::convertirADias(){
    int diasDelAño = 0;

    // Sumar días de los meses anteriores
    string meses[] = {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                      "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Verificar si es año bisiesto
    bool esBisiesto = (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
    if(esBisiesto){
        diasPorMes[1] = 29;
    }

    // Encontrar el índice del mes actual
    int indiceMes = -1;
    for(int i = 0; i < 12; i++){
        if(meses[i] == mes){
            indiceMes = i;
            break;
        }
    }

    if(indiceMes == -1){
        return 0; // Mes inválido
    }

    // Sumar días de meses anteriores
    for(int i = 0; i < indiceMes; i++){
        diasDelAño += diasPorMes[i];
    }

    // Sumar días del mes actual
    diasDelAño += dia;

    return diasDelAño;
}
