#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Coche.h"
#include <functional>
#include <cmath>

template <typename T, typename Comparator>
int partition(std::vector<T>& lista, int low, int high, Comparator comp) {
    T pivot = lista[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (comp(lista[j], pivot)) {
            i++;
            std::swap(lista[i], lista[j]);
        }
    }
    std::swap(lista[i + 1], lista[high]);
    return i + 1;
}

template <typename T, typename Comparator>
void quickSort(std::vector<T>& lista, int low, int high, Comparator comp) {
    if (low < high) {
        int pi = partition(lista, low, high, comp);
        quickSort(lista, low, pi - 1, comp);
        quickSort(lista, pi + 1, high, comp);
    }
}

template <typename T, typename Comparator>
void bubbleSortPass(std::vector<T>& lista, Comparator comp, int n) {
    // Función auxiliar que realiza una pasada completa de intercambios
    if (n <= 1) return;

    for (int j = 0; j < n - 1; j++) {
        if (!comp(lista[j], lista[j + 1])) {
            std::swap(lista[j], lista[j + 1]);
        }
    }
}

template <typename T, typename Comparator>
void bubbleSortRecursive(std::vector<T>& lista, Comparator comp, int n) {
    // Función recursiva principal
    if (n <= 1) return;
    // Realizar una pasada completa de intercambios
    bubbleSortPass(lista, comp, n);
    // Llamada recursiva con un rango reducido
    bubbleSortRecursive(lista, comp, n - 1);
}

// Función wrapper para iniciar el ordenamiento
template <typename T, typename Comparator>
void bubbleSort(std::vector<T>& lista, Comparator comp) {
    bubbleSortRecursive(lista, comp, lista.size());
}

template <typename T, typename Comparator>
void ordenarLista(ListaCircularDoble<T>& lista, Comparator comp) {
    std::vector<T> elementos;
    
    Nodo<T>* aux = lista.getPrimero();
    do {   
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    quickSort(elementos, 0, elementos.size() - 1, comp);

    aux = lista.getPrimero();
    int index = 0;
    do {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    lista.mostrar(lista.getPrimero());
}

template <typename T, typename Comparator>
void ordenarListaBubbleSort(ListaCircularDoble<T>& lista,Comparator comp){
    std::vector<T> elementos;

    Nodo<T>* aux = lista.getPrimero();
    do{                     // Extraer los elementos de la lista circular doble
        elementos.push_back(aux->getDato());
        aux= aux->getSiguiente();
    }while (aux != lista.getPrimero());

    bubbleSort(elementos,comp);// Ordenar los elementos

    aux=lista.getPrimero();
    int index=0;// Volver a insertar los elementos ordenados en la lista circular doble
    do{
        aux->setDato(elementos[index++]);
        aux=aux->getSiguiente();
    }while (aux != lista.getPrimero());

    lista.mostrar(lista.getPrimero());
}

template <typename T>
void ordenarListaBucket(ListaCircularDoble<T>& lista, std::function<std::string(const T&)> getKey) {
    std::vector<T> elementos;

    // Extraer los elementos de la lista circular doble
    Nodo<T>* aux = lista.getPrimero();
    if (aux == nullptr) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }

    do {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    
    const int bucketCount = 256; 
    std::vector<std::vector<T>> buckets(bucketCount);

    // Distribuir los elementos en los buckets
    for (const auto& item : elementos) {
        std::string key = getKey(item);
        if (!key.empty()) {
            char firstChar = tolower(key[0]); // Usar el primer carácter de la clave
            int bucketIndex = static_cast<int>(firstChar);
            buckets[bucketIndex].push_back(item);
        }
    }

    // Limpiar el vector de elementos
    elementos.clear();

    // Ordenar cada bucket y volver a insertar en el vector de elementos
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), [&getKey](const T& a, const T& b) {
            return getKey(a) < getKey(b); // Usar la clave para ordenar
        });
        elementos.insert(elementos.end(), bucket.begin(), bucket.end());
    }

    // Volver a insertar los elementos ordenados en la lista circular doble
    aux = lista.getPrimero();
    int index = 0;
    do {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    // Mostrar la lista ordenada
    lista.mostrar(lista.getPrimero());
}

template <typename T, typename Comparator>
void ordenarListaShellSort(ListaCircularDoble<T>& lista, Comparator comp) {
    // Contar el número de elementos en la lista circular doble
    int n = 0;
    Nodo<T>* aux = lista.getPrimero();
    if (aux != nullptr) {
        do {
            n++;
            aux = aux->getSiguiente();
        } while (aux != lista.getPrimero());
    }

    // Crear un arreglo dinámico para almacenar los elementos
    T* elementos = new T[n];

    // Copiar los elementos de la lista al arreglo
    aux = lista.getPrimero();
    for (int i = 0; i < n; ++i) {
        elementos[i] = aux->getDato();
        aux = aux->getSiguiente();
    }

    // Implementación del algoritmo Shell Sort
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            T temp = elementos[i];
            int j;
            for (j = i; j >= gap && comp(temp, elementos[j - gap]); j -= gap) {
                elementos[j] = elementos[j - gap];
            }
            elementos[j] = temp;
        }
    }

    // Volver a copiar los elementos ordenados en la lista
    aux = lista.getPrimero();
    for (int i = 0; i < n; ++i) {
        aux->setDato(elementos[i]);
        aux = aux->getSiguiente();
    }

    // Liberar memoria dinámica
    delete[] elementos;

    // Mostrar la lista ordenada
    lista.mostrar(lista.getPrimero());
}

template <typename T, typename KeyExtractor>
void radixSortByString(std::vector<T>& elementos, KeyExtractor getKey) {
    int maxLength = 0;
    for (const auto& item : elementos) {
        int length = static_cast<int>(getKey(item).length());
        maxLength = std::max(maxLength, length);
    }

    for (int i = maxLength - 1; i >= 0; i--) {
        std::vector<std::vector<T>> buckets(256);
        for (const auto& item : elementos) {
            std::string key = getKey(item);
            int charIndex = static_cast<int>(key.length()) - 1 - i;
            int charValue = (charIndex >= 0) ? static_cast<int>(key[charIndex]) : 0;
            buckets[charValue].push_back(item);
        }

        elementos.clear();
        for (auto& bucket : buckets) {
            for (const auto& item : bucket) {
                elementos.push_back(item);
            }
        }
    }
}

template <typename T, typename KeyExtractor>
void radixSortByInt(std::vector<T>& elementos, KeyExtractor getKey) {
    int maxValue = 0;
    for (const auto& item : elementos) {
        int value = getKey(item);
        maxValue = std::max(maxValue, value);
    }

    for (int exp = 1; maxValue / exp > 0; exp *= 10) {
        std::vector<std::vector<T>> buckets(10);
        for (const auto& item : elementos) {
            int digit = (getKey(item) / exp) % 10;
            buckets[digit].push_back(item);
        }

        elementos.clear();
        for (auto& bucket : buckets) {
            for (const auto& item : bucket) {
                elementos.push_back(item);
            }
        }
    }
}


template <typename T, typename KeyExtractor>
void ordenarListaPorRadix(ListaCircularDoble<T>& lista, KeyExtractor getKey) {
    std::vector<T> elementos;

    // Extraer elementos de la lista circular a un vector
    Nodo<T>* aux = lista.getPrimero();
    do {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    // Determinar si estamos ordenando por cadena o por entero
    using KeyType = typename std::invoke_result<KeyExtractor, T>::type;
    if constexpr (std::is_same<KeyType, std::string>::value) {
        // Ordenar por cadena usando Radix Sort
        radixSortByString(elementos, getKey);
    } else if constexpr (std::is_integral<KeyType>::value) {
        // Ordenar por entero usando Radix Sort
        radixSortByInt(elementos, getKey);
    } else {
        static_assert(false, "El tipo de clave no es compatible con Radix Sort");
    }

    // Reinsertar elementos ordenados en la lista circular
    aux = lista.getPrimero();
    int index = 0;
    do {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    } while (aux != lista.getPrimero());

    lista.mostrar(lista.getPrimero());
}

/*template <typename T>
void radixSort(T* arr, int n, int base) {
    for (int posicion = 0; posicion < sizeof(T) * 8 / std::log2(base); ++posicion) {
        // Crear un arreglo de conteo
        int* conteo = new int[base]();
        T* salida = new T[n];

        // Contar ocurrencias de cada dígito
        for (int i = 0; i < n; i++) {
            int digito = obtenerDigito(arr[i], base, posicion);
            conteo[digito]++;
        }

        // Cambiar conteo para que contenga posiciones
        for (int i = 1; i < base; i++) {
            conteo[i] += conteo[i - 1];
        }

        // Construir el arreglo de salida
        for (int i = n - 1; i >= 0; i--) {
            int digito = obtenerDigito(arr[i], base, posicion);
            salida[conteo[digito] - 1] = arr[i];
            conteo[digito]--;
        }

        // Copiar el arreglo de salida de nuevo a arr
        for (int i = 0; i < n; i++) {
            arr[i] = salida[i];
        }

        // Liberar memoria
        delete[] conteo;
        delete[] salida;
    }
}

template <typename T, typename Comparator>
void ordenarListaRadix(ListaCircularDoble<T>& lista, Comparator comp) {
    // Contar el número de elementos en la lista circular doble
    int n = 0;
    Nodo<T>* aux = lista.getPrimero();
    if (aux != nullptr) {
        do {
            n++;
            aux = aux->getSiguiente();
        } while (aux != lista.getPrimero());
    }

    // Crear un arreglo dinámico para almacenar los elementos
    T* elementos = new T[n];

    // Copiar los elementos de la lista al arreglo
    aux = lista.getPrimero();
    for (int i = 0; i < n; ++i) {
        elementos[i] = aux->getDato();
        aux = aux->getSiguiente();
    }

    // Función para obtener el dígito en una posición específica
    auto obtenerDigito = [](T num, int base, int posicion) {
        return (num / static_cast<T>(base << posicion)) % base;
    };

    // Llamar a la función de ordenamiento por Radix
    radixSort(elementos, n, 10); // Base 10 para números decimales

    // Volver a copiar los elementos ordenados en la lista
    aux = lista.getPrimero();
    for (int i = 0; i < n; ++i) {
        aux->setDato(elementos[i]);
        aux = aux->getSiguiente();
    }

    // Liberar memoria dinámica
    delete[] elementos;

    // Mostrar la lista ordenada
    lista.mostrar(lista.getPrimero());
}
*/

