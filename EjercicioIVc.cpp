#include <iostream>
#include <chrono>

using namespace std;

// Función recursiva para comparar dos cadenas de caracteres en tiempo de ejecución
bool compareStringsRuntime(const char* str1, const char* str2) {
    if (*str1 == '\0' && *str2 == '\0') return true; // Caso base: ambas cadenas terminan
    if (*str1 != *str2) return false; // Si los caracteres son diferentes, no son iguales
    return compareStringsRuntime(str1 + 1, str2 + 1); // Llamado recursivo con el siguiente carácter
}

// Función para medir el tiempo de ejecución de la comparación en tiempo de ejecución
void measureRuntime() {
    const char* text1 = "Este es un texto de prueba con más de 64 caracteres para comparar.";
    const char* text2 = "Este es un texto de prueba con más de 64 caracteres para comparar.";
    
    auto startTime = chrono::high_resolution_clock::now();
    bool result = compareStringsRuntime(text1, text2);
    auto endTime = chrono::high_resolution_clock::now();
    
    auto elapsedTime = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
    
    cout << "Comparación en tiempo de ejecución: " << (result ? "Iguales" : "Diferentes") << endl;
    cout << "Tiempo de ejecución: " << elapsedTime.count() << " nanosegundos" << endl;
}

// Comparación en tiempo de compilación con templates
constexpr bool compareStringsCompileTime(const char* str1, const char* str2) {
    return (*str1 == '\0' && *str2 == '\0') ? true : (*str1 == *str2 && compareStringsCompileTime(str1 + 1, str2 + 1));
}

int main() {
    // Medir tiempo de ejecución
    measureRuntime();
    
    // Evaluación en tiempo de compilación
    constexpr bool compileTimeResult = compareStringsCompileTime("Este es un texto de prueba con más de 64 caracteres para comparar.", "Este es un texto de prueba con más de 64 caracteres para comparar.");
    cout << "Comparación en tiempo de compilación: " << (compileTimeResult ? "Iguales" : "Diferentes") << endl;
    
    return 0;
}

/*
Conclusión:
- La comparación en tiempo de ejecución toma un cierto tiempo medible, ya que se realiza durante la ejecución del programa.
- La comparación en tiempo de compilación, al estar evaluada en `constexpr`, se resuelve en la etapa de compilación y no contribuye al tiempo de ejecución.
- En general, el uso de `constexpr` permite optimizar y reducir el costo computacional en tiempo de ejecución si los valores son conocidos en tiempo de compilación.
*/
