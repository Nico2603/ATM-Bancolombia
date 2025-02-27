# Cajero Automático en C++

Este proyecto es una simulación de un cajero automático en C++ con interfaz de consola. Permite crear cuentas, realizar consignaciones (gravamen 4x1000), retiros, consultar saldo, inscribir y realizar pagos, y cancelar cuentas. Desarrollado en C++98 para Windows.

## Características

- **Interfaz Visual:** Utiliza funciones como `gotoxy` y `cuadro` para organizar la salida en la consola.
- **Operaciones Bancarias:** Permite crear cuentas, hacer depósitos, retiros, consultas de saldo, y gestionar pagos.
- **Validación de Datos:** Implementa validaciones para garantizar la integridad de la información.
- **Compatibilidad:** Optimizado para compilar en C++98 en sistemas Windows.

## Requisitos

- Sistema operativo: Windows
- Compilador compatible con C++98 (ej. TDM-GCC o Dev-C++)

## Compilación y Ejecución

1. Abre el proyecto en tu entorno de desarrollo.
2. Compila el archivo fuente.
3. Ejecuta el programa desde la consola y sigue las instrucciones del menú.

## Uso

El programa muestra un menú principal en la consola que permite:
- **Crear Cuenta:** Registrar datos personales y generar un número de cuenta.
- **Consignaciones:** Depositar dinero con la aplicación de un gravamen (4x1000) para montos mayores a $1000.
- **Retiros:** Realizar extracciones con cobro fijo.
- **Consultar Saldo:** Verificar el saldo descontando una tarifa de consulta.
- **Gestión de Pagos:** Inscribir y efectuar pagos.
- **Cancelación de Cuenta:** Cerrar la cuenta retirando el saldo y eliminando los datos.

## Licencia

Este proyecto es de libre distribución. ¡Siéntete libre de usar y mejorar el código!

---

**Código C++ hecho por: Nicolas Ceballos Brito (1089096352)**
