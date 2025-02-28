% Cargar datos desde el CSV
data = readtable('resultados.csv', 'VariableNamingRule', 'preserve');

% Verificar columnas disponibles
disp('Columnas detectadas en el CSV:');
disp(data.Properties.VariableNames);

% Asegurar que las columnas correctas existen
if ~any(strcmp(data.Properties.VariableNames, 'Estructura/Tarea')) || ...
   ~any(strcmp(data.Properties.VariableNames, 'Tamaño')) || ...
   ~any(strcmp(data.Properties.VariableNames, 'Tiempo (microsegundos)'))
    error('No se encontraron las columnas requeridas en el CSV.');
end

% Extraer los datos
algoritmos = unique(data.("Estructura/Tarea"));
tamanos = data.("Tamaño");
tiempos = data.("Tiempo (microsegundos)");

% Definir funciones de complejidad teórica
O_n = @(x, a) a * x;
O_n2 = @(x, a) a * x.^2;
O_nlogn = @(x, a) a * x .* log2(x);
O_logn = @(x, a) a * log2(x);

% Iterar sobre cada algoritmo
for i = 1:length(algoritmos)
    nombreAlgoritmo = algoritmos{i};
    
    % Filtrar los datos de este algoritmo
    indices = strcmp(data.("Estructura/Tarea"), nombreAlgoritmo);
    tam_actual = tamanos(indices);
    tiempo_actual = tiempos(indices);
    
    % Asegurar que los datos estén ordenados
    [tam_actual, idx] = sort(tam_actual);
    tiempo_actual = tiempo_actual(idx);
    
    % Ajustar modelos de complejidad con regresión
    coef_n = polyfit(tam_actual, tiempo_actual, 1);  % O(n)
    coef_n2 = polyfit(tam_actual.^2, tiempo_actual, 1);  % O(n^2)
    coef_nlogn = polyfit(tam_actual .* log2(tam_actual), tiempo_actual, 1);  % O(n log n)
    coef_logn = polyfit(log2(tam_actual), tiempo_actual, 1);  % O(log n)

    % Calcular errores de ajuste
    error_n = sum((tiempo_actual - polyval(coef_n, tam_actual)).^2);
    error_n2 = sum((tiempo_actual - polyval(coef_n2, tam_actual.^2)).^2);
    error_nlogn = sum((tiempo_actual - polyval(coef_nlogn, tam_actual .* log2(tam_actual))).^2);
    error_logn = sum((tiempo_actual - polyval(coef_logn, log2(tam_actual))).^2);

    % Determinar la mejor complejidad
    errores = [error_n, error_n2, error_nlogn, error_logn];
    etiquetas = ["O(n)", "O(n^2)", "O(n log n)", "O(log n)"];
    [~, mejor_idx] = min(errores);
    mejor_ajuste = etiquetas(mejor_idx);
    
    % Imprimir resultado
    fprintf('%s se ajusta mejor a %s\n', nombreAlgoritmo, mejor_ajuste);

    % Graficar resultados
    figure;
    hold on;
    scatter(tam_actual, tiempo_actual, 'k', 'DisplayName', 'Datos experimentales');
    
    % Graficar la mejor función ajustada
    tam_range = linspace(min(tam_actual), max(tam_actual), 100);
    if mejor_idx == 1
        plot(tam_range, polyval(coef_n, tam_range), 'r--', 'DisplayName', 'O(n)');
    elseif mejor_idx == 2
        plot(tam_range, polyval(coef_n2, tam_range.^2), 'b--', 'DisplayName', 'O(n^2)');
    elseif mejor_idx == 3
        plot(tam_range, polyval(coef_nlogn, tam_range .* log2(tam_range)), 'g--', 'DisplayName', 'O(n log n)');
    else
        plot(tam_range, polyval(coef_logn, log2(tam_range)), 'm--', 'DisplayName', 'O(log n)');
    end
    
    title(sprintf('Análisis de Complejidad para %s', nombreAlgoritmo));
    xlabel('Tamaño de entrada (n)');
    ylabel('Tiempo de ejecución (microsegundos)');
    legend('Location', 'northwest');
    grid on;
    hold off;

    % Guardar la gráfica
    nombre_figura = strrep(nombreAlgoritmo, ' ', '_');
    saveas(gcf, sprintf('%s_complejidad.png', nombre_figura));
end
