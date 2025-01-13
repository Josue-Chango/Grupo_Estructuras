#include <iostream>
#include <graphics.h>
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

// Función para graficar el árbol
void drawTree(Node* node, int x, int y, int offset) {
    if (node == nullptr) return;

    // Dibujar el nodo actual
    circle(x, y, 20);
    //outtextxy(x - 10, y - 10, to_string(node->data).c_str());
    char buffer[10];
sprintf(buffer, "%d", node->data); // Convierte el entero a una cadena
outtextxy(x - 10, y - 10, buffer); // Usa la cadena para graficar

    // Dibujar el subárbol izquierdo
    if (node->left) {
        line(x, y, x - offset, y + 50);
        drawTree(node->left, x - offset, y + 50, offset / 2);
    }

    // Dibujar el subárbol derecho
    if (node->right) {
        line(x, y, x + offset, y + 50);
        drawTree(node->right, x + offset, y + 50, offset / 2);
    }
}

void visualizeTree(Node* root) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    drawTree(root, getmaxx() / 2, 50, 200); // Dibuja el árbol centrado en la pantalla
    getch();
    closegraph();
}

int main() {
    Node* root = nullptr;
    int value;

    cout << "Ingrese valores para el arbol (0 para finalizar): " << endl;
    while (true) {
        cout << "Valor: ";
        cin >> value;
        if (value == 0) break;
        root = insert(root, value);
    }

    // Visualizar el árbol
    visualizeTree(root);

    return 0;
};