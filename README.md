Cajero Automático en C++
Este proyecto es una simulación de un cajero automático implementado en C++ que permite realizar operaciones bancarias básicas a través de una interfaz de consola. La aplicación está diseñada para demostrar habilidades en programación, manejo de estructuras de datos y desarrollo de interfaces en modo texto utilizando funciones propias para posicionar y organizar la salida en consola.

Características
Interfaz Visual en Consola:
Utiliza funciones como gotoxy y cuadro para posicionar elementos y dibujar cuadros, ofreciendo una presentación visual organizada y atractiva en la consola.

Operaciones Bancarias Básicas:

Creación de cuentas: Registra datos personales (cédula, correo, número de celular) y asigna un número de cuenta.
Consignaciones (Depósitos): Permite depositar dinero en la cuenta, aplicando un gravamen del 4x1000 para montos mayores a $1000.
Consulta de saldo: Permite consultar el saldo de la cuenta, descontando una tarifa fija por consulta.
Retiros: Realiza extracciones de dinero, aplicando un cobro fijo por transacción.
Inscripción y realización de pagos: Permite registrar pagos (como facturas) y, posteriormente, realizar dichos pagos descontando del saldo de la cuenta.
Cancelación de cuenta: Simula el cierre de una cuenta mediante la retirada total del saldo y el borrado de los datos asociados.
Validación de Datos:
Se implementan múltiples funciones de validación para garantizar que los datos ingresados sean correctos (por ejemplo, validación de correos electrónicos, números enteros, números decimales y cadenas de texto).

Compatibilidad con C++98:
El proyecto ha sido adaptado para compilar en entornos que soportan C++98, utilizando conversiones mediante istringstream y evitando construcciones modernas como range‑based for o funciones propias de C++11.

Tecnologías
Lenguaje: C++
Librerías:
<iostream>
<string>
<conio.h>
<sstream>
<windows.h>
Instrucciones de Compilación y Uso
Compilación:
Se recomienda utilizar un compilador como TDM-GCC o Dev-C++ en Windows. Dado que el proyecto utiliza llamadas a system("cls") y system("pause"), está optimizado para sistemas operativos Windows.

Ejecución:
Una vez compilado, ejecuta el programa desde la consola. Se desplegará un menú principal que te permitirá seleccionar la operación que deseas realizar (crear cuenta, consignaciones, consultar saldo, retiros, inscribir pagos, realizar pagos o cancelar cuenta).

Interfaz de Usuario:
La aplicación utiliza una interfaz basada en texto con controles de posición y cuadros de diálogo para guiar al usuario a través de cada proceso.
