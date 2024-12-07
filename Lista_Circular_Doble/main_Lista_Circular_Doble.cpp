/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo Altamirano     *
 * Fecha de creacion:              18/11/2024                                          *
 * Fecha de modificacion:          18/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Lista_Circular_Doble.cpp"
#include "Nodo_Circular_Doble.cpp"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include "Validaciones.cpp"
//#include <windows.h>
using namespace std;

int main() {
    Lista_Circular_Doble<int>* lista_entero = new Lista_Circular_Doble<int>();
    Lista_Circular_Doble<float>* lista_flotante = new Lista_Circular_Doble<float>();
    Lista_Circular_Doble<double>* lista_Doble = new Lista_Circular_Doble<double>();
    Lista_Circular_Doble<std::string>* lista_string = new Lista_Circular_Doble<std::string>();
    //Lista_Circular<string>* lista_personas = new Lista_Circular<string>();
    Lista_Circular_Doble<char>* lista_letras = new Lista_Circular_Doble<char>();

    int opcion, dato_entero;
    float dato_flotante;
    double dato_Doble;
    std::string dato_string;
    char dato_char;
    string nombre1, nombre2, apellido, correo, placa;

    Validaciones<int> ingresar_entero;
    Validaciones<float> ingresar_flotante;
    Validaciones<double> ingresar_Doble;
    Validaciones<std::string> ingresar_string;
    Validaciones<char> ingresar_letra;

    /*HINSTANCE hDLL = LoadLibrary("ValidDll.dll");
    if (!hDLL) {
        std::cerr << "No se pudo cargar la DLL.\n";
        return 1;
    }*/


   do {
        system("cls");
        cout << "***********Listas Simples***********" << endl;
        cout << "1. Lista de enteros" << endl;
        cout << "2. lista de flotantes" << endl;
        cout << "3. lista de Circulars" << endl;
        cout << "4. lista de strings" << endl;
        cout << "5. lista de letras" << endl;
        cout << "6. salir" << endl;
        opcion = ingresar_entero.ingresar("Opcion: ","entero");
        cout << endl;
        switch (opcion) {
        case 1:
            do {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1:
                    dato_entero = ingresar_entero.ingresar("ingrese el dato a insertar: ", "entero");
                    cout << endl;
                    lista_entero->insertar(dato_entero);
                    cout << endl << "Dato ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2:
                    dato_entero = ingresar_entero.ingresar("ingrese el dato a buscar: ", "entero");
                    cout << endl;
                    lista_entero->buscar(dato_entero);
                    system("pause");
                    break;
                case 3:
                    dato_entero = ingresar_entero.ingresar("ingrese el dato a eliminar: ", "entero");
                    cout << endl;
                    lista_entero->eliminar(dato_entero);
                    system("pause");
                    break;
                case 4:
                    lista_entero->mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 2:
            do {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1:
                    dato_flotante = ingresar_flotante.ingresar("ingrese el dato a insertar: ", "flotante");
                    cout << endl;
                    lista_flotante->insertar(dato_flotante);
                    cout << endl << "Dato ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2:
                    dato_flotante = ingresar_flotante.ingresar("ingrese el dato a buscar: ", "flotante");
                    cout << endl;
                    lista_flotante->buscar(dato_flotante);
                    system("pause");
                    break;
                case 3:
                    dato_flotante = ingresar_flotante.ingresar("ingrese el dato a eliminar: ", "flotante");
                    cout << endl;
                    lista_flotante->eliminar(dato_flotante);
                    system("pause");
                    break;
                case 4:
                    lista_flotante->mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 3:
            do {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1:
                    dato_Doble = ingresar_Doble.ingresar("ingrese el dato a insertar: ", "double");
                    cout << endl;
                    lista_Doble->insertar(dato_Doble);
                    cout << endl << "Dato ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2:
                    dato_Doble = ingresar_Doble.ingresar("ingrese el dato a buscar: ", "double");
                    cout << endl;
                    lista_Doble->buscar(dato_Doble);
                    system("pause");
                    break;
                case 3:
                    dato_Doble = ingresar_Doble.ingresar("ingrese el dato a eliminar: ", "double");
                    cout << endl;
                    lista_Doble->eliminar(dato_Doble);
                    system("pause");
                    break;
                case 4:
                    lista_Doble->mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 4:
            do {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Guardar" << endl;
                cout << "6. Cargar" << endl;
                cout << "7. cifrar" << endl;
                cout << "8. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1:
                    do{
                        system("cls");
                        nombre1 = ingresar_string.ingresar("Ingrese su primer nombre: ", "string");
                        cout << endl;
                        nombre2 = ingresar_string.ingresar("Ingrese su segundo nombre: ", "string");
                        cout <<endl;
                        apellido = ingresar_string.ingresar("Ingrese su apellido: ", "string");
                        cout << endl;
                        placa = ingresar_string.Ingresar_Placa();
                        cout << endl;
                        if((nombre1 == "" && nombre2 == "") || apellido == ""){
                            cout << "Persona no ingresada" << endl << "La persona necesita al menos un nombre y un apellido " << endl;
                            system("pause");
                        }
                    }while((nombre1 == "" && nombre2 == "") || apellido =="");
                    dato_string = lista_string->validar_cedula_existente();
                    correo = lista_string->generar_correo(nombre1, nombre2, apellido);
                    lista_string->insertar_persona(nombre1, nombre2, apellido, dato_string, correo, placa);
                    cout << endl << "Persona ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2:
                    dato_string = ingresar_string.ingresar("ingrese el dato a buscar: ", "string");
                    cout << endl;
                    lista_string->buscar(dato_string);
                    system("pause");
                    break;
                case 3:
                    dato_char = ingresar_letra.ingresar("Ingrese la letra: ", "char");
                    cout << endl;
                    lista_string->eliminarLetra(dato_char);
                    system("pause");
                    break;
                case 4:
                    lista_string->mostrar_persona();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    lista_string->guardarEnArchivo("Principal.txt");
                    system("pause");
                    break;
                case 6:
                    lista_string->cargarDesdeArchivo("Principal.txt");
                    system("pause");
                    break;
                case 7:
                    dato_entero = ingresar_entero.ingresar("Ingrese el desplazamiento para cifrar: ", "entero");
                    do{
                        system("cls");
                        cout << "***********Listas Simples***********" << endl;
                        cout << "1. Cifrado Cesar" << endl;
                        cout << "2. Decifrado Cesar" << endl;
                        cout << "3. Salir" << endl;
                        opcion = ingresar_entero.ingresar("Opcion: ","entero");
                        cout << endl;
                        switch (opcion) {
                        case 1:
                            lista_string->cifrar_cesar(dato_entero);
                            cout << endl;
                            cout << "Texto cifrado correctamente. " << endl;
                            system("pause");
                            break;
                        case 2:
                            lista_string->descifrar_cesar(dato_entero);
                            cout << endl;
                            cout << "Texto descifrado correctamente. " << endl;
                            system("pause");
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Opcion no valida, intente de nuevo" << endl;
                            system("pause");
                            break;
                        }
                    }while (opcion != 3);
                    break;
                case 8:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 8);
            break;
        case 5:
            do {
                system("cls");
                cout << "***********Listas Simples***********" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Buscar" << endl;
                cout << "3. Eliminar" << endl;
                cout << "4. Mostrar" << endl;
                cout << "5. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1:
                    dato_char = ingresar_letra.ingresar("ingrese el dato a insertar: ", "char");
                    cout << endl;
                    lista_letras->insertar(dato_char);
                    cout << endl << "Dato ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2:
                    dato_char = ingresar_letra.ingresar("ingrese el dato a buscar: ", "char");
                    cout << endl;
                    lista_letras->buscar(dato_char);
                    system("pause");
                    break;
                case 3:
                    dato_char = ingresar_letra.ingresar("ingrese el dato a eliminar: ", "char");
                    cout << endl;
                    lista_letras->eliminar(dato_char);
                    system("pause");
                    break;
                case 4:
                    lista_letras->mostrar();
                    cout << endl;
                    system("pause");
                    break;
                case 5:
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 5);
            break;
        case 6:
            cout << "Gracias por visitarnos" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion no valida, intente de nuevo" << endl;
            system("pause");
            break;
        }
    } while (opcion != 6);

    delete[] lista_entero;
    delete[] lista_Doble;
    delete[] lista_flotante;
    delete[] lista_letras;
    delete[] lista_string;
    
    /*
       // Crear un parqueadero con 10 espacios iniciales y un radio (que no se usa mucho aquí)
    Parqueadero parqueadero(10, 5);  // 10 espacios y radio 5 para la visualización

    // Mostrar el parqueadero inicial
    std::cout << "Parqueadero inicial:" << std::endl;
    parqueadero.mostrarParqueaderoCircular();

    // Ocupamos algunos espacios y mostramos las posiciones
    std::cout << "\nOcupando algunos espacios:" << std::endl;
    parqueadero.ocuparEspacio(0);  // Vehículo en el primer espacio
    parqueadero.ocuparEspacio(3);  // Vehículo en el cuarto espacio
    parqueadero.ocuparEspacio(5);  // Vehículo en el sexto espacio
    parqueadero.ocuparEspacio(7);  // Vehículo en el octavo espacio
    parqueadero.ocuparEspacio(9);  // Vehículo en el décimo espacio

    // Mostrar el parqueadero después de ocupar los espacios
    std::cout << "\nParqueadero después de ocupar espacios:" << std::endl;
    parqueadero.mostrarParqueaderoCircular();

    // Expandir el parqueadero agregando 5 nuevos espacios
    std::cout << "\nExpandimos el parqueadero agregando 5 espacios más..." << std::endl;
    parqueadero.expandirEspacios(15);  // Ahora hay 15 espacios

    // Mostrar el parqueadero después de la expansión
    std::cout << "\nParqueadero después de la expansión:" << std::endl;
    parqueadero.mostrarParqueaderoCircular();

    // Ocupamos algunos de los nuevos espacios
    std::cout << "\nOcupando más espacios después de la expansión:" << std::endl;
    parqueadero.ocuparEspacio(10);  // Vehículo en el espacio 11
    parqueadero.ocuparEspacio(12);  // Vehículo en el espacio 13

    // Mostrar el parqueadero después de ocupar más espacios
    std::cout << "\nParqueadero después de ocupar más espacios:" << std::endl;
    parqueadero.mostrarParqueaderoCircular();
    
    
    
    
    
    
    
    
    */



    system("pause");
    return 0;
}
