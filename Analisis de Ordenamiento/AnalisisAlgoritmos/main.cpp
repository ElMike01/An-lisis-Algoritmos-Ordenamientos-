#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Constantes globales
constexpr int NUM_PRUEBAS = 1000;       // Número de pruebas por tamaño
constexpr int MIN_TAMANO = 10;          // Tamaño mínimo del arreglo
constexpr int MAX_TAMANO = 1000;        // Tamaño máximo del arreglo
constexpr int INCREMENTO = 10;          // Incremento entre tamaños
constexpr int NUM_ALGORITMOS = 7;       // Número de algoritmos a evaluar

// Nombres de los algoritmos
const string NOMBRES_ALGORITMOS[NUM_ALGORITMOS] = {
    "Insercion",
    "Burbuja",
    "Seleccion",
    "Shell",
    "Mezcla",
    "Rapido",
    "Monticulo"
};

// Prototipos de funciones
void ordenarPorInsercion(vector<int>& arr);
void ordenarBurbuja(vector<int>& arr);
void ordenarSeleccion(vector<int>& arr);
void ordenarShell(vector<int>& arr);
void ordenarMezcla(vector<int>& arr, vector<int>& temp, int inicio, int fin);
void ordenarRapido(vector<int>& arr, int inicio, int fin);
void ordenarMonticulo(vector<int>& arr);
void ajustarMonticulo(vector<int>& arr, int n, int i);
int particionar(vector<int>& arr, int inicio, int fin);

// Funciones auxiliares
void ejecutarAlgoritmo(int alg, vector<int>& arr, vector<int>& temp);
void exportarResultados(const vector<vector<vector<double>>>& tiempos);

int main() {
    random_device rd;  // Dispositivo de números aleatorios
    mt19937 generador(rd());  // Generador Mersenne Twister
    uniform_int_distribution<> distribucion(1, 1000);  // Rango 1-1000

    // Matriz 3D: [algoritmo][tamaño][prueba]
    vector<vector<vector<double>>> tiempos(
        NUM_ALGORITMOS,
        vector<vector<double>>((MAX_TAMANO - MIN_TAMANO) / INCREMENTO + 1,
        vector<double>(NUM_PRUEBAS)));

    // Bucle por tamaños
    for (int idxTam = 0, tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO, idxTam++) {
        cout << "Probando tamano: " << tam << endl;

        // Generar arreglo aleatorio
        vector<int> arrOriginal(tam);
        for (int j = 0; j < tam; j++) {
            arrOriginal[j] = distribucion(generador);
        }

        // Arreglo temporal para MergeSort
        vector<int> temp(tam);

        // Bucle por algoritmos
        for (int alg = 0; alg < NUM_ALGORITMOS; alg++) {
            cout << "  Probando algoritmo: " << NOMBRES_ALGORITMOS[alg] << endl;

            // Bucle de pruebas
            for (int prueba = 0; prueba < NUM_PRUEBAS; prueba++) {
                vector<int> arr = arrOriginal;  // Copia

                auto inicio = chrono::high_resolution_clock::now();
                ejecutarAlgoritmo(alg, arr, temp);
                auto fin = chrono::high_resolution_clock::now();

                tiempos[alg][idxTam][prueba] = chrono::duration<double>(fin - inicio).count();
            }
        }
    }

    exportarResultados(tiempos);
    return 0;
}

// Implementación de algoritmos de ordenamiento
void ordenarPorInsercion(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        const int clave = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

void ordenarBurbuja(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void ordenarSeleccion(vector<int>& arr) {
    for (int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void ordenarShell(vector<int>& arr) {
    for (int brecha = arr.size() / 2; brecha > 0; brecha /= 2) {
        for (int i = brecha; i < arr.size(); i++) {
            const int temp = arr[i];
            int j;
            for (j = i; j >= brecha && arr[j - brecha] > temp; j -= brecha) {
                arr[j] = arr[j - brecha];
            }
            arr[j] = temp;
        }
    }
}

void ordenarMezcla(vector<int>& arr, vector<int>& temp, int inicio, int fin) {
    if (inicio >= fin) return;

    const int medio = inicio + (fin - inicio) / 2;
    ordenarMezcla(arr, temp, inicio, medio);
    ordenarMezcla(arr, temp, medio + 1, fin);

    // Mezclar
    int i = inicio, j = medio + 1, k = inicio;
    while (i <= medio && j <= fin) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while (i <= medio) temp[k++] = arr[i++];
    while (j <= fin) temp[k++] = arr[j++];

    for (k = inicio; k <= fin; k++) {
        arr[k] = temp[k];
    }
}

int particionar(vector<int>& arr, int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[fin]);
    return i + 1;
}

void ordenarRapido(vector<int>& arr, int inicio, int fin) {
    if (inicio < fin) {
        const int indicePivote = particionar(arr, inicio, fin);
        ordenarRapido(arr, inicio, indicePivote - 1);
        ordenarRapido(arr, indicePivote + 1, fin);
    }
}

void ajustarMonticulo(vector<int>& arr, int n, int i) {
    int mayor = i;
    const int izquierdo = 2 * i + 1;
    const int derecho = 2 * i + 2;

    if (izquierdo < n && arr[izquierdo] > arr[mayor])
        mayor = izquierdo;

    if (derecho < n && arr[derecho] > arr[mayor])
        mayor = derecho;

    if (mayor != i) {
        swap(arr[i], arr[mayor]);
        ajustarMonticulo(arr, n, mayor);
    }
}

void ordenarMonticulo(vector<int>& arr) {
    // Construir montículo
    for (int i = arr.size() / 2 - 1; i >= 0; i--)
        ajustarMonticulo(arr, arr.size(), i);

    // Extraer elementos
    for (int i = arr.size() - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        ajustarMonticulo(arr, i, 0);
    }
}

// Funciones auxiliares
void ejecutarAlgoritmo(const int alg, vector<int>& arr, vector<int>& temp) {
    switch (alg) {
        case 0: ordenarPorInsercion(arr); break;
        case 1: ordenarBurbuja(arr); break;
        case 2: ordenarSeleccion(arr); break;
        case 3: ordenarShell(arr); break;
        case 4: ordenarMezcla(arr, temp, 0, arr.size() - 1); break;
        case 5: ordenarRapido(arr, 0, arr.size() - 1); break;
        case 6: ordenarMonticulo(arr); break;
        default: ;
    }
}

void exportarResultados(const vector<vector<vector<double>>>& tiempos) {
    for (int alg = 0; alg < NUM_ALGORITMOS; alg++) {
        string nombreArchivo = to_string(alg + 1) + "_" + NOMBRES_ALGORITMOS[alg] + "_Ordenamiento.csv";
        ofstream archivo(nombreArchivo);

        if (!archivo.is_open()) {
            cerr << "Error al abrir archivo: " << nombreArchivo << endl;
            continue;
        }

        // Escribir encabezados
        for (int tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO) {
            archivo << tam;
            if (tam < MAX_TAMANO) archivo << ",";
        }
        archivo << endl;

        // Escribir datos
        for (int prueba = 0; prueba < NUM_PRUEBAS; prueba++) {
            for (int idxTam = 0, tam = MIN_TAMANO; tam <= MAX_TAMANO; tam += INCREMENTO, idxTam++) {
                archivo << tiempos[alg][idxTam][prueba];
                if (tam < MAX_TAMANO) archivo << ",";
            }
            archivo << endl;
        }

        cout << "Exportado: " << nombreArchivo << endl;
    }
}