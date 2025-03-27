#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <fstream>

using namespace std;

// Constantes globales
constexpr int NUM_PRUEBAS = 1000; // Número de pruebas
constexpr int TAM_ARREGLO = 10;    // Tamaño del arreglo

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

    // Arreglo para almacenar los tiempos de ejecución
    double tiempos[NUM_PRUEBAS];

    for (int i = 0; i < NUM_PRUEBAS; i++) {
        // Generar un arreglo de 10 números aleatorios entre 1 y 1000
        int arr[TAM_ARREGLO];
        for (int & j : arr) {
            j = distrib(gen); // Generar número aleatorio
        }

        // Registrar el tiempo antes de iniciar el ordenamiento
        auto inicio = chrono::high_resolution_clock::now();

        // Ejecutar el algoritmo de ordenamiento por inserción
        ordenamientoPorInsercion(arr, TAM_ARREGLO);

        // Registrar el tiempo después de completar el ordenamiento
        auto fin = chrono::high_resolution_clock::now();

        // Calcular el tiempo de ejecución
        tiempos[i] = chrono::duration<double>(fin - inicio).count();

        // Mostrar el arreglo original y el ordenado solo en la primera iteración
        if (i == 0) {
            cout << "Arreglo original: ";
            for (const int j : arr) {
                cout << j << " ";
            }
            cout << endl;

            cout << "Arreglo ordenado: ";
            for (const int j : arr) {
                cout << j << " ";
            }
            cout << endl;

            cout << "Tiempo de ejecuciOn: " << fixed << setprecision(6) << tiempos[i] << " segundos" << endl;
        }
    }

    // Calcular el tiempo promedio de ejecución
    double sumaTiempos = 0;
    for (const double tiempo : tiempos) {
        sumaTiempos += tiempo;
    }
    const double tiempoPromedio = sumaTiempos / NUM_PRUEBAS;

    // Mostrar el tiempo promedio de ejecución
    cout << "Tiempo promedio de ejecuciOn: " << fixed << setprecision(6) << tiempoPromedio << " segundos" << endl;

    // Exportar resultados a un archivo de texto
    if (ofstream archivo("1_Ordenamiento_Insercion_tiempos.txt"); archivo.is_open()) {
        for (const double tiempo : tiempos) {
            archivo << tiempo << endl;
        }
        archivo.close();
        cout << "Resultados exportados a '1_Ordenamiento_Insercion_tiempos.txt'" << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }

    return 0; // Indicar una ejecución exitosa
}