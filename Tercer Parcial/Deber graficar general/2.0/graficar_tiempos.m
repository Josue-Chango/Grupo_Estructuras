% Leer el archivo de resultados con nombres de columna originales
data = readtable('resultados.csv', 'VariableNamingRule', 'preserve');

% Mostrar nombres de columnas para verificar estructura
disp('Columnas detectadas en el CSV:');
disp(data.Properties.VariableNames);

% Verificar si las columnas existen
if any(strcmp(data.Properties.VariableNames, 'Estructura/Tarea'))
    algoritmo_col = 'Estructura/Tarea';
else
    error('No se encontró la columna "Estructura/Tarea". Verifique el CSV.');
end

if any(strcmp(data.Properties.VariableNames, 'Tamaño'))
    tamano_col = 'Tamaño';
else
    error('No se encontró la columna "Tamaño". Verifique el CSV.');
end

if any(strcmp(data.Properties.VariableNames, 'Tiempo (microsegundos)'))
    tiempo_col = 'Tiempo (microsegundos)';
else
    error('No se encontró la columna "Tiempo (microsegundos)". Verifique el CSV.');
end

% Extraer datos del CSV
algoritmos = data.(algoritmo_col);
tamanos = data.(tamano_col);
tiempos = data.(tiempo_col);

% Extraer los valores únicos de tamaños
tamanos_unicos = unique(tamanos);

% ------------------ GRAFICAR COMPLEJIDAD EXPERIMENTAL ------------------
figure;
hold on;

% Graficar los tiempos de ejecución de Bubble Sort
bubble_sort_times = tiempos(strcmp(algoritmos, 'Bubble Sort'));
bubble_sort_sizes = tamanos(strcmp(algoritmos, 'Bubble Sort'));
plot(bubble_sort_sizes, bubble_sort_times, 'ro-', 'LineWidth', 2, 'DisplayName', 'Bubble Sort (Experimental)');

% Graficar los tiempos de ejecución de Quick Sort
quick_sort_times = tiempos(strcmp(algoritmos, 'Quick Sort'));
quick_sort_sizes = tamanos(strcmp(algoritmos, 'Quick Sort'));
plot(quick_sort_sizes, quick_sort_times, 'bo-', 'LineWidth', 2, 'DisplayName', 'Quick Sort (Experimental)');

% ------------------ GRAFICAR FUNCIONES TEÓRICAS DE COMPLEJIDAD ------------------

% Función teórica O(n²) para Bubble Sort (escalada para comparación)
n_squared = tamanos_unicos.^2 / max(tamanos_unicos.^2) * max(bubble_sort_times);
plot(tamanos_unicos, n_squared, 'r--', 'LineWidth', 2, 'DisplayName', 'O(n^2) Teórico');

% Función teórica O(n log n) para Quick Sort (escalada para comparación)
n_log_n = tamanos_unicos .* log2(tamanos_unicos);
n_log_n = n_log_n / max(n_log_n) * max(quick_sort_times); % Normalización
plot(tamanos_unicos, n_log_n, 'b--', 'LineWidth', 2, 'DisplayName', 'O(n log n) Teórico');

% ------------------ CONFIGURAR GRÁFICO ------------------
title('Comparación de Complejidades (Big O)');
xlabel('Tamaño del arreglo (n)');
ylabel('Tiempo de ejecución (microsegundos)');
legend('Location', 'northwest');
grid on;
hold off;

% Guardar la gráfica
saveas(gcf, 'grafica_complejidad.png');
disp('Gráfica de complejidad guardada como grafica_complejidad.png');
