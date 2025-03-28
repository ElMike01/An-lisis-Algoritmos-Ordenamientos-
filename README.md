# Análisis de Algoritmos de Ordenamiento

## Descripción General

Este proyecto tiene como objetivo analizar y comparar el rendimiento de siete algoritmos de ordenamiento mediante su implementación y evaluación en diferentes tamaños de arreglos. Los algoritmos estudiados son:

- **Ordenamiento por Inserción**
- **Ordenamiento Burbuja**
- **Ordenamiento por Selección**
- **Ordenamiento Shell**
- **Ordenamiento por Mezcla (Merge Sort)**
- **Ordenamiento Rápido (Quick Sort)**
- **Ordenamiento por Montículos (Heap Sort)**

El rendimiento de cada algoritmo se mide con diferentes tamaños de arreglos y los resultados se guardan en archivos CSV para su posterior análisis.

## Estructura del Repositorio

El repositorio está organizado en tres programas principales, cada uno con su respectivo archivo **.cpp** y ejecutable **.exe**:

- **OrdenamientoPorInsercion** (primer programa): Implementa el ordenamiento por inserción.
- **AnalisisAlgoritmos**: Implementa y compara los siete algoritmos de ordenamiento.
- **AnalisisRendimiento**: Analiza el rendimiento de los algoritmos y genera los archivos CSV con los tiempos de ejecución.

Cada programa tiene su propio directorio:

```
Analisis-Algoritmos-Ordenamiento/
│── OrdenamientoPorInsercion/
│   ├── main.cpp
│   ├── OrdenamientoPorInsercion.exe
│
│── AnalisisAlgoritmos/
│   ├── main.cpp
│   ├── AnalisisAlgoritmos.exe
│
│── AnalisisRendimiento/
│   ├── main.cpp
│   ├── AnalisisRendimiento.exe
│
│── datos/
│   ├── tiempos_ordenamientos.csv
│   ├── grafica.png
│
│── README.md
│── LICENCE.md
```

## Requisitos del Sistema

- **Sistema operativo**: Windows, Linux o macOS
- **Compilador**: Compatible con C++11 o superior (GCC, Clang o MSVC)
- **Librerías**: Solo usa las estándar de C++, no requiere dependencias externas.

## Instrucciones de Compilación y Ejecución

Para compilar y ejecutar cada programa, sigue los siguientes pasos:

### 1️⃣ Compilar los programas

Desde la terminal, navega al directorio de cada programa y ejecuta:

#### **OrdenamientoPorInsercion**
```bash
cd OrdenamientoPorInsercion
 g++ -o OrdenamientoPorInsercion main.cpp
```

#### **AnalisisAlgoritmos**
```bash
cd AnalisisAlgoritmos
 g++ -o AnalisisAlgoritmos main.cpp
```

#### **AnalisisRendimiento**
```bash
cd AnalisisRendimiento
 g++ -o AnalisisRendimiento main.cpp
```

### 2️⃣ Ejecutar los programas

#### **Ejecutar OrdenamientoPorInsercion**
```bash
./OrdenamientoPorInsercion
```

#### **Ejecutar AnalisisAlgoritmos**
```bash
./AnalisisAlgoritmos
```

#### **Ejecutar AnalisisRendimiento**
```bash
./AnalisisRendimiento
```

Este último generará archivos CSV con los tiempos de ejecución para cada algoritmo.

## Resultados y Análisis

Los archivos CSV generados tienen los tiempos promedio de ejecución de los algoritmos para distintos tamaños de arreglos. A partir de estos datos, se ha generado una gráfica comparativa:

![Gráfica de comparación](datos/grafica.png)

### Observaciones
- **Quick Sort y Merge Sort** son los algoritmos más eficientes en la mayoría de los casos.
- **Burbuja, Selección e Inserción** tienen un rendimiento ineficiente para grandes volúmenes de datos.
- **Heap Sort y Shell Sort** ofrecen desempeños intermedios.

## Conclusión

Este análisis muestra que la elección del algoritmo de ordenamiento adecuado depende del tamaño del conjunto de datos. Algoritmos como **Merge Sort** y **Quick Sort** son ideales para grandes volúmenes de datos, mientras que algoritmos como **Burbuja, Inserción y Selección** deben evitarse para datos extensos.

Se recomienda seguir investigando optimizaciones en la selección de pivotes y el uso de procesamiento paralelo para mejorar el rendimiento en aplicaciones reales.
