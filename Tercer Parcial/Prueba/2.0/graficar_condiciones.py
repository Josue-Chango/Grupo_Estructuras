import numpy as np
import matplotlib.pyplot as plt

# Leer los parámetros desde config.txt
try:
    with open("config.txt", "r") as file:
        params = list(map(float, file.readline().split()))
except FileNotFoundError:
    print("Error: No se encontró config.txt. Asegúrate de ejecutarlo desde C++ primero.")
    exit(1)

n_inicio, n_fin, incremento = params

# Verificar que los valores sean correctos
if n_inicio <= 0 or n_fin <= n_inicio or incremento <= 0:
    print("Error: Valores inválidos en config.txt. Asegúrate de que n_inicio > 0, n_fin > n_inicio y incremento > 0.")
    exit(1)

# Generar valores de n según las condiciones especificadas
n_values = np.arange(n_inicio, n_fin, incremento)

# Calcular las funciones
f_n = n_values  # La función identidad n
f_e_log_n = np.exp(np.log(n_values))  # La función e^{log_e(n)}

# Crear la figura
plt.figure(figsize=(7, 5))
plt.axhline(0, color="black", linewidth=1)  # Eje X
plt.axvline(0, color="black", linewidth=1)  # Eje Y

# Graficar la función identidad n en azul
plt.plot(n_values, f_n, 'b-', linewidth=2, label=r'$n$')

# Graficar la función e^{log_e(n)} en rojo
plt.plot(n_values, f_e_log_n, 'r-', linewidth=2, label=r'$e^{\log_e(n)}$')

# Dibujar líneas de referencia punteadas en n = e
e_value = np.exp(1)  # e ≈ 2.718
plt.axvline(e_value, color="black", linestyle=":", linewidth=1, label=r'$n = e$')

# Etiquetas de referencia
plt.text(e_value + 0.2, -1, r'$e$', fontsize=12, color='k')
plt.text(0.5, -5, r'$e^{\log_e(n)}$', fontsize=12, color='r', fontstyle='italic', fontweight='bold')
plt.text(4.5, 5, r'$n$', fontsize=12, color='b', fontstyle='italic', fontweight='bold')

# Configuración de la gráfica
plt.xlabel(r'$n$')
plt.ylabel(r'Valor de la función')
plt.title(r'Demostración de O Grande: Comparación de $n$ y $e^{\log_e(n)}$')
plt.legend(loc="upper left")
plt.grid(True)

# Ajustar los límites del eje
plt.xlim([-1, 6])
plt.ylim([-8, 6])

# Guardar la gráfica
plt.savefig("demostracion_O_grande_python.png")
plt.show()

print("Gráfica generada y guardada como demostracion_O_grande_python.png")
