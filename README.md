Analisis-algoritmos-Ordenamientos
El objetivo de esta actividad es ampliar un experimento previo para analizar y comparar el rendimiento de siete algoritmos de ordenamiento.

Análisis de Algoritmos de Ordenamiento
Descripción General
Este proyecto tiene como objetivo analizar y comparar el rendimiento de siete algoritmos de ordenamiento mediante la implementación y evaluación de su tiempo de ejecución en diferentes tamaños de arreglos. Para ello, se han implementado los algoritmos de ordenamiento más comunes: Ordenamiento por Inserción, Ordenamiento Burbuja, Ordenamiento por Selección, Ordenamiento Shell, Ordenamiento por Mezcla (Merge Sort), Ordenamiento Rápido (Quick Sort), y Ordenamiento por Montículos (Heap Sort).

El rendimiento de cada uno de estos algoritmos se ha medido en función de diferentes tamaños de arreglos y se ha guardado en archivos CSV, los cuales pueden ser utilizados para realizar una comparación más detallada.

Requisitos del Sistema
Para ejecutar este código, necesitas cumplir con los siguientes requisitos:

Sistema operativo: Linux, macOS o Windows.
Compilador: Un compilador de C++ moderno que soporte el estándar C++11 o superior (por ejemplo, GCC o Clang).
Librerías: El código no requiere librerías externas, solo las estándar de C++.
Instrucciones de Compilación y Ejecución
Compilación
Descarga o clona este repositorio en tu máquina.

Abre una terminal y navega hasta la carpeta del proyecto.

Para compilar el código, utiliza el siguiente comando (asegúrate de tener un compilador C++):

g++ -o analisis_ordenamientos main.cpp
Este comando generará un archivo ejecutable llamado analisis_ordenamientos (en Linux/macOS) o analisis_ordenamientos.exe (en Windows) Ejecución

Para ejecutar el programa, simplemente usa el siguiente comando: ./analisis_ordenamientos

El programa generará siete archivos CSV con los resultados de cada algoritmo de ordenamiento y los tiempos de ejecución para los diferentes tamaños de arreglo. Los archivos serán nombrados según el siguiente formato:

1_Insercion_Ordenamiento.csv

2_Burbuja_Ordenamiento.csv

3_Seleccion_Ordenamiento.csv

4_Shell_Ordenamiento.csv

5_Mezcla_Ordenamiento.csv

6_Rapido_Ordenamiento.csv

7_Monticulos_Ordenamiento.csv
Descripción de los Algoritmos de Ordenamiento Implementados

Ordenamiento por Inserción
El algoritmo de ordenamiento por inserción es un algoritmo simple que construye la lista ordenada de uno en uno. Compara el elemento a ordenar con los elementos previamente ordenados e inserta el nuevo elemento en su posición correcta.

Complejidad temporal:

Mejor caso: O(n)

Promedio y peor caso: O(n²)
Ordenamiento Burbuja
El ordenamiento burbuja compara cada par de elementos adyacentes y los intercambia si están en el orden incorrecto. Este proceso se repite hasta que el arreglo está completamente ordenado.

Complejidad temporal:

Mejor caso: O(n)

Promedio y peor caso: O(n²)
Ordenamiento por Selección
El algoritmo de ordenamiento por selección divide el arreglo en dos subarreglos: uno ordenado y uno no ordenado. En cada iteración, selecciona el menor (o mayor) elemento del subarreglo no ordenado y lo coloca en la posición correcta.

Complejidad temporal:

Mejor, promedio y peor caso: O(n²)
Ordenamiento Shell
El algoritmo de ordenamiento Shell es una mejora del ordenamiento por inserción. Realiza comparaciones e intercambios en elementos distantes entre sí. El algoritmo mejora su rendimiento a medida que los elementos se acercan entre sí durante el proceso.

Complejidad temporal:

Depende de la secuencia de incremento utilizada, pero puede ser O(n³/2) en el caso más general.
Ordenamiento por Mezcla (Merge Sort)
El algoritmo de ordenamiento por mezcla es un algoritmo de divide y vencerás. Divide el arreglo en dos mitades, las ordena recursivamente y luego fusiona las dos mitades ordenadas.

Complejidad temporal:

Mejor, promedio y peor caso: O(n log n)
Ordenamiento Rápido (Quick Sort)
El algoritmo de ordenamiento rápido también es un algoritmo de divide y vencerás. Elige un pivote, particiona el arreglo en dos subarreglos de tal manera que todos los elementos menores al pivote estén a su izquierda, y todos los mayores a su derecha, y luego aplica recursión.

Complejidad temporal:

Mejor y promedio caso: O(n log n)

Peor caso: O(n²) (aunque esto es raro si se elige bien el pivote)
Ordenamiento por Montículos (Heap Sort)
El ordenamiento por montículos utiliza una estructura de datos llamada "montículo binario". Construye un montículo a partir del arreglo y luego extrae repetidamente el máximo (o mínimo) elemento del montículo, reordenando el árbol en cada paso.

Complejidad temporal:

Mejor, promedio y peor caso: O(n log n)
Gráfica Comparativa de los Tiempos de Ejecución

A continuación, se presenta una gráfica que compara los tiempos de ejecución de cada uno de los algoritmos en función del tamaño de los arreglos. Los tiempos fueron obtenidos experimentalmente con los resultados generados en los archivos CSV:

Análisis de Resultados

Los resultados experimentales obtenidos muestran que los algoritmos como Merge Sort y Quick Sort son significativamente más rápidos que los algoritmos como Burbuja, Inserción y Selección, especialmente cuando los tamaños de los arreglos aumentan. Como era de esperar, los algoritmos de tipo "divide y vencerás" como Merge Sort y Quick Sort escalan mucho mejor que los algoritmos de intercambio o selección.

El ordenamiento por Shell también mostró un rendimiento competitivo, aunque no al nivel de Merge Sort o Quick Sort. Burbuja y Selección demostraron ser ineficientes incluso con tamaños de arreglo pequeños, lo que refuerza la idea de que estos algoritmos no son adecuados para conjuntos de datos grandes. Conclusiones

Este análisis demuestra la importancia de elegir el algoritmo de ordenamiento adecuado dependiendo del tamaño del conjunto de datos. Para arreglos grandes, los algoritmos Merge Sort y Quick Sort son las mejores opciones debido a su eficiencia. Los algoritmos Burbuja, Inserción y Selección tienen un rendimiento deficiente y deberían evitarse cuando el tamaño del conjunto de datos es considerable.

Se recomienda seguir investigando optimizaciones y variaciones de algoritmos como Quick Sort y Merge Sort, ya que en muchos casos estos algoritmos pueden ser mejorados con técnicas como la selección de pivotes inteligentes o el uso de hilos de ejecución para procesar en paralelo.
