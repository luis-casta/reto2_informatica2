#ifndef FECHA_H
#define FECHA_H
#include <string>

using namespace std;

class Fecha {
private:
    int dia;
    string mes;
    int año;

public:
    Fecha();
    Fecha(int nuevoDia, string &nuevoMes, int nuevoAño);
    ~Fecha(); // Destructor

    // setters y gueters para dia
    void setDia(int nuevoDia);
    int getDia();

    // setters y gueters para mes
    void setMes(string& nuevoDia);
    string getMes();

    // setters y gueters para año
    void setAño(string &nuevoAño);
    int getAño();

    bool esValida();
    string actualizarFecha();
    int diasEntreFechas(Fecha& otraFecha);
};

#endif
