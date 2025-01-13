#include <iostream>
#include <graphics.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// Definición de un nodo del árbol
struct Node {
    int data;
    int level;
    Node* left;
    Node* right;
};


// Funciones para manejar el árbol
Node* createNode(int value) {
    Node* node = new Node();
    node->data = value;
    node->level = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

Node* skew(Node* node) {
    if (node == nullptr || node->left == nullptr) return node;
    if (node->left->level == node->level) {
        Node* left = node->left;
        node->left = left->right;
        left->right = node;
        return left;
    }
    return node;
}

Node* split(Node* node) {
    if (node == nullptr || node->right == nullptr || node->right->right == nullptr) return node;
    if (node->level == node->right->right->level) {
        Node* right = node->right;
        node->right = right->left;
        right->left = node;
        right->level++;
        return right;
    }
    return node;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    root = skew(root);
    root = split(root);
    return root;
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return nullptr;
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        } else {
            Node* temp = root->right;
            while (temp->left != nullptr) temp = temp->left;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) return false;
    if (value < root->data) return search(root->left, value);
    if (value > root->data) return search(root->right, value);
    return true;
}

// Función para mostrar el árbol (en orden)
void inOrder(Node* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Función para graficar el árbol
void drawTree(Node* node, int x, int y, int offset) {
    if (node == nullptr) return;

    circle(x, y, 20);
    char buffer[10];
    sprintf(buffer, "%d", node->data);
    outtextxy(x - 10, y - 10, buffer);

    if (node->left) {
        line(x, y, x - offset, y + 50);
        drawTree(node->left, x - offset, y + 50, offset / 2);
    }

    if (node->right) {
        line(x, y, x + offset, y + 50);
        drawTree(node->right, x + offset, y + 50, offset / 2);
    }
}

void visualizeTree(Node* root) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawTree(root, getmaxx() / 2, 50, 200);
    getch();
    closegraph();

}



// Función de validación de entrada
int leerNumero() {
    string entrada;
    while (true) {
        cout << "Ingrese un número: ";
        cin >> entrada;

        // Validar si la entrada contiene solo dígitos
        bool esNumero = true;
        for (char c : entrada) {
            if (!isdigit(c)) { // Si algún carácter no es un dígito, la entrada no es válida
                esNumero = false;
                break;
            }
        }

        if (esNumero) {
            return stoi(entrada); // Convertir la entrada a entero y retornarla
        } else {
            cout << "Entrada inválida. Por favor, ingrese un número válido." << endl;
        }
    }
}

// Menú principal
int main() {
    Node* root = nullptr;
    int option, value;

    do {
        cout << "\n--- Arbol AA ---\n";
        cout << "1. Insertar\n";
        cout << "2. Buscar\n";
        cout << "3. Eliminar\n";
        cout << "4. Mostrar (InOrder)\n";
        cout << "5. Visualizar\n";
        cout << "6. Salir\n";
        cout << "Elija una opcion: ";
        option = leerNumero(); // Leer opción validada

        switch (option) {
        case 1:
            cout << "Ingrese el valor a insertar: ";
            value = leerNumero(); // Leer valor validado
            root = insert(root, value);
            break;
        case 2:
            cout << "Ingrese el valor a buscar: ";
            value = leerNumero(); // Leer valor validado
            if (search(root, value)) {
                cout << "Valor encontrado.\n";
            } else {
                cout << "Valor no encontrado.\n";
            }
            break;
        case 3:
            cout << "Ingrese el valor a eliminar: ";
            value = leerNumero(); // Leer valor validado
            root = deleteNode(root, value);
            break;
        case 4:
            cout << "Valores del arbol (InOrder): ";
            inOrder(root);
            cout << endl;
            break;
        case 5:
            visualizeTree(root);
            break;
        case 6:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }
    } while (option != 6);

    return 0;
}
