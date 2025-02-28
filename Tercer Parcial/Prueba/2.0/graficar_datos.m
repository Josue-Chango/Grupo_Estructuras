% Script de MATLAB para graficar los datos en una sola ventana
try
    % Cargar los datos
    datos = load('datos_matlab.dat');
    n = datos(:,1);
    e_log_n = datos(:,2);
    n_values = datos(:,3);

    % Crear una única figura
    figure;
    hold on;
    % Graficar e·log(n) en magenta (curva con marcadores circulares)
    plot(n, e_log_n, 'mo-', 'LineWidth', 2, 'MarkerSize', 6, 'DisplayName', 'e·log(n)');
    % Graficar n en verde (línea discontinua)
    plot(n, n_values, 'g--', 'LineWidth', 2, 'DisplayName', 'n');
    % Dibujar línea de referencia en n = e
    e_value = exp(1);
    plot([e_value e_value], get(gca,'YLim'), 'k--', 'LineWidth', 1, 'DisplayName', 'n = e');
    % Etiquetas y títulos
    xlabel('n');
    ylabel('Valor de la función');
    title('Comparación de e·log(n) vs n');
    legend('Location', 'northwest');
    grid on;
    % Guardar la imagen
    saveas(gcf, 'grafica_matlab.png');
    disp('Gráfica generada y guardada como grafica_matlab.png');
catch e
    disp(['Error: ' e.message]);
    disp('Verifique que el archivo datos_matlab.dat existe y tiene el formato correcto');
end
