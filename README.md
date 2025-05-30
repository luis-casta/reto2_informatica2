
# Explicación del Diagrama UML - UdeAStay

Este sistema fue diseñado bajo los principios de la programación orientada a objetos en C++, representando las entidades del dominio del problema (estadías hogareñas) y sus relaciones, así como las funcionalidades requeridas.

Esta posible solución fué planteada tratando de optimizar los recursos de memoria del sistema, por eso proponemos usar punteros y memoria dinamica, nos parece lo más optimo para esta solución, aunque tenemos duda si haciendolo con string y pasando los objetos como referencia sea también una  buena manera de abordar este desafio, y en que nos podria ayudar ( si así lo fuera) a optimizar los recursos de mejor forma. 

---

## 1. Clase: `Fecha`

Representa una fecha del calendario.

**Responsabilidades:**
- Almacena día, mes y año.
- Permite comparar fechas y sumar días.
- Muestra la fecha en formato textual requerido:  
  `"lunes, 13 de mayo del 2025"`.

---

## 2. Clase: `Alojamiento`

Representa una propiedad que puede ser reservada (casa o apartamento).

**Atributos:** nombre, código, anfitrión, ubicación, precio, tipo, amenidades, fechas reservadas.

**Relaciones:**
- Está asociada a un `Anfitrion`.
- Participa en múltiples `Reservacion`.

**Responsabilidades:**
- Verificar disponibilidad en fechas.
- Mostrar su información detallada.

---

## 3. Clase: `Anfitrion`

Representa a la persona que administra alojamientos en la plataforma.

**Atributos:** documento, antigüedad, puntuación, lista de alojamientos.

**Relaciones:**
- Relación uno a muchos con `Alojamiento`.

**Responsabilidades:**
- Agregar y listar alojamientos.
- Consultar reservaciones asociadas a sus propiedades.

---

## 4. Clase: `Huesped`

Representa a un usuario que realiza reservaciones en la plataforma.

**Atributos:** documento, antigüedad, puntuación, lista de reservaciones.

**Relaciones:**
- Relación uno a muchos con `Reservacion`.

**Responsabilidades:**
- Validar si tiene conflictos de fechas.
- Agregar nuevas reservaciones.

---

## 5. Clase: `Reservacion`

Contiene toda la información sobre una reserva.

**Atributos:** código, fecha de inicio, duración, alojamiento, huésped, método de pago, fecha de pago, monto, anotaciones.

**Relaciones:**
- Asociada a un `Alojamiento`.
- Asociada a un `Huesped`.
- Usa objetos de tipo `Fecha`.

**Responsabilidades:**
- Calcular el costo total de la estadía.
- Generar un comprobante de reserva.

---

## 6. Clase: `Plataforma`

Clase controladora del sistema.

**Atributos:** listas de anfitriones, huéspedes, alojamientos y reservaciones.

**Responsabilidades:**
- Iniciar sesión según el tipo de usuario.
- Realizar reservaciones.
- Anular reservaciones.
- Consultar reservaciones por anfitrión.
- Actualizar el histórico.
- Medir consumo de recursos.

---

## Relaciones generales

- `Anfitrion` ➝ tiene múltiples `Alojamiento`.
- `Huesped` ➝ tiene múltiples `Reservacion`.
- `Reservacion` ➝ se asocia a `Alojamiento` y `Huesped`.
- Todas las clases se gestionan desde `Plataforma`.

---


