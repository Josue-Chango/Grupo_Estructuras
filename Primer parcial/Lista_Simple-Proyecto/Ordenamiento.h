#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "Coche.h"
#include "Lista.h"
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
    if (n <= 1) return;
    for (int j = 0; j < n - 1; j++) {
        if (!comp(lista[j], lista[j + 1])) {
            std::swap(lista[j], lista[j + 1]);
        }
    }
}

template <typename T, typename Comparator>
void bubbleSortRecursive(std::vector<T>& lista, Comparator comp, int n) {
    if (n <= 1) return;
    bubbleSortPass(lista, comp, n);
    bubbleSortRecursive(lista, comp, n - 1);
}

template <typename T, typename Comparator>
void ordenarLista(ListaSimple<T>& lista, Comparator comp) {
    std::vector<T> elementos;
    Nodo<T>* aux = lista.getPrimero();
    while (aux) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    quickSort(elementos, 0, elementos.size() - 1, comp);

    aux = lista.getPrimero();
    int index = 0;
    while (aux) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}

template <typename T, typename Comparator>
void ordenarListaBubbleSort(ListaSimple<T>& lista, Comparator comp) {
    std::vector<T> elementos;
    Nodo<T>* aux = lista.getPrimero();
    while (aux) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    // Uso de bubbleSortRecursive en lugar de bubbleSort
    bubbleSortRecursive(elementos, comp, elementos.size());

    aux = lista.getPrimero();
    int index = 0;
    while (aux) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}

template <typename T>
void ordenarListaBucket(ListaSimple<T>& lista, std::function<std::string(const T&)> getKey) {
    std::vector<T> elementos;
    Nodo<T>* aux = lista.getPrimero();
    while (aux) {
        elementos.push_back(aux->getDato());
        aux = aux->getSiguiente();
    }

    const int bucketCount = 256;
    std::vector<std::vector<T>> buckets(bucketCount);

    for (const auto& item : elementos) {
        std::string key = getKey(item);
        if (!key.empty()) {
            char firstChar = tolower(key[0]);
            int bucketIndex = static_cast<int>(firstChar);
            buckets[bucketIndex].push_back(item);
        }
    }

    elementos.clear();
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end(), [&getKey](const T& a, const T& b) {
            return getKey(a) < getKey(b);
        });
        elementos.insert(elementos.end(), bucket.begin(), bucket.end());
    }

    aux = lista.getPrimero();
    int index = 0;
    while (aux) {
        aux->setDato(elementos[index++]);
        aux = aux->getSiguiente();
    }

    lista.mostrar(lista.getPrimero());
}