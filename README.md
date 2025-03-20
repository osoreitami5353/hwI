# Homework I
Estos códigos corresponden a las consignas del homework 1 de la materia Paradigmas de la Programación. El archivo de las consignas es `I102_Homework1.pdf`.

Cada ejercicio está implementado en archivos `.cpp`, siguiendo las especificaciones indicadas en el enunciado. Se incluyen instrucciones de compilación para cada uno.

## Ejercicio I
Este programa genera una matriz cuadrada de tamaño `n x n`, donde `n` es un número entero positivo mayor a 1. La matriz se llena con valores secuenciales comenzando desde `1`. Luego, se imprimen sus valores en orden normal y en orden inverso utilizando un solo ciclo.

* **Compilación y ejecución**
    g++ EjercicioI.cpp -Wall -g -o ejerI
    ./ejerI

## Ejericio II
Este ejercicio implementa un sistema de registro de eventos en un archivo de log.
Consta de dos partes:

* Parte a) Se crea un sistema de log básico que almacena mensajes con distintos niveles de severidad (DEBUG, INFO, WARNING, ERROR, CRITICAL).

* Parte b) Se amplía el sistema permitiendo:

    1. Registrar errores con información sobre el archivo y la línea de código.

    2. Registrar accesos de usuario con la etiqueta [SECURITY].

    3. Capturar un error en tiempo de ejecución y registrarlo antes de detener el programa.

Archivos
* ***_ejercicio2a.cpp:_** Implementación de la parte a.

* **_ejercicio2b.cpp:_** Implementación de la parte b.

* **Compilación y ejecución**
    g++ EjercicioIIa.cpp -Wall -g -o ejerIIa
    ./ejerIIa

    g++ EjercicioIIb.cpp -Wall -g -o ejerIIb
    ./ejerIIb

## Ejericio III
Este programa implementa una lista enlazada utilizando smart pointers (shared_ptr) para la gestión automática de memoria.
Incluye las siguientes operaciones:

* create_node(valor): Crea un nuevo nodo con el valor especificado.

* push_front(head, valor): Inserta un nodo al inicio de la lista.

* push_back(head, valor): Inserta un nodo al final de la lista.

* insert(head, valor, posición): Inserta un nodo en una posición específica. Si la posición es mayor que la longitud de la lista, se inserta al final.

* erase(head, posición): Elimina un nodo en la posición dada. Si la posición es mayor que la longitud de la lista, se elimina el último nodo.

* print_list(head): Imprime la lista enlazada.

* **Compilación y ejecución**
    g++ EjercicioIII.cpp -Wall -g -o ejerIII
    ./ejerIII

## Ejericio IV
Este ejercicio implementa una comparación de cadenas de texto utilizando recursión, y mide su tiempo de ejecución en diferentes escenarios.
Se divide en tres partes:

* Parte a) Implementa una función recursiva para comparar dos cadenas de caracteres.

* Parte b) Mide el tiempo de ejecución de la comparación y la optimiza usando constexpr para evaluación en tiempo de compilación.

* Parte c) Compara los tiempos de ejecución entre la evaluación normal y la evaluación en tiempo de compilación.

Archivos
* ***_Ejercicio4a.cpp:_*** Implementación de la parte a.

* ***_ejercicio4b.cpp:_*** Implementación de la parte b.

* ***_ejercicio4c.cpp:_*** Implementación de la parte c.

* **Compilación y ejecución**
    g++ EjercicioIVa.cpp -Wall -g -o ejerIVa
    ./ejerIVa

    g++ EjercicioIVb.cpp -Wall -g -o ejerIVb
    ./ejerIVb

    g++ EjercicioIVc.cpp -Wall -g -o ejerIVc
    ./ejerIVc