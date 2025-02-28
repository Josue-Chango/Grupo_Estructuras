/*#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    double inicio, fin, incremento;
    
    // Pedir parámetros al usuario
    cout << "Ingrese el valor inicial de n: ";
    cin >> inicio;
    cout << "Ingrese el valor final de n: ";
    cin >> fin;
    cout << "Ingrese el incremento de n: ";
    cin >> incremento;

    // Guardar los valores en un archivo de configuración
    ofstream configFile("config.txt");
    if (!configFile) {
        cerr << "Error al crear el archivo config.txt" << endl;
        return 1;
    }

    configFile << inicio << " " << fin << " " << incremento << endl;
    configFile.close();
    cout << "Configuración guardada en config.txt" << endl;

    // Ejecutar MATLAB con el script
    int matlabStatus = system("matlab -r \"graficar_condiciones2\"");

    if (matlabStatus != 0) {
        cout << "Error al ejecutar MATLAB." << endl;
    }

    return 0;
}*/


/*#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main() {
    double inicio, fin, incremento;
    
    // Pedir parámetros al usuario
    cout << "Ingrese el valor inicial de n: ";
    cin >> inicio;
    cout << "Ingrese el valor final de n: ";
    cin >> fin;
    cout << "Ingrese el incremento de n: ";
    cin >> incremento;

    // Validar que los valores sean correctos
    if (inicio <= 0 || fin <= inicio || incremento <= 0) {
        cerr << "Error: Valores inválidos. Asegúrate de que n_inicio > 0, n_fin > n_inicio y incremento > 0." << endl;
        return 1;
    }

    // Guardar los valores en un archivo de configuración
    ofstream configFile("config.txt");
    if (!configFile) {
        cerr << "Error al crear el archivo config.txt" << endl;
        return 1;
    }

    configFile << inicio << " " << fin << " " << incremento << endl;
    configFile.close();
    cout << "Configuración guardada en config.txt" << endl;

    // Ejecutar el script de Python para graficar
    int pythonStatus = system("python graficar_condiciones.py");


    if (pythonStatus != 0) {
        cout << "Error al ejecutar el script de Python. Intenta ejecutarlo manualmente." << endl;
    } else {
        cout << "Gráfica generada exitosamente." << endl;
    }
    system("pause");
    return 0;
}*/



#include <iostream>
#include <cmath> // Para exp() y log()
#include <fstream> // Para exportar datos
#include <iomanip> // Para formatear números

using namespace std;

int main() {
    // Variables para los parámetros
    double c;
    float n0, max_n;
    bool cumple = true;
    const double e = exp(1.0); // Constante e = 2.71828...

    // Solicitar datos al usuario
    cout << "Ingrese el valor de la constante c (recomendado c=1): ";
    cin >> c;
    
    cout << "Ingrese el valor inicial n0 (recomendado n0=" << e << "): ";
    cin >> n0;
    
    cout << "Ingrese el valor máximo de n para verificar: ";
    cin >> max_n;

    // Crear archivos para exportar datos
    // 1. CSV estándar (compatible con Python y MATLAB)
    ofstream archivo_csv("datos_notacion.csv");
    archivo_csv << "n,e_log_n,n" << endl; // Cambiado para las funciones correctas
    
    // 2. Archivo de datos para MATLAB (.dat)
    ofstream archivo_matlab("datos_matlab.dat");
    archivo_matlab << "% Datos para graficar en MATLAB" << endl;
    archivo_matlab << "% Columna 1: valores de n" << endl;
    archivo_matlab << "% Columna 2: valores de e·log(n)" << endl;
    archivo_matlab << "% Columna 3: valores de n" << endl;
    
    // 3. Archivo de script para MATLAB (.m)
    ofstream script_matlab("graficar_datos.m");
    script_matlab << "% Script de MATLAB para graficar los datos\n";
    script_matlab << "% Ejecutar este script en MATLAB\n\n";
    script_matlab << "try\n";
    script_matlab << "    % Cargar los datos\n";
    script_matlab << "    datos = load('datos_matlab.dat');\n";
    script_matlab << "    n = datos(:,1);\n";
    script_matlab << "    e_log_n = datos(:,2);\n";
    script_matlab << "    n_values = datos(:,3);\n\n";
    script_matlab << "    % Crear figura con dos subgráficas\n";
    script_matlab << "    h = figure('Position', [100, 100, 1200, 500]);\n\n";
    script_matlab << "    % Gráfica normal\n";
    script_matlab << "    subplot(1,2,1);\n";
    script_matlab << "    plot(n, e_log_n, 'bo-', 'LineWidth', 2);\n";
    script_matlab << "    hold on;\n";
    script_matlab << "    plot(n, n_values, 'r--', 'LineWidth', 2);\n";
    script_matlab << "    xlabel('n');\n";
    script_matlab << "    ylabel('Valor');\n";
    script_matlab << "    title('Comparación de e·log(n) vs n');\n";
    script_matlab << "    lh1 = legend('e·log(n)', 'n', 'Location', 'northwest');\n";
    script_matlab << "    grid on;\n\n";
    script_matlab << "    % Marcar el punto n = e donde las funciones se intersecan\n";
    script_matlab << "    e_value = exp(1);\n";
    script_matlab << "    line([e_value e_value], get(gca,'YLim'), 'Color', 'g', 'LineStyle', '--');\n";
    script_matlab << "    text(e_value+0.1, min(get(gca,'YLim'))*2, ['n = e ≈ ' num2str(e_value, '%.4f')], 'Color', 'g');\n\n";
    script_matlab << "    % Gráfica semilogarítmica\n";
    script_matlab << "    subplot(1,2,2);\n";
    script_matlab << "    semilogy(n, e_log_n, 'bo-', 'LineWidth', 2);\n";
    script_matlab << "    hold on;\n";
    script_matlab << "    semilogy(n, n_values, 'r--', 'LineWidth', 2);\n";
    script_matlab << "    xlabel('n');\n";
    script_matlab << "    ylabel('Valor (escala logarítmica)');\n";
    script_matlab << "    title('Comparación en escala logarítmica');\n";
    script_matlab << "    lh2 = legend('e·log(n)', 'n', 'Location', 'northwest');\n";
    script_matlab << "    grid on;\n\n";
    script_matlab << "    % Ajustar diseño\n";
    script_matlab << "    drawnow;\n";
    script_matlab << "    pause(0.5);\n\n";
    script_matlab << "    % Guardar la figura como imagen de manera segura\n";
    script_matlab << "    print(h, 'grafica_matlab.png', '-dpng');\n\n";
    script_matlab << "    % Mostrar mensaje\n";
    script_matlab << "    disp('Gráfica generada y guardada como grafica_matlab.png');\n\n";
    script_matlab << "catch e\n";
    script_matlab << "    disp(['Error: ' e.message]);\n";
    script_matlab << "    disp('Verifique que el archivo datos_matlab.dat existe y tiene el formato correcto');\n";
    script_matlab << "end\n";
    
    // Verificar la desigualdad e·log(n) ≤ n para n ≥ n0
    for (double n = 1.0; n <= max_n; n += (n < 5 ? 0.1 : 1.0)) {
        double e_log_n = e * log(n); // Calcula e·log(n)
        
        // Guardar los datos en los archivos
        archivo_csv << n << "," << e_log_n << "," << n << endl;
        archivo_matlab << fixed << setprecision(6) << n << " " << e_log_n << " " << n << endl;
        
        if (n >= n0) {
            if (e_log_n > n) {
                cumple = false;
                cout << "Falla en n = " << n << ": e·log(n) = " << e_log_n << " > n = " << n << endl;
            }
        }
        
        // Mostrar valores para comparación
        cout << "n = " << n << "\t e·log(n) = " << e_log_n
             << "\t Cumple: " << (e_log_n <= n ? "Sí" : "No") << endl;
    }
    
    // Cerrar los archivos
    archivo_csv.close();
    archivo_matlab.close();
    script_matlab.close();
    
    cout << "\nDatos exportados en los siguientes formatos:" << endl;
    cout << "1. datos_notacion.csv - CSV para uso general" << endl;
    cout << "2. datos_matlab.dat - Formato de datos para MATLAB" << endl;
    cout << "3. graficar_datos.m - Script de MATLAB listo para ejecutar" << endl;

    // Resultado de la demostración
    if (cumple) {
        cout << "\nDemostración exitosa: e·log(n) ≤ n para todo n ≥ " << n0 << endl;
        cout << "Por lo tanto, e^n ∈ O(e·log(n))" << endl;
    } else {
        cout << "\nLa condición falló para algunos valores. Revisar la demostración." << endl;
    }
    int matlabStatus = system("matlab -r \"graficar_datos\"");
   return 0;
}