% Leer el archivo de configuración
fileID = fopen('config.txt', 'r');
if fileID == -1
    error('No se pudo abrir config.txt');
end

% Leer los valores desde el archivo
params = fscanf(fileID, '%f %f %f');
fclose(fileID);

% Extraer valores
n_inicio = params(1);
n_fin = params(2);
incremento = params(3);

% Verificar que los valores sean correctos
if n_inicio <= 0 || n_fin <= n_inicio || incremento <= 0
    error('Valores inválidos en config.txt. Asegúrate de que n_inicio > 0, n_fin > n_inicio y incremento > 0.');
end

% Generar valores de n según las condiciones especificadas
n_values = n_inicio:incremento:n_fin;

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

% Graficar la función n^e en azul
plot(n_values, f_n_e, 'b-', 'LineWidth', 2, 'DisplayName', 'n^e');

% Graficar la función e^n en rojo
plot(n_values, f_e_n, 'r-', 'LineWidth', 2, 'DisplayName', 'e^n');

% Dibujar líneas de referencia en n = e
e_value = exp(1);
plot([e_value e_value], [0 max(f_e_n)], 'k--', 'LineWidth', 1, 'DisplayName', 'n = e');
plot([0 max(n_values)], [f_e_n(find(n_values >= e_value, 1)) f_e_n(find(n_values >= e_value, 1))], 'k--', 'LineWidth', 1);

% Etiquetas de referencia
text(e_value + 0.2, -1, 'e', 'FontSize', 12, 'Color', 'k');
text(n_values(end)/2, max(f_n_e)/2, 'n^e', 'FontSize', 12, 'Color', 'b', 'FontAngle', 'italic', 'FontWeight', 'bold');
text(n_values(end)/2, max(f_e_n)/2, 'e^n', 'FontSize', 12, 'Color', 'r', 'FontAngle', 'italic', 'FontWeight', 'bold');

% Configuración de la gráfica
xlabel('n');
ylabel('Valor de la función');
title(sprintf('Gráfica para n desde %.2f hasta %.2f con incremento %.2f', n_inicio, n_fin, incremento));
legend('Location', 'northwest');
grid on;

% Ajustar los límites del eje
axis([n_inicio n_fin 0 max(f_e_n)]);

hold off;

% Guardar la gráfica
saveas(gcf, 'grafica_condiciones.png');

disp('Gráfica generada y guardada como grafica_condiciones.png');
