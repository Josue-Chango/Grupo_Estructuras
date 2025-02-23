import numpy as np
import matplotlib.pyplot as plt

# Datos de tamaños de entrada
sizes = np.array([1000, 2000, 5000, 10000, 20000, 50000])  # Tamaños de los arreglos

# Simulación de tiempos de ejecución en microsegundos (valores aproximados)
bubble_sort_times = np.array([5000, 20000, 120000, 500000, 2000000, 5000000])  # O(n^2)
quick_sort_times = np.array([3000, 8000, 25000, 60000, 150000, 400000])  # O(n log n)

# Funciones teóricas de complejidad
n_squared = sizes**2 / 1000  # Escalado para comparación visual
n_log_n = sizes * np.log2(sizes) / 10  # Escalado para comparación visual

# Graficar los tiempos de ejecución y las funciones teóricas
plt.figure(figsize=(10, 6))
plt.plot(sizes, bubble_sort_times, 'ro-', label="Bubble Sort (Experimental)")
plt.plot(sizes, quick_sort_times, 'bo-', label="Quick Sort (Experimental)")
plt.plot(sizes, n_squared, 'r--', label="O(n^2) Teórico")
plt.plot(sizes, n_log_n, 'b--', label="O(n log n) Teórico")

plt.xlabel("Tamaño del arreglo (n)")
plt.ylabel("Tiempo de ejecución (microsegundos)")
plt.title("Comparación de Complejidades (Big O)")
plt.legend()
plt.grid(True)
plt.show()