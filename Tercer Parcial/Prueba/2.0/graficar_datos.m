% Script de MATLAB para graficar los datos
% Ejecutar este script en MATLAB

try
    % Cargar los datos
    datos = load('datos_matlab.dat');
    n = datos(:,1);
    e_log_n = datos(:,2);
    n_values = datos(:,3);

    % Crear figura con dos subgráficas
    h = figure('Position', [100, 100, 1200, 500]);

    % Gráfica normal
    subplot(1,2,1);
    plot(n, e_log_n, 'bo-', 'LineWidth', 2);
    hold on;
    plot(n, n_values, 'r--', 'LineWidth', 2);
    xlabel('n');
    ylabel('Valor');
    title('Comparación de e·log(n) vs n');
    lh1 = legend('e·log(n)', 'n', 'Location', 'northwest');
    grid on;

    % Marcar el punto n = e donde las funciones se intersecan
    e_value = exp(1);
    line([e_value e_value], get(gca,'YLim'), 'Color', 'g', 'LineStyle', '--');
    text(e_value+0.1, min(get(gca,'YLim'))*2, ['n = e ≈ ' num2str(e_value, '%.4f')], 'Color', 'g');

    % Gráfica semilogarítmica
    subplot(1,2,2);
    semilogy(n, e_log_n, 'bo-', 'LineWidth', 2);
    hold on;
    semilogy(n, n_values, 'r--', 'LineWidth', 2);
    xlabel('n');
    ylabel('Valor (escala logarítmica)');
    title('Comparación en escala logarítmica');
    lh2 = legend('e·log(n)', 'n', 'Location', 'northwest');
    grid on;

    % Ajustar diseño
    drawnow;
    pause(0.5);

    % Guardar la figura como imagen de manera segura
    print(h, 'grafica_matlab.png', '-dpng');

    % Mostrar mensaje
    disp('Gráfica generada y guardada como grafica_matlab.png');

catch e
    disp(['Error: ' e.message]);
    disp('Verifique que el archivo datos_matlab.dat existe y tiene el formato correcto');
end
