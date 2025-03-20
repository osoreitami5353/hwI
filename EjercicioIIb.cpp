#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Enumeración para representar los diferentes niveles de severidad de los mensajes de log
enum SeverityLevel {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    CRITICAL,
    SECURITY // Nueva categoría para mensajes de acceso
};

// Función sobrecargada para registrar mensajes generales con nivel de severidad
void logMessage(const string& message, SeverityLevel level) {
    ofstream logFile("log.txt", ios::app);
    
    if (!logFile) {
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }

    // Determina la etiqueta correspondiente al nivel de severidad
    string tag;
    switch (level) {
        case DEBUG: tag = "DEBUG"; break;
        case INFO: tag = "INFO"; break;
        case WARNING: tag = "WARNING"; break;
        case ERROR: tag = "ERROR"; break;
        case CRITICAL: tag = "CRITICAL"; break;
        case SECURITY: tag = "SECURITY"; break;
    }

    // Escribe el mensaje en el archivo de log
    logFile << "[" << tag << "] " << message << endl;
    logFile.close();
}

// Función sobrecargada para registrar errores con información adicional
void logMessage(const string& message, const string& file, int line) {
    ofstream logFile("log.txt", ios::app);
    
    if (!logFile) {
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }
    
    // Escribe el mensaje de error junto con el archivo y la línea en el archivo de log
    logFile << "[ERROR] " << message << " | Archivo: " << file << " | Línea: " << line << endl;
    logFile.close();
}

// Función sobrecargada para registrar accesos de usuario
void logMessage(const string& message, const string& user, SeverityLevel level = SECURITY) {
    ofstream logFile("log.txt", ios::app);
    
    if (!logFile) {
        cerr << "No se pudo abrir el archivo de log." << endl;
        return;
    }
    
    // Escribe el mensaje de acceso de usuario en el archivo de log
    logFile << "[SECURITY] " << message << " | Usuario: " << user << endl;
    logFile.close();
}

int main() {
    // Pruebas de los diferentes tipos de logging
    logMessage("Este es un mensaje de depuración.", DEBUG);
    logMessage("El sistema ha iniciado correctamente.", INFO);
    logMessage("Se ha detectado un posible problema.", WARNING);
    logMessage("Ha ocurrido un error en la aplicación.", ERROR);
    logMessage("Fallo crítico: el sistema se detendrá.", CRITICAL);
    
    // Registro de accesos de usuario con diferentes resultados
    logMessage("Acceso concedido", "user123");
    logMessage("Acceso denegado", "notuser456");
    
    // Captura de error en tiempo de ejecución
    try {
        int x = 0;
        if (x == 0) {
            throw runtime_error("División por cero detectada");
        }
        int resultado = 10 / x; // Esto nunca se ejecutará por la excepción
    } catch (const exception& e) {
        logMessage(e.what(), __FILE__, __LINE__); // Registra el error con detalles
        /*
          "__FILE__" es una macro que se expande al nombre del archivo fuente actual como una cadena de texto (string).
          __LINE__" es otra macro que se expande al número de línea en la que aparece en el código fuente.
        */
        cerr << "Error crítico: " << e.what() << endl;
        return 1; // Salir con código de error
    }

    cout << "Mensajes de log escritos en log.txt" << endl;
    return 0;
}