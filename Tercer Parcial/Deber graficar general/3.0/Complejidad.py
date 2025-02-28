import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

# Funciones de complejidad teórica
def O_n(x, a):
    return a * x

def O_n2(x, a):
    return a * x**2

def O_nlogn(x, a):
    return a * x * np.log2(x)

def O_logn(x, a):
    return a * np.log2(x)

# Leer datos desde el CSV
data = pd.read_csv("resultados.csv")

# Obtener algoritmos únicos
algoritmos = data["Estructura/Tarea"].unique()

# Iterar sobre cada algoritmo y analizar su complejidad
for algoritmo in algoritmos:
    datos = data[data["Estructura/Tarea"] == algoritmo]

    # Extraer valores
    tamanos = datos["Tamaño"].values
    tiempos = datos["Tiempo (microsegundos)"].values

    # Ajustar cada modelo
    popt_n, _ = curve_fit(O_n, tamanos, tiempos)
    popt_n2, _ = curve_fit(O_n2, tamanos, tiempos)
    popt_nlogn, _ = curve_fit(O_nlogn, tamanos, tiempos)
    popt_logn, _ = curve_fit(O_logn, tamanos, tiempos)

    # Calcular errores de ajuste
    error_n = np.sum((tiempos - O_n(tamanos, *popt_n))**2)
    error_n2 = np.sum((tiempos - O_n2(tamanos, *popt_n2))**2)
    error_nlogn = np.sum((tiempos - O_nlogn(tamanos, *popt_nlogn))**2)
    error_logn = np.sum((tiempos - O_logn(tamanos, *popt_logn))**2)

    # Determinar el mejor ajuste
    errores = {"O(n)": error_n, "O(n^2)": error_n2, "O(n log n)": error_nlogn, "O(log n)": error_logn}
    mejor_ajuste = min(errores, key=errores.get)

    # Imprimir el resultado
    print(f"{algoritmo} se ajusta mejor a {mejor_ajuste}")

    # Graficar los datos y la mejor curva ajustada
    plt.figure()
    plt.scatter(tamanos, tiempos, label="Datos experimentales", color="black")
    x_range = np.linspace(min(tamanos), max(tamanos), 100)

    if mejor_ajuste == "O(n)":
        plt.plot(x_range, O_n(x_range, *popt_n), 'r--', label="O(n)")
    elif mejor_ajuste == "O(n^2)":
        plt.plot(x_range, O_n2(x_range, *popt_n2), 'b--', label="O(n^2)")
    elif mejor_ajuste == "O(n log n)":
        plt.plot(x_range, O_nlogn(x_range, *popt_nlogn), 'g--', label="O(n log n)")
    else:
        plt.plot(x_range, O_logn(x_range, *popt_logn), 'm--', label="O(log n)")

    plt.title(f"Análisis de Complejidad para {algoritmo}")
    plt.xlabel("Tamaño de entrada (n)")
    plt.ylabel("Tiempo de ejecución (microsegundos)")
    plt.legend()
    plt.grid()
    plt.savefig(f"{algoritmo.replace(' ', '_')}_complejidad.png")
    plt.show()
