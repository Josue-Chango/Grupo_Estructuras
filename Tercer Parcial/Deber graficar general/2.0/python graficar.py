import pandas as pd
import matplotlib.pyplot as plt

data = pd.read_csv("resultados.csv")
plt.figure()
for alg in data["Algoritmo"].unique():
    subset = data[data["Algoritmo"] == alg]
    plt.plot(subset["Tamaño"], subset["Tiempo (microsegundos)"], '-o', label=alg)

plt.xlabel("Tamaño del array")
plt.ylabel("Tiempo (microsegundos)")
plt.title("Comparación de Algoritmos de Ordenamiento")
plt.legend()
plt.grid(True)
plt.show()
