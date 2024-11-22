#ifndef __VALID_H__
#define __VALID_H__

#include <windows.h>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif

#ifdef _WIN32
#define DLL_EXPORT __declspec(dllexport) // Exportaci�n de funciones en Windows
#else
#define DLL_EXPORT
#endif


#ifdef __cplusplus
extern "C" {
    DLL_EXPORT int ingresar(char* msj);
    DLL_EXPORT char ingresarLetra(char* msj);
    DLL_EXPORT float ingresarFloat(char* msj);
    DLL_EXPORT std::string ingresarString(char* msj);
    DLL_EXPORT double ingresarDouble(char* msj);

    DLL_EXPORT int sumarEnteros(int a, int b);
    DLL_EXPORT float sumarFlotantes(float a, float b);
    DLL_EXPORT int contarDigitos(int numero);
    DLL_EXPORT int contarVocales(std::string texto);
    DLL_EXPORT std::string esPalindromo(std::string texto);
    DLL_EXPORT std::string invertirCadena(std::string texto);
    DLL_EXPORT char convertirAMayusculaManual(char letra);
    DLL_EXPORT std::string verificarVocalOConsonante(char letra);
    DLL_EXPORT std::string concatenarStrings(std::string str1, std::string str2);
    DLL_EXPORT float restarFlotantes(float num1, float num2);
}
#endif

#endif // __VALID_H__
