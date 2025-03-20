#include <iostream>
#include <chrono>

using namespace std;

// Función recursiva para comparar dos cadenas de texto
bool compararCadenas(const char* str1, const char* str2) {
    // Caso base: si ambos caracteres son el terminador '\0', las cadenas son iguales
    if (*str1 == '\0' && *str2 == '\0') {
        return true;
    }
    // Si los caracteres actuales son diferentes, las cadenas no son iguales
    if (*str1 != *str2) {
        return false;
    }
    // Llamada recursiva avanzando en ambas cadenas
    return compararCadenas(str1 + 1, str2 + 1);
}

int main() {
    // Definición de cadenas de al menos 64 caracteres
    const char* cadena1 = "Esta es una cadena de prueba con más de sesenta y cuatro caracteres.";
    const char* cadena2 = "Esta es una cadena de prueba con más de sesenta y cuatro caracteres.";
    const char* cadena3 = "Esta es otra cadena diferente que cumple con la cantidad de caracteres.";

    // Medición del tiempo de ejecución para la comparación
    auto startTime = chrono::high_resolution_clock::now();
    bool resultado1 = compararCadenas(cadena1, cadena2);
    auto endTime = chrono::high_resolution_clock::now();
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    
    cout << "Comparación 1 (igualdad): " << (resultado1 ? "true" : "false") << endl;
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;
    
    // Medición para una comparación negativa
    startTime = chrono::high_resolution_clock::now();
    bool resultado2 = compararCadenas(cadena1, cadena3);
    endTime = chrono::high_resolution_clock::now();
    elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    
    cout << "Comparación 2 (diferentes): " << (resultado2 ? "true" : "false") << endl;
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;
    
    return 0;
}
