% Definir el rango de valores para n sin usar linspace
n_values = 1:0.1:10; % Generar valores desde 1 hasta 10 con incrementos de 0.1

% Inicializar los vectores de funciones
f_n_e = zeros(size(n_values));
f_e_n = zeros(size(n_values));

% Calcular los valores de las funciones para cada n
for i = 1:length(n_values)
    f_n_e(i) = n_values(i)^exp(1); % n^e
    f_e_n(i) = exp(n_values(i)); % e^n
end

% Crear la figura
figure;
hold on;

% Graficar la función n^e (línea azul gruesa)
plot(n_values, f_n_e, 'b-', 'LineWidth', 2, 'DisplayName', 'n^e');

% Graficar la función e^n (curva roja gruesa)
plot(n_values, f_e_n, 'r-', 'LineWidth', 2, 'DisplayName', 'e^n');

% Dibujar líneas de referencia en e
e_value = exp(1); % e ≈ 2.718
plot([e_value e_value], [0 max(f_e_n)], 'k--', 'LineWidth', 1, 'DisplayName', 'Referencia e'); % Línea vertical en n = e
plot([0 max(n_values)], [f_e_n(find(n_values >= e_value, 1)) f_e_n(find(n_values >= e_value, 1))], 'k--', 'LineWidth', 1);

% Etiquetas de e
text(e_value + 0.2, 0, 'e', 'FontSize', 12, 'Color', 'k');
text(0.5, max(f_n_e)/2, 'n^e', 'FontSize', 12, 'Color', 'b', 'FontAngle', 'italic', 'FontWeight', 'bold');
text(0.5, max(f_e_n)/2, 'e^n', 'FontSize', 12, 'Color', 'r', 'FontAngle', 'italic', 'FontWeight', 'bold');

% Configuración de la gráfica
xlabel('n');
ylabel('Valor de la función');
title('Comparación de n^e y e^n');
legend('Location', 'northwest');
grid on;

% Ajustar los límites del eje para mejorar la visualización
axis([1 10 0 max(f_e_n)]);

hold off;

% Guardar la gráfica
saveas(gcf, 'comparacion_n_e_exponential.png');

disp('Gráfica generada y guardada como comparacion_n_e_exponential.png');
