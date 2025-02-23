% Leer el archivo de resultados
data = readtable('resultados.txt');

% Extraer nombres y tiempos
nombres = data{:,1};  % Algoritmos
tiempos = data{:,2};  % Tiempos de ejecución

% Crear la gráfica de barras
figure;
bar(tiempos);
set(gca, 'XTickLabel', nombres, 'XTick', 1:length(nombres));
xlabel('Algoritmo');
ylabel('Tiempo (microsegundos)');
title('Comparación de Tiempos de Ejecución');
grid on;

% Guardar la gráfica
saveas(gcf, 'grafica_tiempos.png');
disp('Gráfica generada y guardada como grafica_tiempos.png');


% Leer los datos desde el archivo CSV
data = readtable('resultados.csv');

% Extraer las columnas de algoritmo, tamaño y tiempo
algoritmos = data.Algoritmo;
tamanos = data.Tama_o;
tiempos = data.Tiempo_microsegundos_;

% Crear una nueva figura
figure;

% Graficar los tiempos de ejecución de Bubble Sort
hold on;
bubble_sort_times = tiempos(strcmp(algoritmos, 'Bubble Sort'));
bubble_sort_sizes = tamanos(strcmp(algoritmos, 'Bubble Sort'));
plot(bubble_sort_sizes, bubble_sort_times, 'ro-', 'DisplayName', 'Bubble Sort (Experimental)');

% Graficar los tiempos de ejecución de Quick Sort
quick_sort_times = tiempos(strcmp(algoritmos, 'Quick Sort'));
quick_sort_sizes = tamanos(strcmp(algoritmos, 'Quick Sort'));
plot(quick_sort_sizes, quick_sort_times, 'bo-', 'DisplayName', 'Quick Sort (Experimental)');

% Graficar la complejidad teórica O(n^2) para Bubble Sort
n_squared = bubble_sort_sizes.^2 / 1000;  % Ajuste para la escala
plot(bubble_sort_sizes, n_squared, 'r--', 'DisplayName', 'O(n^2) Teórico');

% Graficar la complejidad teórica O(n log n) para Quick Sort
n_log_n = quick_sort_sizes .* log2(quick_sort_sizes) / 10;  % Ajuste para la escala
plot(quick_sort_sizes, n_log_n, 'b--', 'DisplayName', 'O(n log n) Teórico');

% Añadir título y etiquetas a la gráfica
title('Comparación de Complejidades (Big O)');
xlabel('Tamaño del arreglo (n)');
ylabel('Tiempo de ejecución (microsegundos)');
legend;
grid on;

% Finalizar la gráfica
hold off;