import pandas as pd
import matplotlib.pyplot as plt

# Cargar los datos experimentales
datos = pd.read_csv("Datos/tiempos.csv")

# Graficar
plt.figure(figsize=(10, 5))
for algoritmo in datos.columns[1:]:  # Ignorar la primera columna (tamaño del array)
    plt.plot(datos["Tamaño"], datos[algoritmo], marker='o', label=algoritmo)

# Configuración de la gráfica
plt.xlabel("Tamaño del Arreglo")
plt.ylabel("Tiempo de Ejecución (ms)")
plt.title("Comparación de Algoritmos de Ordenamiento")
plt.legend()
plt.grid()
plt.savefig("grafica.png")  # Guardar la imagen
plt.show()