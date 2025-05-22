#include "fecha.h"
#include <iostream>

using namespace std;

// constructor por defecto 
Fecha::Fecha(){
    dia = 1;
    mes = "enero";
    año = 2025;
}

// contructor sobreacargado 
Fecha::Fecha(int nuevoDia, string& nuevoMes, int nuevoAño){
    dia = nuevoDia;
    mes = nuevoMes;
    año = nuevoAño;
}

// destructor
Fecha::~Fecha(){}

// metodos setter y gueter para dia 
void Fecha::setDia(int nuevoDia){
    dia = nuevoDia;
}
int Fecha::getDia(){
    return dia;
}

// metodos setter y gueters para mes 
void Fecha::setMes(string& nuevoMes){
    mes = nuevoMes;
}
string Fecha::getMes(){
    return mes;
}

// metodos setter y gueter para año
void Fecha::setAño(string &nuevoAñoTexto) {
    año = stoi(nuevoAñoTexto);
}
int Fecha::getAño(){
    return año;
}

// convertir mes a numero
int convertirMesANumero(string mes){
  if (mes == "enero")
      return 1;
  if (mes == "febrero")
      return 2;
  if (mes == "marzo")
      return 3;
  if (mes == "abril")
      return 4;
  if (mes == "mayo")
      return 5;
  if (mes == "junio")
      return 6;
  if (mes == "julio")
      return 7;
  if (mes == "agosto")
      return 8;
  if (mes == "septiembre")
      return 9;
  if (mes == "octubre")
      return 10;
  if (mes == "noviembre")
      return 11;
  if (mes == "diciembre")
      return 12;
}

// actualizar fecha 
string Fecha::actualizarFecha(){
    return to_string(dia) + " de " + mes + " de " + to_string(año);
}

// validar si la fecha es válida 
// partimos de que todos los meses tienen 30 dias 
bool Fecha::esValida(){
    int mesNum = convertirMesANumero(mes);
    return (mesNum >= 1 && mesNum <= 12 && dia >= 1 && dia <= 30);
}

// verificar dias entre fechas 
int Fecha::diasEntreFechas(Fecha &otraFecha){
    int mes1 = convertirMesANumero(mes);
    int mes2 = convertirMesANumero(otraFecha.mes);

    int total1 = año * 360 + mes1 * 30 + dia;
    int total2 = otraFecha.año * 360 + mes2 * 30 + otraFecha.dia;

    int diferencia = total2 - total1;
    if (diferencia < 0){
        diferencia = -diferencia;
    }
    return diferencia;
}