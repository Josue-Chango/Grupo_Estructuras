#include <iostream>
#include <vector>

void extraeIndicesParesImpares(const std::vector<int>& a, std::vector<int>& lista_pares, std::vector<int>& lista_impares, int index = 0) {
    if (index >= a.size()) {
        return;
    }
    
    if (index % 2 == 0) {
        lista_pares.push_back(a[index]);
    } else {
        lista_impares.push_back(a[index]);
    }
    
    extraeIndicesParesImpares(a, lista_pares, lista_impares, index + 1);
}

int main() {
    int n, num;
    std::vector<int> a, lista_pares, lista_impares;
    
    std::cout << "Ingrese la cantidad de elementos en la lista: ";
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::cout << "Ingrese el elemento " << i + 1 << ": ";
        std::cin >> num;
        a.push_back(num);
    }
    
    extraeIndicesParesImpares(a, lista_pares, lista_impares);
    
    std::cout << "Lista de indices pares: ";
    for (int num : lista_pares) {
        std::cout << num << " ";
    }
    
    std::cout << "\nLista de indices impares: ";
    for (int num : lista_impares) {
        std::cout << num << " ";
    }
    
    std::cout << "\nPresione Enter para salir...";
    std::cin.ignore(); 
    std::cin.get(); 
    
    return 0;
}
