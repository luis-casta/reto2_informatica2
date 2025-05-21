#include <iostream>
#include "alojamiento.h"

using namespace std;

int main()
{
    Alojamiento a;

    a.setNombre("Finca El Retiro");
    a.setDepartamento("Antioquia");
    a.setMunicipio("Rionegro");
    a.setDireccion("Km 5 vía Rionegro");
    a.setTipo("Casa campestre");
    a.setIdentificador(101);
    a.setPrecioPorNoche(150000);

    a.mostrarDatos();



    return 0;
}
