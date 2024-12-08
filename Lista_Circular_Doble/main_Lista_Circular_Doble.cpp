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
#include "Parqueadero.cpp"
//#include <windows.h>
using namespace std;

int main() {
    Parqueadero parqueadero(3, 3); // Parqueadero inicial de 3x3
    parqueadero.mostrarParqueadero();
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
                cout << "8. Ingresar vehiculo" << endl;
                cout << "9. Sacar vehiculo" << endl;
                cout << "10. Mostrar Parqueadero" << endl;
                cout << "11. Salir" << endl;
                opcion = ingresar_entero.ingresar("Opcion: ","entero");
                cout << endl;
                switch (opcion) {
                case 1: //Insertar
                lista_string->cargarDesdeArchivo("Parqueadero.txt");
                    do{
                        system("cls");
                        dato_string = lista_string->validar_cedula_existente();
                        cout << endl;
                        nombre1 = ingresar_string.ingresar("Ingrese su primer nombre: ", "string");
                        cout << endl;
                        nombre2 = ingresar_string.ingresar("Ingrese su segundo nombre: ", "string");
                        cout <<endl;
                        apellido = ingresar_string.ingresar("Ingrese su apellido: ", "string");
                        cout << endl;
                        placa = lista_string->validar_placa_existente();
                        cout << endl;
                        if((nombre1 == "" && nombre2 == "") || apellido == ""){
                            cout << "Persona no ingresada" << endl << "La persona necesita al menos un nombre y un apellido " << endl;
                            system("pause");
                        }
                    }while((nombre1 == "" && nombre2 == "") || apellido =="");
                    
                    correo = lista_string->generar_correo(nombre1, nombre2, apellido);
                    parqueadero.ingresarVehiculo(placa, nombre1, nombre2, apellido, dato_string, correo);
                    lista_string->insertar_persona(nombre1, nombre2, apellido, dato_string, correo, placa);
                    parqueadero.mostrarParqueadero();

                    //lista_string->insertar_persona(nombre1, nombre2, apellido, dato_string, correo, placa);

                    cout << endl << "Vehiculo ingresado correctamente" << endl;
                    system("pause");
                    break;
                case 2: //Buscar
                    /*dato_string = ingresar_string.ingresar("ingrese el dato a buscar: ", "string");
                    cout << endl;
                    lista_string->buscar(dato_string);
                    system("pause");*/
                    cout << endl << "funcion en mantenimiento" << endl;
                    system("pause");
                    break;
                case 3: //Eliminar
                    /*dato_char = ingresar_letra.ingresar("Ingrese la letra: ", "char");
                    cout << endl;
                    lista_string->eliminarLetra(dato_char);*/
                    cout << endl << "funcion en mantenimiento" << endl;
                    system("pause");
                    break;
                case 4: //Mostrar
                    lista_string->mostrar_persona();
                    cout << endl;
                    parqueadero.mostrarParqueadero();
                    cout << endl;
                    system("pause");
                    break;
                case 5: //Guardar
                    lista_string->guardarEnArchivo("Parqueadero.txt");
                    system("pause");
                    break;
                case 6: //Cargar
                    lista_string->cargarDesdeArchivo("Parqueadero.txt");
                    system("pause");
                    break;
                case 7: //cifrar
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
                case 8: //Ingresar vehiculo
                    cout << endl << "funcion en mantenimiento" << endl;
                    system("pause");
                    break;
                case 9: //Sacar vehiculo
                    placa = ingresar_string.Ingresar_Placa();
                    parqueadero.retirarVehiculo(placa);
                    break;
                case 10: //Mostrar Parqueadero
                    //parqueadero.mostrarParqueadero();
                    cout << endl << "funcion en mantenimiento" << endl;
                    system("pause");
                    break;
                case 11: //Salir
                    break;
                default:
                    cout << "Opcion no valida, intente de nuevo" << endl;
                    system("pause");
                    break;
                }
            } while (opcion != 11);
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
    Parqueadero parqueadero(3, 3); // Parqueadero inicial de 3x3

    parqueadero.mostrarParqueadero();

    // Ingreso de vehículos
    parqueadero.ingresarVehiculo("ABC123", "Juan", "Carlos", "Pérez", "1234567890", "juan.perez@gmail.com");
    parqueadero.ingresarVehiculo("XYZ789", "Maria", "Luisa", "Gómez", "0987654321", "maria.gomez@gmail.com");

    // Mostrar el parqueadero actualizado
    parqueadero.mostrarParqueadero();

    // Retiro de un vehículo
    parqueadero.retirarVehiculo("ABC123");

    // Mostrar el parqueadero actualizado
    parqueadero.mostrarParqueadero();

    // Expandir el parqueadero
    parqueadero.expandirParqueadero(2, 2);
    parqueadero.mostrarParqueadero();
    
    
    
    
    
    
    
    
    */



    system("pause");
    return 0;
}
