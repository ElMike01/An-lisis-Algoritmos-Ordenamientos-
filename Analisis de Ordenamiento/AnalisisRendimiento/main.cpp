#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

// Constantes globales
constexpr int NUM_PRUEBAS = 1000; // Número de pruebas por tamaño de arreglo
constexpr int MIN_TAMANO = 10;     // Tamaño mínimo de arreglo
constexpr int MAX_TAMANO = 1000;   // Tamaño máximo de arreglo
constexpr int INCREMENTO = 10;      // Incremento entre tamaños

// Función que implementa el algoritmo de ordenamiento por inserción
void ordenamientoPorInsercion(int arr[], const int n) {
    for (int i = 1; i < n; i++) {
        const int clave = arr[i];
        int j = i - 1;

        // Mover los elementos de arr[0..i-1], que son mayores que clave,
        // a una posición adelante de su posición actual
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

int main() {
    // Inicializar el generador de números aleatorios
    random_device rd; // Semilla aleatoria
    mt19937 gen(rd()); // Generador Mersenne Twister
    uniform_int_distribution<> distrib(1, 1000); // Distribución uniforme entre 1 y 1000

    // Crear archivo CSV para almacenar los tiempos de ejecución
    ofstream archivo("1_Ordenamiento_Insercion_tiempos.csv");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo CSV." << endl;
        return 1;
    }

    // Escribir encabezados en el archivo CSV
    for (int tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO) {
        archivo << "Tamano " << tam;
        if (tam < MAX_TAMANO) {
            archivo << ",";
        }
    }
    archivo << endl; // Nueva línea después de los encabezados

    // Bucle para diferentes tamaños de arreglo
    for (int tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO) {
        double sumaTiempos = 0;

        // Realizar las pruebas para el tamaño actual
        for (int i = 0; i < NUM_PRUEBAS; i++) {
            // Declarar un arreglo con el tamaño correspondiente
            const auto arr = new int[tam];

            // Generar un arreglo de números aleatorios
            for (int j = 0; j < tam; j++) {
                arr[j] = distrib(gen);
            }

            // Registrar el tiempo antes de iniciar el ordenamiento
            auto inicio = chrono::high_resolution_clock::now();

            // Ejecutar el algoritmo de ordenamiento por inserción
            ordenamientoPorInsercion(arr, tam);

            // Registrar el tiempo después de completar el ordenamiento
            auto fin = chrono::high_resolution_clock::now();

            // Calcular el tiempo de ejecución
            const double tiempoEjecucion = chrono::duration<double>(fin - inicio).count();
            sumaTiempos += tiempoEjecucion;

            // Liberar la memoria del arreglo
            delete[] arr;
        }

        // Calcular el tiempo promedio de ejecución
        const double tiempoPromedio = sumaTiempos / NUM_PRUEBAS;

        // Mostrar el tiempo promedio de ejecución en pantalla
        cout << "Tiempo promedio de ejecucion para tamano " << tam << ": "
             << fixed << setprecision(6) << tiempoPromedio << " segundos" << endl;

        // Escribir el tiempo promedio en el archivo CSV
        archivo << tiempoPromedio;
        if (tam < MAX_TAMANO) {
            archivo << ",";
        }
    }

    archivo << endl; // Nueva línea después de los tiempos
    archivo.close(); // Cerrar el archivo CSV
    cout << "Resultados exportados a '1_Ordenamiento_Insercion_tiempos.csv'" << endl;

    return 0; // Indicar una ejecución exitosa
}