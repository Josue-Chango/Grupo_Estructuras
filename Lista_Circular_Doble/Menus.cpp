/***************************************************************************************
 *            UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE                                  *
 * Proposito:                      Programa sobre lista simple                         *
 * Autor:                          Josue Chango, Adonny Calero, Eduardo altamirano     *
 * Fecha de creacion:              23/11/2024                                          *
 * Fecha de modificacion:          23/11/2024                                          *
 * Materia:                        Estructura de datos                                 *
 * NRC :                           1978                                                *
 **************************************************************************************/
#include "Menus.h"
#include <windows.h>
#include "Lista_Circular_Doble.cpp"
#include "Nodo_Circular_Doble.cpp"
#include "Validaciones.cpp"
#include "Parqueadero.cpp"
#include <ctime>
//#include <cstdint>
//using byte = unsigned char;



template <typename T>
Menus<T>::Menus()
{
}

template <typename T>
void Menus<T>::setConsoleColor(WORD color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

enum Opciones_Menu_Principal {
    Insertar,
    Buscar,
    Eliminar,
    Mostrar,
    Cifrar,
    Sacar_Vehiculo,
    Salir_Menu_Principal
};

enum Opciones_Menu_Cifrado {
    Cifrado_Cesar,
    Decifrado_Cesar,
    Salir_Menu_Cifrado
};



template<typename T>
void Menus<T>::Menu_Principal(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Insertar",
        "Buscar",
        "Eliminar",
        "Mostrar",
        "cifrar",
        "Sacar Vehiculo",
        "Salir"
    };

    cout << "******************************" << endl;
    cout << "************GARAJE************" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < Salir_Menu_Principal +1; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}

template<typename T>
void Menus<T>::Menu_Cifrado(int opcion) {
    system("cls");
    const char* opciones[] = {
        "Cifrar Cesar",
        "Decifrar Cesar",
        "Salir"
    };

    cout << "******************************" << endl;
    cout << "***********CIFRADO***********" << endl;
    cout << "******************************" << endl;
    for (int i = 0; i < Salir_Menu_Cifrado+1; ++i) {
        if (i == opcion) {
            setConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
            cout << " --> " << opciones[i] << "\n";
            setConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }
        else {
            cout << "     " << opciones[i] << "\n";
        }
    }
    cout << "******************************" << endl;
}

template<typename T>
void Menus<T>::Menu() {
Menus<int> entrada;
    int opcion;
    bool Continuar_Menu_Principal = true;

    std::time_t t;
    std::tm* now;

    Validaciones<std::string> ingresar_string;
    Validaciones<int> ingresar_entero;

    Parqueadero parqueadero(3, 3); // Parqueadero inicial de 3x3
    Lista_Circular_Doble<std::string>* lista_string = new Lista_Circular_Doble<std::string>();
    Lista_Circular_Doble<std::string>* lista_registro = new Lista_Circular_Doble<std::string>();
    int dato_entero;
    std::string dato_string, fecha;
    string nombre1, nombre2, apellido, correo, placa;

    lista_string->cargarDesdeArchivo("Parqueadero.txt");
    
    opcion = 0;
    while (Continuar_Menu_Principal) {
        
        entrada.Menu_Principal(opcion);

        int tecla = _getch();
        switch (tecla) {
        case 72: // Flecha arriba
            opcion = (opcion - 1 + (Salir_Menu_Principal + 1 )) % (Salir_Menu_Principal + 1);
            break;
        case 80: // Flecha abajo
            opcion = (opcion + 1) % (Salir_Menu_Principal + 1 );
            break;
        case 13: // Enter
            switch (opcion) {
            case Sacar_Vehiculo:
                
                system("pause");
                break;
            case Salir_Menu_Principal:
                cout << endl << "Gracias por visitarnos " << endl ;
                Continuar_Menu_Principal=false;
                system("pause");
                break;
            case Insertar: 
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
                    t = std::time(nullptr);
                    now = std::localtime(&t);
                    fecha = to_string(now->tm_year+1900)+ "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_mday) + " " + to_string(now->tm_hour) + ":" + to_string(now->tm_min) + ":" + to_string(now->tm_sec);
                    lista_registro->registro(nombre1, nombre2, apellido, dato_string, correo, placa, fecha);
                    parqueadero.mostrarParqueadero();
                    lista_string->guardarEnArchivo("Parqueadero.txt");
                    lista_registro->guardar_Registro("Registro.txt");
                    //lista_string->insertar_persona(nombre1, nombre2, apellido, dato_string, correo, placa);
                    cout << endl << "Vehiculo ingresado correctamente" << endl;
                    system("pause");
                break;
            case Buscar: // Flecha abajo
                placa = ingresar_string.Ingresar_Placa();
                    cout << endl;
                    if (parqueadero.buscarVehiculo(placa)) {
                        cout << "Vehiculo encontrado." << endl;
                    } else {
                        cout << "Vehiculo no encontrado." << endl;
                    }
                system("pause");
                break;
            case Eliminar: //Eliminar
                placa = ingresar_string.Ingresar_Placa();
                parqueadero.retirarVehiculo(placa);
                system("pause");
                break;
            case Mostrar: //Mostrar
                lista_string->mostrar_persona();
                cout << endl;
                parqueadero.mostrarParqueadero();
                cout << endl;
                system("pause");                    
                break;
            case Cifrar: //cifrar
                system("cls");
                dato_entero = ingresar_entero.ingresar("Ingrese el desplazamiento para cifrar: ", "entero");
                    system("cls");
                    bool continuar_Cifrado=true;
                    opcion = 0;
                while (continuar_Cifrado) {
                    entrada.Menu_Cifrado(opcion);
                     tecla = _getch();
                        switch (tecla) {
                        case 72: // Flecha arriba
                            opcion = (opcion - 1 + (Salir_Menu_Cifrado + 1)) % (Salir_Menu_Cifrado+1);
                            break;
                        case 80: // Flecha abajo
                            opcion = (opcion + 1) % (Salir_Menu_Cifrado +1);
                            break;
                        case 13: // Enter
                            switch (opcion) {
                            case Cifrado_Cesar:
                                lista_string->cifrar_cesar(dato_entero);
                                cout << endl;
                                cout << "Texto cifrado correctamente. " << endl;
                                system("pause");
                                break;
                            case Decifrado_Cesar:
                                lista_string->descifrar_cesar(dato_entero);
                                cout << endl;
                                cout << "Texto descifrado correctamente. " << endl;
                                system("pause");
                                break;
                            case Salir_Menu_Cifrado:
                                continuar_Cifrado = false;
                                break;

                            }
                    }
                }
                break;
            
            break;

            }                    
        }
    }
}