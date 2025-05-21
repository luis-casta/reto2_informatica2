#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int* dia;
    int* mes;
    int* anio;

public:
    Fecha(int d = 1, int m = 1, int a = 2000);
    Fecha(const Fecha& otra); // Constructor de copia
    ~Fecha(); // Destructor

    // Getters
    int getDia() const;
    int getMes() const;
    int getAnio() const;

    // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);

    // Métodos clave
    bool esValida() const;
    void actualizarFecha(int n);

};

#endif
