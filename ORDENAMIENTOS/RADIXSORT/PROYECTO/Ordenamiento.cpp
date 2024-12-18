#include <iostream>
#include <vector>
#include <algorithm>
#include "Coche.h"

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
