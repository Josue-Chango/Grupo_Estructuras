#include "Grafo.h"
#include <queue>
#include <iostream>
#include <graphics.h>
#include <cmath> // Include cmath for sqrt
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
#include <cstdlib> // Para rand()
#include <ctime>   // Para time()

Grafo::Grafo() {
    srand(time(0)); // Inicializar aleatoriedad

    // Crear los nodos
    for (int i = 0; i < 8; ++i) {
        nodos.push_back(new NodoGrafo(i));
    }

    int totalAristas = rand() % 12 + 5; // Genera entre 5 y 16 aristas

    for (int i = 0; i < totalAristas; ++i) {
        int origen = rand() % 8;
        int destino = rand() % 8;

        if (origen != destino) { // Evitar auto-conexiones
            bool yaExiste = false;

            // Verificar que la arista no esté duplicada
            for (NodoGrafo* ady : nodos[origen]->adyacentes) {
                if (ady->valor == destino) {
                    yaExiste = true;
                    break;
                }
            }

            if (!yaExiste) {
                nodos[origen]->adyacentes.push_back(nodos[destino]);
            }
        }
    }
}

void Grafo::agregarArista(int origen, int destino, bool dirigido) {
    nodos[origen]->adyacentes.push_back(nodos[destino]);
    if (!dirigido) {
        nodos[destino]->adyacentes.push_back(nodos[origen]);
    }
    std::cout << "Arista agregada: " << origen << " -> " << destino << std::endl;
}

void Grafo::dibujarFlecha(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) return; // Evita dibujar flechas entre el mismo nodo

    std::cout << "Dibujando flecha de (" << x1 << ", " << y1 << ") a (" << x2 << ", " << y2 << ")" << std::endl;

    // Calcular la dirección y longitud de la flecha
    int dx = x2 - x1;
    int dy = y2 - y1;
    float length = sqrt(dx * dx + dy * dy);

    // Tamaño de la punta de la flecha
    int arrowSize = 15;
    
    // Ajustar los puntos finales para que la flecha no toque los círculos
    float nodeRadius = 15; // Radio de los nodos
    float ratio = (length - nodeRadius) / length;
    
    // Nuevos puntos finales
    int endX = x1 + (dx * ratio);
    int endY = y1 + (dy * ratio);
    
    // Dibujar la línea principal
    line(x1, y1, endX, endY);

    // Calcular los puntos para la punta de la flecha
    float angle = atan2(dy, dx);
    float arrowAngle = 0.5; // Ángulo de la punta de la flecha (en radianes)

    // Puntos para la punta de la flecha
    int point1X = endX - arrowSize * cos(angle - arrowAngle);
    int point1Y = endY - arrowSize * sin(angle - arrowAngle);
    int point2X = endX - arrowSize * cos(angle + arrowAngle);
    int point2Y = endY - arrowSize * sin(angle + arrowAngle);

    // Dibujar la punta de la flecha como un triángulo relleno
    int points[8] = {
        endX, endY,
        point1X, point1Y,
        point2X, point2Y,
        endX, endY
    };
    
    // Dibujar el contorno de la punta de la flecha
    setfillstyle(SOLID_FILL, getcolor()); // Usar el mismo color que la línea
    fillpoly(4, points); // Rellenar el triángulo
}

// 🔹 DIBUJAR FLECHAS BLANCAS ENTRE NODOS ADYACENTES
void Grafo::graficar(int verticeInicial) {
    srand(time(0)); // Inicializar aleatoriedad

    setbkcolor(DARKGRAY);
    cleardevice();

    int x[8], y[8];
    int centroX = 200, centroY = 250; // Mover el centro un poco a la izquierda
    int radio = 150; // Ajusta el radio según el tamaño de la pantalla

    // Generar posiciones distribuidas uniformemente en un círculo
    for (int i = 0; i < 8; ++i) {
        double angulo = (2 * M_PI / 8) * i; // Espaciado uniforme en círculo
        x[i] = centroX + radio * cos(angulo);
        y[i] = centroY + radio * sin(angulo);
    }

    char buffer[10];

    // 🔹 INICIALIZAR BFS
    std::vector<int> parent(8, -1);  // Inicializar Parent en -1
    std::vector<bool> visitado(8, false); // Inicializar tabla "Visitado" como F

    std::queue<NodoGrafo*> cola;
    cola.push(nodos[verticeInicial]);
    visitado[verticeInicial] = true;
    parent[verticeInicial] = verticeInicial; // El nodo inicial es su propio padre

    std::cout << "Inicio BFS desde el nodo: " << verticeInicial << std::endl;

    // 🔹 DIBUJAR LAS FLECHAS BLANCAS ENTRE LOS NODOS
    setcolor(WHITE); // Flechas blancas para las conexiones entre nodos
    for (int i = 0; i < 8; ++i) {
        for (NodoGrafo* adyacente : nodos[i]->adyacentes) {
            // Asegurémonos de dibujar todas las conexiones entre los nodos
            dibujarFlecha(x[i], y[i], x[adyacente->valor], y[adyacente->valor]);
        }
    }

    while (!cola.empty()) {
        NodoGrafo* actual = cola.front();
        cola.pop();

        std::cout << "Nodo explorado: " << actual->valor << std::endl;

        // Marcar como visitado en la tabla
        visitado[actual->valor] = true;

        // Dibujar las flechas de BFS (en azul) desde el nodo actual a sus adyacentes
        for (NodoGrafo* adyacente : actual->adyacentes) {
            if (!visitado[adyacente->valor]) {
                cola.push(adyacente); // Añadir a la cola
                parent[adyacente->valor] = actual->valor; // Registrar el nodo padre

                // Dibujar flecha solo si el nodo adyacente no ha sido visitado
                setcolor(BLUE); // Flechas azules para el recorrido BFS
                dibujarFlecha(x[actual->valor], y[actual->valor], x[adyacente->valor], y[adyacente->valor]);
                std::cout << "   Nodo " << adyacente->valor << " tiene como padre a " << actual->valor << std::endl;
            }
        }
    }

    // 🔹 DIBUJAR NODOS (Reducir el tamaño de los círculos)
    setcolor(BLUE);
    for (int i = 0; i < 8; ++i) {
        setfillstyle(SOLID_FILL, BLUE);
        // Reducir el radio de los círculos para que no ocupen tanto espacio
        fillellipse(x[i], y[i], 15, 15);  // Radio más pequeño
        circle(x[i], y[i], 15);  // Radio más pequeño
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(x[i] - 5, y[i] - 5, buffer);
    }

    // 🔹 ACTUALIZAR TABLAS "Parent" Y "Visited"
    int tableX = 450, tableY = 45; // Mover la tabla hacia la derecha

    outtextxy(tableX, tableY - 20, "Padre");
    for (int i = 0; i < 8; ++i) {
        rectangle(tableX, tableY + i * 30, tableX + 50, tableY + (i + 1) * 30);
        // Mostrar la numeración de los nodos
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 30, tableY + i * 30 + 10, buffer);  // Mover la numeración hacia la izquierda
        if (parent[i] == -1) {
            outtextxy(tableX + 20, tableY + i * 30 + 10, (char*)"-");
        } else {
            snprintf(buffer, sizeof(buffer), "%d", parent[i]);
            outtextxy(tableX + 20, tableY + i * 30 + 10, buffer);
        }
    }

    tableX += 100; // Aumentamos la distancia entre la tabla de Parent y la de Visited

    outtextxy(tableX, tableY - 20, "Visitado");
    for (int i = 0; i < 8; ++i) {
        rectangle(tableX, tableY + i * 30, tableX + 50, tableY + (i + 1) * 30);
        // Mostrar la numeración de los nodos en la tabla
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 30, tableY + i * 30 + 10, buffer);  // Mover la numeración hacia la izquierda
        
        if (visitado[i]) {
            outtextxy(tableX + 20, tableY + i * 30 + 10, (char*)"T");
        } else {
            outtextxy(tableX + 20, tableY + i * 30 + 10, (char*)"F");
        }
    }
}

void dibujarNodo(int x, int y, int valor) {
    rectangle(x, y, x + 50, y + 30);
    char buffer[10];
    snprintf(buffer, sizeof(buffer), "%d", valor);
    outtextxy(x + 20, y + 10, buffer); // Dato
}

void Grafo::graficarListaAdyacencia(int verticeInicial) {
    int startX = 50, startY = 50;
    int boxWidth = 50, boxHeight = 30;
    int offsetX = 70, offsetY = 50;
    char buffer[10];

    // Initialize Parent and Visited arrays
    std::vector<int> parent(nodos.size(), -1);  // -1 means no parent
    std::vector<bool> visited(nodos.size(), false);

    // Perform BFS from the initial vertex
    std::queue<NodoGrafo*> queue;
    queue.push(nodos[verticeInicial]);
    visited[verticeInicial] = true;

    while (!queue.empty()) {
        NodoGrafo* current = queue.front();
        queue.pop();

        for (NodoGrafo* adyacente : current->adyacentes) {
            if (!visited[adyacente->valor]) {
                queue.push(adyacente);
                visited[adyacente->valor] = true;
                parent[adyacente->valor] = current->valor;  // Set parent
            }
        }
    }

    for (int i = 0; i < nodos.size(); ++i) {
        if (nodos[i] == nullptr) continue; // Skip null nodes

        int x = startX;
        int y = startY + i * offsetY;

        // Dibujar índice en azul
        setcolor(BLUE);
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(x - 20, y + 10, buffer);
        setcolor(WHITE);

        // Dibujar nodo principal
        dibujarNodo(x, y, nodos[i]->valor);

        // Dibujar nodos adyacentes
        for (int j = 0; j < nodos[i]->adyacentes.size(); ++j) {
            x += offsetX;
            dibujarNodo(x, y, nodos[i]->adyacentes[j]->valor);
            
            // Dibujar la flecha
            line(x - offsetX + boxWidth, y + boxHeight / 2, x, y + boxHeight / 2);
            line(x, y + boxHeight / 2, x - 5, y + boxHeight / 2 - 5);
            line(x, y + boxHeight / 2, x - 5, y + boxHeight / 2 + 5);
        }
    }

    // Dibujar tablas de Parent y Visited
    int tableX = 400, tableY = 50;
    outtextxy(tableX, tableY - 20, "Padre"); // Use const char*
    for (int i = 0; i < nodos.size(); ++i) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 20, tableY + i * 30 + 10, buffer); // Row labels
        rectangle(tableX, tableY + i * 30, tableX + 50, tableY + (i + 1) * 30);
        snprintf(buffer, sizeof(buffer), "%d", parent[i]);
        outtextxy(tableX + 20, tableY + i * 30 + 10, (parent[i] == -1) ? (char*)"-" : buffer);
    }

    tableX += 100;
    outtextxy(tableX, tableY - 20, "Visited"); // Use const char*
    for (int i = 0; i < nodos.size(); ++i) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 20, tableY + i * 30 + 10, buffer); // Row labels
        rectangle(tableX, tableY + i * 30, tableX + 50, tableY + (i + 1) * 30);
        outtextxy(tableX + 20, tableY + i * 30 + 10, visited[i] ? (char*)"T" : (char*)"f");
    }
}

void Grafo::graficarMatrizAdyacencia(int verticeInicial) {
    int n = nodos.size();
    int startX = 50, startY = 50;
    int cellSize = 30;
    char buffer[10];

    // Draw the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x = startX + j * cellSize;
            int y = startY + i * cellSize;
            rectangle(x, y, x + cellSize, y + cellSize);

            // Check if there is an edge between node i and node j
            bool edgeExists = false;
            for (NodoGrafo* adyacente : nodos[i]->adyacentes) {
                if (adyacente->valor == j) {
                    edgeExists = true;
                    break;
                }
            }

            // Draw 1 if there is an edge, otherwise 0
            snprintf(buffer, sizeof(buffer), "%d", edgeExists ? 1 : 0);
            outtextxy(x + cellSize / 2 - 5, y + cellSize / 2 - 5, buffer);
        }
    }

    // Draw row and column labels
    for (int i = 0; i < n; ++i) {
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(startX - 20, startY + i * cellSize + cellSize / 2 - 5, buffer); // Row labels
        outtextxy(startX + i * cellSize + cellSize / 2 - 5, startY - 20, buffer); // Column labels
    }

    // Initialize Parent and Visited arrays
    std::vector<int> parent(n, -1);  // -1 means no parent
    std::vector<bool> visited(n, false);

    // Perform BFS from the initial vertex
    std::queue<NodoGrafo*> queue;
    queue.push(nodos[verticeInicial]);
    visited[verticeInicial] = true;

    while (!queue.empty()) {
        NodoGrafo* current = queue.front();
        queue.pop();

        for (NodoGrafo* adyacente : current->adyacentes) {
            if (!visited[adyacente->valor]) {
                queue.push(adyacente);
                visited[adyacente->valor] = true;
                parent[adyacente->valor] = current->valor;  // Set parent
            }
        }
    }

    // Draw Parent and Visited tables
    int tableX = startX + n * cellSize + 50;
    int tableY = startY;
    
    // Parent table
    outtextxy(tableX, tableY - 20, "Padre");
    for (int i = 0; i < n; ++i) {
        rectangle(tableX, tableY + i * cellSize, tableX + cellSize, tableY + (i + 1) * cellSize);
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 20, tableY + i * cellSize + cellSize / 2 - 5, buffer); // Row labels
        snprintf(buffer, sizeof(buffer), "%d", parent[i]);
        outtextxy(tableX + cellSize / 2 - 5, tableY + i * cellSize + cellSize / 2 - 5, (parent[i] == -1) ? (char*)"-" : buffer); // Parent values
    }

    tableX += cellSize + 50;

    // Visited table
    outtextxy(tableX, tableY - 20, "Visitado");
    for (int i = 0; i < n; ++i) {
        rectangle(tableX, tableY + i * cellSize, tableX + cellSize, tableY + (i + 1) * cellSize);
        snprintf(buffer, sizeof(buffer), "%d", i);
        outtextxy(tableX - 20, tableY + i * cellSize + cellSize / 2 - 5, buffer); // Row labels
        outtextxy(tableX + cellSize / 2 - 5, tableY + i * cellSize + cellSize / 2 - 5, visited[i] ? (char*)"T" : (char*)"f"); // Visited values
    }
}


