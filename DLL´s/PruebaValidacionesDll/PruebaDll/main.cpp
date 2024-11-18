#include <iostream>
#include <windows.h>  // Para la gestión de DLLs

typedef int (*IngresarInt)(char*);
typedef char (*IngresarLetra)(char*);
typedef float (*IngresarFloat)(char*);
typedef std::string (*IngresarString)(char*);
typedef double (*IngresarDouble)(char*);

int main() {
    // Cargar la DLL
    HINSTANCE hDLL = LoadLibrary("ValidacionesDLL.dll");
    if (!hDLL) {
        std::cerr << "No se pudo cargar la DLL.\n";
        return 1;
    }

    // Cargar las funciones desde la DLL
    IngresarInt ingresar = (IngresarInt)GetProcAddress(hDLL, "ingresar");
    IngresarLetra ingresarLetra = (IngresarLetra)GetProcAddress(hDLL, "ingresarLetra");
    IngresarFloat ingresarFloat = (IngresarFloat)GetProcAddress(hDLL, "ingresarFloat");
    IngresarString ingresarString = (IngresarString)GetProcAddress(hDLL, "ingresarString");
    IngresarDouble ingresarDouble = (IngresarDouble)GetProcAddress(hDLL, "ingresarDouble");

    if (!ingresar || !ingresarLetra || !ingresarFloat || !ingresarString || !ingresarDouble) {
        std::cerr << "No se pudieron cargar algunas funciones desde la DLL.\n";
        FreeLibrary(hDLL);
        return 1;
    }

    // Probar las funciones
    char mensaje[] = "Ingrese un número entero: ";
    int numero = ingresar(mensaje);
    std::cout << "\nNúmero ingresado: " << numero << "\n";

    char mensajeLetra[] = "Ingrese una letra: ";
    char letra = ingresarLetra(mensajeLetra);
    std::cout << "\nLetra ingresada: " << letra << "\n";

    char mensajeFloat[] = "Ingrese un número flotante: ";
    float numeroFloat = ingresarFloat(mensajeFloat);
    std::cout << "\nNúmero flotante ingresado: " << numeroFloat << "\n";

    char mensajeString[] = "Ingrese una cadena de texto: ";
    std::string texto = ingresarString(mensajeString);
    std::cout << "\nTexto ingresado: " << texto << "\n";

    char mensajeDouble[] = "Ingrese un número double: ";
    double numeroDouble = ingresarDouble(mensajeDouble);
    std::cout << "\nNúmero double ingresado: " << numeroDouble << "\n";

    // Liberar la DLL
    FreeLibrary(hDLL);
    return 0;
}
