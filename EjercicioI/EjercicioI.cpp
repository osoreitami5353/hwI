#include <iostream>
#include <vector>

using namespace std;

// Función para generar la matriz
vector<vector<int>> matrixGenerator(int n) { // Devuelve una matriz representada como un vector de vectores de enteros
    vector<vector<int>> matrix(n, vector<int>(n));  // Crear matriz de tamaño n x n
    int value = 1;

    for (int i = 0; i < n; i++) {       // Recorre filas
        for (int j = 0; j < n; j++) {   // Recorre columnas
            matrix[i][j] = value++;     // Asigna el valor y luego lo incrementa
        }
    }
    
    return matrix;
}

// Función para imprimir la matriz
void printMatrix(const vector<vector<int>>& matrix) { // Se usa const para evitar modificaciones en la matriz dentro de la función, se usa & para evitar copias innecesarias de la matriz
    for (const auto& row : matrix) { // Recorre fila por fila tomando los vector<int>
        for (int value : row) {      // Recorre los elementos de cada fila
            cout << value << " ";    // Imprime cada número seguido de un espacio
        }
        cout << endl;   // Al terminar una fila, salta a la siguiente línea
    }
}

// Función para imprimir la matriz en orden inverso con un solo ciclo
void printInverseMatrix(const vector<vector<int>>& matrix) {
    int n = matrix.size();      // Obtener el n
    
    int totalElements = n * n;  // Número total de elementos en la matriz

    for (int k = totalElements - 1; k >= 0; k--) {
        int i = k / n;  // Calcula la fila
        int j = k % n;  // Calcula la columna

        cout << "M[" << i << "][" << j << "]=" << matrix[i][j] << endl;
    }
}

int main() {
    int n;
    cout << "Ingrese el valor de n: ";
    cin >> n;

    if (n > 1) {
        vector<vector<int>> matrix = matrixGenerator(n);

        cout << "Matriz normal:" << endl;
        printMatrix(matrix);

        cout << "\nMatriz en orden inverso:" << endl;
        printInverseMatrix(matrix);
    } else {
        cout << "El valor de n debe ser mayor a 1." << endl;
    }

    return 0;
}

