#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Enumeración para representar los diferentes niveles de severidad de los mensajes de log
enum SeverityLevel {
    DEBUG,    // Mensajes de depuración
    INFO,     // Mensajes informativos
    WARNING,  // Advertencias sobre posibles problemas
    ERROR,    // Errores en la aplicación
    CRITICAL  // Errores críticos que pueden detener el sistema
};

// Función para registrar mensajes en un archivo de log
void logMessage(const string& mensaje, SeverityLevel nivel) {
    // Abre el archivo "log.txt" en modo de añadir (ios::app) para no sobrescribir contenido previo
    ofstream logFile("log.txt", ios::app);

    // Verifica si el archivo se abrió correctamente
    if (!logFile) {
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;  // Sale de la función si no se pudo abrir el archivo
    }

    // Convierte el nivel de severidad en una etiqueta de texto
    string etiqueta;
    switch (nivel) {
        case DEBUG: etiqueta = "DEBUG"; break;
        case INFO: etiqueta = "INFO"; break;
        case WARNING: etiqueta = "WARNING"; break;
        case ERROR: etiqueta = "ERROR"; break;
        case CRITICAL: etiqueta = "CRITICAL"; break;
    }

    // Escribe en el archivo el mensaje con su nivel de severidad
    logFile << "[" << etiqueta << "] " << mensaje << endl;

    // Cierra el archivo para guardar los cambios
    logFile.close();
}

// Función principal del programa
int main() {
    // Escribe varios mensajes de prueba en el archivo de log con diferentes niveles de severidad
    logMessage("Este es un mensaje de depuración.", DEBUG);
    logMessage("El sistema ha iniciado correctamente.", INFO);
    logMessage("Se ha detectado un posible problema.", WARNING);
    logMessage("Ha ocurrido un error en la aplicación.", ERROR);
    logMessage("Fallo crítico: el sistema se detendrá.", CRITICAL);

    // Muestra un mensaje en la consola indicando que los mensajes se han guardado en el log
    cout << "Mensajes de log escritos correctamente en el archivo log.txt" << endl;
    
    return 0;  // Retorna 0 indicando que el programa finalizó correctamente
}
